
import javax.media.*;
import javax.media.format.*;
import javax.media.protocol.*;

import java.awt.*;
import java.awt.event.*;


public class VideoPlayer extends Frame implements ControllerListener, ActionListener {

	Player videoPlayer;

	String filename;

	public VideoPlayer(String s1) {
		super(s1);

		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e) {
				dispose();
				System.exit(0);
			}
		});

		MenuBar mb = new MenuBar();
		setMenuBar(mb);

		Menu fileMenu = new Menu("File");
		mb.add(fileMenu);

		MenuItem itemPlay = new MenuItem("Play");
		itemPlay.addActionListener(this);
		fileMenu.add(itemPlay);
	}

	public void actionPerformed(ActionEvent e) {
		String action = e.getActionCommand().toString();

		if (action.equals("Play")) {
			play();
		}
	}

	void play() {
		try {
			FileDialog dlg = new FileDialog(this,
				"Choose video file", FileDialog.LOAD);
			dlg.show();

			filename = dlg.getDirectory() + dlg.getFile();

			videoPlayer = Manager.createPlayer(
				new MediaLocator("file:///" + filename));


			System.out.println("Adding controller listener");

			videoPlayer.addControllerListener(this);
			videoPlayer.start();

		} catch (Exception e) {
			System.out.println("Error " + e);
		}
	}

	public synchronized void controllerUpdate(ControllerEvent event) {
		System.out.println("Event: " + event);

		if (event instanceof RealizeCompleteEvent) {
			Component comp;

			comp = videoPlayer.getVisualComponent();
			if (comp != null) {
				add("Center", comp);
			} else {
				System.out.println("Unable to get visual component");
			}

			validate();
		}
	}

	public static void main(String[] args) {
		VideoPlayer vp = new VideoPlayer("Minimal Video Player");

		vp.setSize(300, 300);
		vp.setLocation(250, 300);

		vp.show();
	}
}
