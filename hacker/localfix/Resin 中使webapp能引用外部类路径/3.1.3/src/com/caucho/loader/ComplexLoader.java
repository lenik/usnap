package com.caucho.loader;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URL;
import java.security.CodeSource;
import java.util.ArrayList;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.annotation.PostConstruct;

import com.caucho.log.Log;
import com.caucho.make.DependencyContainer;
import com.caucho.vfs.Dependency;
import com.caucho.vfs.JarPath;
import com.caucho.vfs.Path;
import com.caucho.vfs.ReadStream;
import com.caucho.vfs.Vfs;

public class ComplexLoader extends Loader implements Dependency {

    private Path                _dir;

    // When the directory was last modified
    @SuppressWarnings("unused")
    private long                _lastModified;

    @SuppressWarnings("unused")
    private String[]            _fileNames;

    private ArrayList<Path>     _dirlist;
    private ArrayList<JarEntry> _jarlist;

    // list of dependencies
    private DependencyContainer _dependencyList = new DependencyContainer();

    public ComplexLoader() {
    }

    public ComplexLoader(Path dir) {
        _dir = dir;
        init();
    }

    /** The directory loader's path. */
    public void setPath(Path path) {
        _dir = path;
    }

    /** The directory loader's path. */
    public Path getPath() {
        return _dir;
    }

    /**
     * Create a new class loader
     *
     * @param parent
     *            parent class loader
     * @param dir
     *            directories which can handle dynamic jar addition
     */
    public static DynamicClassLoader create(ClassLoader parent, Path dir) {
        DynamicClassLoader loader = new DynamicClassLoader(parent);
        ComplexLoader complexLoader = new ComplexLoader(dir);
        loader.addLoader(complexLoader);
        loader.init();
        return loader;
    }

    /** Initialize */
    @PostConstruct
    public void init() {
        _lastModified = _dir.getLastModified();

        try {
            _fileNames = _dir.list();
        } catch (IOException e) {
        }

        _dirlist = new ArrayList<Path>();
        _jarlist = new ArrayList<JarEntry>();
        _dependencyList = new DependencyContainer();

        scan();
    }

    /**
     * True if any of the loaded classes have been modified. If true, the caller
     * should drop the classpath and create a new one.
     */
    @Override
    public boolean isModified() {
        return _dependencyList.isModified();
    }

    /** True if the classes in the directory have changed. */
    @Override
    public boolean logModified(Logger log) {
        if (isModified()) {
            log.info(_dir.getNativePath() + " has modified files");
            return true;
        } else
            return false;
    }

    /** Sets the owning class loader. */
    public void setLoader(DynamicClassLoader loader) {
        super.setLoader(loader);
        for (Path path : _dirlist)
            loader.addURL(path);
        for (JarEntry jar : _jarlist)
            loader.addURL(jar.getJarPath());
    }

    private void scan() {
        clear();
        scan(_dir);
    }

    /** Find all the jars in this directory and add them to jarList. */
    private void scan(Path dir) {
        try {
            for (String file : dir.list()) {
                Path path = dir.lookup(file);
                if (file.endsWith(".jar") || file.endsWith(".zip")) {
                    addJar(path);
                } else if (path.isFile() && path.getLength() < MAX_LINK_SIZE) {
                    parseLink(path);
                } else if (path.isDirectory()) {
                    // scan(path);
                }
            }
        } catch (IOException e) {
        }
    }

    private void addJar(Path path) {
        JarPath jarPath = JarPath.create(path);
        JarEntry jarEntry = new JarEntry(jarPath);
        if (_jarlist.contains(jarEntry))
            return;
        _jarlist.add(jarEntry);
        _dependencyList.add(jarPath.getDepend());
    }

    private void parseLink(Path link) throws IOException {
        ReadStream in = link.openRead();
        String cnt = Files_readLine(in, "utf-8");
        in.close();

        int pos = cnt.indexOf(':');
        Path ref = null;
        Path dir = null;
        if (pos > 0) {
            ref = Vfs.lookup(cnt);
        } else {
            dir = link.getParent();
            ref = dir.lookup(cnt);
        }
        if (ref == null)
            throw new NullPointerException("can't parse link of " + link);
        // if (!ref.exists())
        if (cnt.endsWith(".jar") || cnt.endsWith(".zip"))
            addJar(ref);
        else if (ref.isDirectory())
            addDir(ref);
        else
            throw new RuntimeException("Invalid link target: " + ref
                    + " (link: " + link);
    }

    private void addDir(Path dir) {
        if (_dirlist.contains(dir))
            return;
        _dirlist.add(dir);
        // _dependencyList.add(dependency);
    }

    /**
     * Adds resources to the enumeration.
     */
    public void getResources(Vector<URL> vector, String name) {
        for (Path path : _dirlist)
            _find(path, name, vector);

        for (JarEntry jarEntry : _jarlist) {
            Path path = jarEntry.getJarPath();
            _find(path, name, vector);
        }
    }

    private void _find(Path path, String name, Vector<URL> vector) {
        path = path.lookup(name);

        // server/249i
        if (path.exists()) {
            try {
                URL url = new URL(path.getURL());
                if (!vector.contains(url))
                    vector.add(url);
            } catch (Exception e) {
                log.log(Level.WARNING, e.toString(), e);
            }
        }
    }

    /**
     * Fill data for the class path. fillClassPath() will add all .jar and .zip
     * files in the directory list.
     */
    @Override
    protected void buildClassPath(ArrayList<String> pathList) {
        for (Path dir : _dirlist) {
            String path = dir.getNativePath();
            if (!pathList.contains(path))
                pathList.add(path);
        }

        for (JarEntry jarEntry : _jarlist) {
            JarPath jar = jarEntry.getJarPath();
            String path = jar.getContainer().getNativePath();
            if (!pathList.contains(path))
                pathList.add(path);
        }
    }

    /**
     * Returns the class entry.
     *
     * @param name
     *            name of the class
     */
    @Override
    protected ClassEntry getClassEntry(String name, String pathName)
            throws ClassNotFoundException {
        String pkg = "";
        int p = pathName.lastIndexOf('/');
        if (p > 0)
            pkg = pathName.substring(0, p + 1);

        // Path classPath = null;

        // Find the path corresponding to the class
        Pair<Path, Object> pair = _findPath(pathName);
        if (pair == null)
            return null;
        Path filePath = pair.first;
        if (filePath.getLength() <= 0)
            return null;

        CodeSource codeSource = null;
        ClassPackage classPackage = null;
        if (pair.second != null) {
            JarEntry jarEntry = (JarEntry) pair.second;
            codeSource = jarEntry.getCodeSource(pathName);
            classPackage = jarEntry.getPackage(pkg);
        }
        ClassEntry entry = new ClassEntry(getLoader(), name, filePath,
                filePath, codeSource);
        if (classPackage != null)
            entry.setClassPackage(classPackage);
        return entry;
    }

    /**
     * Find a given path somewhere in the classpath
     *
     * @param pathName
     *            the relative resourceName
     *
     * @return the matching path or null
     */
    public Path getPath(String pathName) {
        Pair<Path, Object> pair = _findPath(pathName);
        if (pair == null)
            return null;
        return pair.first;
    }

    private Pair<Path, Object> _findPath(String pathName) {
        for (Path dir : _dirlist) {
            Path filePath = dir.lookup(pathName);
            if (filePath.canRead())
                return new Pair<Path, Object>(filePath, null);
        }
        for (JarEntry jarEntry : _jarlist) {
            Path path = jarEntry.getJarPath();
            Path filePath = path.lookup(pathName);
            if (filePath.canRead())
                return new Pair<Path, Object>(filePath, jarEntry);
        }
        return null;
    }

    public Path getCodePath() {
        return _dir;
    }

    /** Destroys the loader, closing the jars. */
    protected void destroy() {
        clear();
    }

    /** Closes the jars. */
    private void clear() {
        _dirlist.clear();

        ArrayList<JarEntry> jars = new ArrayList<JarEntry>(_jarlist);
        _jarlist.clear();
        for (int i = 0; i < jars.size(); i++) {
            JarEntry jarEntry = jars.get(i);
            JarPath jarPath = jarEntry.getJarPath();
            jarPath.closeJar();
        }
    }

    public String toString() {
        return "ComplexLoader[" + _dir + "]";
    }

    private static final Logger log           = Log.open(ComplexLoader.class);

    private static final int    MAX_LINK_SIZE = 4096;

    static class Pair<TK, TV> {

        public TK first;
        public TV second;

        public Pair(TK first, TV second) {
            this.first = first;
            this.second = second;
        }

    }

    public static String Files_readLine(InputStream in, String charset)
            throws IOException {
        // InputStream in = url.openStream();
        BufferedReader reader = new BufferedReader(new InputStreamReader(in,
                charset));
        String line = reader.readLine();
        in.close();
        return line;
    }

}
