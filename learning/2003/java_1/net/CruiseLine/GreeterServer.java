
import java.rmi.Naming;

public class GreeterServer {
	public GreeterServer() {
		try {
			Greeter g = new GreeterImpl();

			Naming.rebind("rmi://localhost:1099/GreeterService", g);
		} catch (Exception e) {
			System.out.println("Exception: " + e);
		}
	}

	public static void main(String[] args) {
		GreeterServer gs = new GreeterServer();
	}
}
