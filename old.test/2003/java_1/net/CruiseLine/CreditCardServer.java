

import java.rmi.Naming;

public class CreditCardServer {
	public static void main(String[] args) {
		try {
			System.out.print("Start server...");

			Finder f = new CreditCardImpl();
			Naming.rebind("rmi://localhost:1099/FinderService", f);

			System.out.println(" started");

		} catch (Exception e) {
			System.out.println("Exception: " + e);
		}
	}
}
