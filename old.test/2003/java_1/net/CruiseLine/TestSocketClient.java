import java.net.*;
import java.io.*;

/**
 * @description	Client of the Test Socket
 * @author	Dansei * Zauj
 * @version	1.1
 */

public class TestSocketClient {
	Socket sock;
	int port = 9001;
	String str = "";

	public TestSocketClient() {
		try {
			sock = new Socket(InetAddress.getLocalHost(), port);
			ObjectInputStream ois = new ObjectInputStream(
				sock.getInputStream());
			str = (String)ois.readObject();
			System.out.println(str);
		} catch (Exception e) {
			System.out.println("Exception: " + e);
		}
	}

	public static void main(String args[]) {
		TestSocketClient tsc = new TestSocketClient();
	}
}
