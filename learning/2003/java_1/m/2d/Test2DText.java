
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.awt.font.*;
import javax.swing.*;

public class Test2DText extends Canvas {
	public Test2DText() {
		setBackground(Color.white);
	}

	public void paint(Graphics _g) {
		Graphics2D g;
		g = (Graphics2D)_g;

		FontRenderContext frc = g.getFontRenderContext();
		Font font1 = new Font("Courier", Font.BOLD, 24);
		String str1 = new String("Java Unleashed");
		TextLayout t1 = new TextLayout(str1, font1, frc);
		Dimension dim1 = getSize();
		g.setColor(Color.gray);
		t1.draw(g, 70, 150);
	}

	public static void main(String[] args) {
		JFrame frame1 = new JFrame("2D Text");
		frame1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		frame1.getContentPane().add("Center", new Test2DText());
		frame1.pack();
		frame1.setSize(new Dimension(500, 300));
		frame1.show();
	}
}