
import java.io.*;

public class Customer implements Serializable {
	int custID;
	String creditCardNumber;

	public Customer() {}
	public Customer(int _custID) { custID = _custID; }
	public int getCustID() { return custID; }
	public void setCustID(int _custID) { custID = _custID; }
	public String getCreditCardNumber() { return creditCardNumber; }
	public void setCreditCardNumber(String _ccn) {
		creditCardNumber = _ccn;
	}
}
