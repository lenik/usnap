
import java.rmi.*;
import javax.ejb.*;

public interface HelloWorldHome extends EJBHome {
	public HelloWorld create() throws CreateException, RemoteException;
}
