
import java.rmi.*;

public interface Finder extends Remote {
	Object addCreditCardNumber(Object obj) throws RemoteException;
}
