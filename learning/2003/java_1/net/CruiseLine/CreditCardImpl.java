
import java.rmi.*;
import java.rmi.server.*;
import java.sql.*;

public class CreditCardImpl extends UnicastRemoteObject implements Finder {
	Connection conn = null;
	Statement stmt = null;

	public CreditCardImpl() throws RemoteException, Exception {
		super();
		init();
	}

	private void init() throws Exception {
		try {
			ConnectToServices();
		} catch (Exception e) {
			System.out.println("Exception: " + e);
		}
	}

	private void ConnectToServices() {
		try {
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			conn = DriverManager.getConnection("jdbc:odbc:CruiseTicket");
			stmt = conn.createStatement();
		} catch (Exception e) {
			System.out.println("Exception: " + e);
		}
	}

	public Object addCreditCardNumber(Object obj) throws RemoteException {
		try {
			Customer cust = (Customer)obj;
			int custID = cust.getCustID();

			String ccNum = "";
			ResultSet rs = stmt.executeQuery("SELECT CreditCardNumber FROM CruiseCustomer WHERE CustomerID = " + Integer.toString(custID));
			while (rs.next()) {
				ccNum = rs.getString("CreditCardNumber");
			}

			cust.setCreditCardNumber(ccNum);
			return cust;
		} catch (Exception e) {
			System.out.println("Exception: " + e);
			return null;
		}
	}
}
