

import java.io.*;
import java.util.*;
import javax.transaction.*;
import javax.naming.*;
import javax.jms.*;


public class GetDefaultID {

	public static void main(String[] args) {

		try {
			Hashtable ht = new Hashtable();
			ht.put(Context.INITIAL_CONTEXT_FACTORY,
				"weblogic.jndi.WLInitialContextFactory");
			ht.put(Context.PROVIDER_URL,
				"t3://80.32.48.2:7001");

			System.out.println("Locate for default...");
			InitialContext ic = new InitialContext(ht);
			System.out.println("initial: " + ic);

			String ctxName = ic.getNameInNamespace();
			System.out.println("The initial context's name is: " + ctxName);

			NamingEnumeration ne = ic.list(ctxName);
			System.out.println("enumeration: " + ne);

			if (ne.hasMore()) {
				while (ne.hasMore())
					System.out.println("element - " + ne.next());
			} else {
				System.out.println("empty.");
			}

		} catch (NamingException e) {
			System.out.println("Nameing exception: " + e);
		}
	}

}
