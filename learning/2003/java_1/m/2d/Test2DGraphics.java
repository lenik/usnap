
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.awt.font.*;
import javax.swing.*;

public class Test2DGraphics extends Canvas {

	public Test2DGraphics() {
		setBackground(Color.white);
	}

	public void paint(Graphics g) {
		Graphics2D g2;
		g2 = (Graphics2D)g;

		g2.setColor(Color.red);
		g2.drawRect(100, 100, 60, 40);

		g2.setColor(Color.blue);
		g2.drawOval(100, 100, 60, 40);

		GeneralPath path1 = new GeneralPath(GeneralPath.WIND_EVEN_ODD);
		path1.moveTo(0, 0);
		path1.lineTo(0, 500);
		path1.lineTo(50, 100);
		path1.lineTo(75, 50);
		path1.lineTo(75, 0);
		path1.closePath();
		g2.setColor(Color.green);
		g2.fill(path1);

		GeneralPath path2 = new GeneralPath(GeneralPath.WIND_EVEN_ODD);
		path2.moveTo(0, 0);
		path2.lineTo(100, 300);
		path2.lineTo(30, 30);
		path2.closePath();
		g2.setColor(Color.gray);
		g2.fill(path2);

		AffineTransform aTran = new AffineTransform();
		aTran.setToRotation(-Math.PI / 10.0);
		g2.transform(aTran);
		aTran.setToTranslation(10, 250);
		g2.transform(aTran);
		g2.setColor(Color.red);
		g2.fill(path2);

		aTran.setToRotation(-Math.PI/5.0);
		g2.transform(aTran);
		aTran.setToTranslation(10, 10);
		g2.transform(aTran);
		g2.setColor(Color.red);
		g2.fill(path2);

		aTran.setToRotation(-Math.PI / 3.0);
		g2.transform(aTran);
		aTran.setToTranslation(10, 10);
		g2.transform(aTran);
		g2.setColor(Color.red);
		g2.fill(path2);
	}

	public static void main(String args[]) {
		JFrame f = new JFrame("2D Graphics");
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		f.getContentPane().add("Center", new Test2DGraphics());

		f.pack();
		f.setSize(new Dimension(500, 500));
		f.show();
	}

}
