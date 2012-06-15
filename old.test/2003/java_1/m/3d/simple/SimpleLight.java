
import java.awt.*;
import java.awt.event.*;
import javax.media.j3d.*;
import javax.vecmath.*;
import com.sun.j3d.utils.geometry.Box;
import com.sun.j3d.utils.geometry.Sphere;
import com.sun.j3d.utils.geometry.ColorCube;
import com.sun.j3d.utils.universe.SimpleUniverse;

public class SimpleLight extends Frame {

	public SimpleLight() {
		super("SimpleLight");
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
		rotateY.rotY(Math.PI/1.0);
		rotateX.mul(rotateY);

		TransformGroup tGroupRotate = new TransformGroup(rotateX);

		TransformGroup tGroupSpin = new TransformGroup();
		tGroupSpin.setCapability(TransformGroup.ALLOW_TRANSFORM_WRITE);

		root.addChild(tGroupRotate);
		tGroupRotate.addChild(tGroupSpin);

		// add light
		addLighting(root);

		Appearance mat = new Appearance();
		Color3f darkRed = new Color3f(09f, 0.2f, 0.1f);
		Color3f black = new Color3f(0.0f, 0.0f, 0.0f);
		mat.setMaterial(new Material(darkRed, black, darkRed, black, 10.0f));


		//tGroupSpin.addChild(new ColorCube(0.3));
		tGroupSpin.addChild(new Box(0.3f, 0.3f, 0.3f, mat));


		Transform3D t3d = new Transform3D();
		Alpha rotateAlpha = new Alpha(-1, 8000);

		RotationInterpolator rint = new RotationInterpolator(
			rotateAlpha, tGroupSpin, t3d, 0.0f, (float)Math.PI * 2.0f);

		BoundingSphere bSphere = new BoundingSphere();
		rint.setSchedulingBounds(bSphere);
		tGroupSpin.addChild(rint);

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
		final SimpleLight m3d = new SimpleLight();
		m3d.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				m3d.dispose();
				System.exit(0);
			}
		});
	}
}
