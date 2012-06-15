
import java.rmi.*;
import java.rmi.server.*;

public class GreeterImpl extends UnicastRemoteObject implements Greeter {
	public GreeterImpl() throws RemoteException {
		super();
	}

	public Object translate(Object obj) {
		Greeting greeting3 = (Greeting)obj;
		if (greeting3.getStr1().equals("Bonjour, Monde")) {
			greeting3.setStr1("Hello, world!");
		} else {
			greeting3.setStr1("Huh?");
		}

		return greeting3;
	}
}
