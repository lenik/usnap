
import java.rmi.RemoteException;
import javax.ejb.EJBObject;

public interface HelloWorld extends EJBObject {
	public String sayIt() throws RemoteException;
}
