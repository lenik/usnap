
import java.awt.*;
import java.awt.event.*;
import javax.media.j3d.*;
import com.sun.j3d.utils.geometry.Sphere;
import com.sun.j3d.utils.geometry.ColorCube;
import com.sun.j3d.utils.universe.SimpleUniverse;

public class Minimal3D extends Frame {

	public Minimal3D() {
		super("Minimal3D");
		setSize(400, 300);
		setLayout(new BorderLayout());
		GraphicsConfiguration config = SimpleUniverse.getPreferredConfiguration();
		Canvas3D c3 = new Canvas3D(config);

		add("Center", c3);
		setVisible(true);

		BranchGroup sGraph = createSceneGraph();
		sGraph.compile();

		SimpleUniverse su = new SimpleUniverse(c3);
		su.getViewingPlatform().setNominalViewingTransform();

		su.addBranchGraph(sGraph);

	}

	public BranchGroup createSceneGraph() {
		BranchGroup root = new BranchGroup();
		Transform3D rotateX = new Transform3D();
		rotateX.rotX(Math.PI/10.0);
		Transform3D rotateY = new Transform3D();
		rotateY.rotY(Math.PI/5.0);
		rotateX.mul(rotateY);

		TransformGroup tGroup = new TransformGroup(rotateX);
		tGroup.addChild(new ColorCube(0.3));
		root.addChild(tGroup);

		return root;
	}

	public static void main(String[] args) {
		final Minimal3D m3d = new Minimal3D();
		m3d.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				m3d.dispose();
				System.exit(0);
			}
		});
	}
}
