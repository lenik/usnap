
import java.rmi.RemoteException;
import java.util.Properties;
import javax.ejb.CreateException;
import javax.ejb.RemoveException;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.rmi.PortableRemoteObject;


public class SimpleEJBClient {
	private static final String JNDI_NAME = "HelloWorld";

	public static void main(String[] args) throws Exception {
		try {
			Properties h = new Properties();

			h.put(Context.INITIAL_CONTEXT_FACTORY, "weblogic.jndi.WLInitialContextFactory");
			h.put(Context.PROVIDER_URL, "t3://localhost:7001");

			InitialContext ctx = new InitialContext(h);

			Object obj = ctx.lookup(JNDI_NAME);
			HelloWorldHome home = (HelloWorldHome)PortableRemoteObject.narrow(obj, HelloWorldHome.class);

			Object ejbObj = home.create();
			HelloWorld simpleEJB = (HelloWorld)PortableRemoteObject.narrow(ejbObj, HelloWorld.class);

			System.out.println("Calling simple EJB: " + simpleEJB.sayIt());
		} catch (Exception e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
	}
}
