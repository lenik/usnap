
import java.awt.*;
import java.awt.event.*;
import javax.media.j3d.*;
import com.sun.j3d.utils.geometry.Sphere;
import com.sun.j3d.utils.geometry.ColorCube;
import com.sun.j3d.utils.universe.SimpleUniverse;

public class SimpleAnim extends Frame {

	public SimpleAnim() {
		super("SimpleAnim");
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

		tGroupSpin.addChild(new ColorCube(0.3));

		Transform3D t3d = new Transform3D();
		Alpha rotateAlpha = new Alpha(-1, 8000);

		RotationInterpolator rint = new RotationInterpolator(
			rotateAlpha, tGroupSpin, t3d, 0.0f, (float)Math.PI * 2.0f);

		BoundingSphere bSphere = new BoundingSphere();
		rint.setSchedulingBounds(bSphere);
		tGroupSpin.addChild(rint);

		return root;
	}

	public static void main(String[] args) {
		final SimpleAnim m3d = new SimpleAnim();
		m3d.addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				m3d.dispose();
				System.exit(0);
			}
		});
	}
}
