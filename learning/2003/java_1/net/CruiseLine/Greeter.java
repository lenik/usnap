
import java.rmi.*;

public interface Greeter extends Remote {
	Object translate(Object obj) throws RemoteException;
}
