
import java.io.IOException;
import java.rmi.*;
import java.util.*;
import javax.rmi.*;


/**
 * @author Stephen Potts

 * @version 1.4
 */

public class GreetingClient {
	/** Creates new GreetingClient */
	public GreetingClient() {}

	public static void main(String[] args) throws Exception {
		try {
			Greeter greeter = (Greeter)Naming.lookup("rmi://localhost:1099/GreeterService");
				Greeting greeting1 = new Greeting("Bonjour, Monde");

				Object obj2 = greeter.translate(greeting1);
				System.out.println("Object obj2 = " + obj2);

				Greeting greeting2 = (Greeting)obj2;
				System.out.println("The original is " + greeting1.getStr1());
				System.out.println("The translation is " + greeting2.getStr1());
		} catch (Exception e) {
			System.out.println("Exception " + e);
		}
	}
}
