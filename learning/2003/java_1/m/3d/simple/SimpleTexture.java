
import java.awt.*;
import java.awt.event.*;
import javax.media.j3d.*;
import javax.vecmath.*;
import com.sun.j3d.utils.geometry.*;
import com.sun.j3d.utils.universe.*;
import com.sun.j3d.utils.image.TextureLoader;

public class SimpleTexture extends Frame {

	public SimpleTexture() {
		super("SimpleTexture");
		setSize(400, 300);
		setLayout(new BorderLayout());
		GraphicsConfiguration config = SimpleUniverse.getPreferredConfiguration();
		Canvas3D c3 = new Canvas3D(config);

		add("Center", c3);
		setVisible(true);

		c3.setStereoEnable(false);

		SimpleUniverse su = new SimpleUniverse(c3);
		su.getViewingPlatform().setNominalViewingTransform();

		su.addBranchGraph(createSceneGraph());

	}


	public BranchGroup createSceneGraph() {
		BranchGroup root = new BranchGroup();

		Transform3D transform = new Transform3D();

		QuadArray plane = new QuadArray(4,
			GeometryArray.COORDINATES | GeometryArray.TEXTURE_COORDINATE_2);

		Point3f p = new Point3f(-1.0f, 1.0f, 0.0f);

		plane.setCoordinate(0, p);
		p.set(-1.0f, -1.0f, 0.0f);
		plane.setCoordinate(1, p);
		p.set(1.0f, -1.0f, 0.0f);
		plane.setCoordinate(2, p);
		p.set(1.0f, 1.0f, 0.0f);
		plane.setCoordinate(3, p);

		Point2f q = new Point2f(0.0f, 1.0f);
		plane.setTextureCoordinate(0, q);
		q.set(0.0f, 0.0f);
		plane.setTextureCoordinate(1, q);
		q.set(1.0f, 0.0f);
		plane.setTextureCoordinate(2, q);
		q.set(1.0f, 1.0f);
		plane.setTextureCoordinate(3, q);

		Appearance appear = new Appearance();
		String filename = "yasa.gif";
		TextureLoader loader = new TextureLoader(filename, this);
		ImageComponent2D image = loader.getImage();

		if (image == null) {
			System.out.println("load failed: " + filename);
		}

		Texture2D texture = new Texture2D(Texture.BASE_LEVEL, Texture.RGBA,
			image.getWidth(), image.getHeight());
		texture.setImage(0, image);

		appear.setTexture(texture);

		appear.setTransparencyAttributes(
			new TransparencyAttributes(TransparencyAttributes.FASTEST, 0.1f)
			);

		Shape3D planeObj = new Shape3D(plane, appear);

		Transform3D rotate = new Transform3D();
		Transform3D tempRotate = new Transform3D();

		rotate.rotX(Math.PI / 4.0d);
		tempRotate.rotY(Math.PI / 5.0d);

		rotate.mul(tempRotate);

		TransformGroup objRotate = new TransformGroup(rotate);
		TransformGroup objSpin = new TransformGroup();
		objSpin.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);

		root.addChild(objRotate);
		objRotate.addChild(objSpin);
		objSpin.addChild(planeObj);

		Transform3D yAxis = new Transform3D();
		Alpha rotationAlpha = new Alpha(-1, 6000);

		RotationInterpolator rotator =
			new RotationInterpolator(rotationAlpha, objSpin, yAxis, 0.0f, (float)Math.PI * 2.0f);

		BoundingSphere bounds = new BoundingSphere();
		rotator.setSchedulingBounds(bounds);
		objSpin.addChild(rotator);

		Background back = new Background();
		back.setColor(1.0f, 1.0f, 1.0f);
		back.setApplicationBounds(new BoundingSphere());
		root.addChild(back);

		return root;
	}

	public void addLighting(BranchGroup root) {
		// main light

		BoundingSphere bSphere = new BoundingSphere(
			new Point3d(0.0, 0.0, 0.0), 100.0);
		Color3f directLightColor = new Color3f(1.0f, 1.0f, 1.0f);

		Vector3f lightDirection = new Vector3f(1.0f, 0.0f, 0.0f);

		DirectionalLight dl = new DirectionalLight(
			directLightColor,
			lightDirection
			);
		dl.setInfluencingBounds(bSphere);

		root.addChild(dl);


		// ambient light
		Color3f ambientLightColor = new Color3f(0.05f, 0.05f, 0.05f);
		AmbientLight al = new AmbientLight(ambientLightColor);
		al.setInfluencingBounds(bSphere);

		root.addChild(al);
	}


	public static void main(String[] args) {
		final SimpleTexture m3d = new SimpleTexture();
		m3d.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				m3d.dispose();
				System.exit(0);
			}
		});
	}
}
