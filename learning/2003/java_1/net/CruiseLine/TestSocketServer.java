
import java.net.*;
import java.io.*;

/**
 * @author	Danci.Z
 * @version	1.0
 */
public class TestSocketServer {
	ServerSocket s;
	int port = 9001;
	Socket c;
	String str;

	/**
	 * @name	Constructor
	 * @author	Zauj.G.D.
	 */
	TestSocketServer() {
		try {
			s = new ServerSocket(port);
			c = s.accept();

			ObjectOutputStream oos;
			oos = new ObjectOutputStream(c.getOutputStream());

			oos.writeObject("Hello!");

			oos.close();
			s.close();
		} catch (Exception e) {
			System.out.println("Exception " + e);
		}
	}

	public static void main(String args[]) {
		TestSocketServer tss = new TestSocketServer();
	}
}
