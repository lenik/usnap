
import java.io.*;

public class HelloClient {
	private native void ShowMessage(String msg);

	static {
		System.loadLibrary("HelloServer");

		// linux: "/home/.../HelloServer.so"
	}

	public static void main(String args[]) {
		HelloClient app = new HelloClient();
		app.ShowMessage("[ Client String ]");
	}
}
