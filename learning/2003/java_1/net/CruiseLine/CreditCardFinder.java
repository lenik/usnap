
import java.io.*;
import java.util.*;
import javax.transaction.*;
import javax.naming.*;

import java.sql.*;
import javax.mail.*;
import javax.mail.internet.*;


public class CreditCardFinder {

	// JDBC Variables
	Connection dbConn = null;
	Statement statement1 = null;

	public CreditCardFinder() throws Exception {
		init();
	}

	private void init() throws Exception {
		try {
			ConnectToServices();
		} catch (Exception e) {
			System.out.println("Exception thrown " + e);
		}
	}

	private void ConnectToServices() {
		try {
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			String sourceURL = "jdbc:odbc:CruiseTicket";

			dbConn = DriverManager.getConnection(sourceURL);

			System.out.println("The database connection is " + dbConn);
			System.out.println("Making connection...\n");

			statement1 = dbConn.createStatement();
		} catch (Exception e) {
			System.out.println("db exception: " + e);
		}
	}

	private void addCreditCardNumber(Customer cust) throws Exception {
		int CustID = cust.getCustID();

		String ccNum = "";
		String getCCString = "SELECT CreditCardNumber FROM CruiseCustomer WHERE CustomerID = " + Integer.toString(CustID);

		ResultSet ccResults = statement1.executeQuery(getCCString);

		while (ccResults.next()) {
			ccNum = ccResults.getString("CreditCardNumber");
		}

		cust.setCreditCardNumber(ccNum);
	}

	private static void log(String s) {
		System.out.println(s);
	}

	public static void main(String[] args) {
		try {
			CreditCardFinder ccf = new CreditCardFinder();
			Customer cust1 = new Customer(1001);
			ccf.addCreditCardNumber(cust1);

			System.out.println("The credit card number for " + cust1.getCustID()
				+ " = " + cust1.getCreditCardNumber());
		} catch (Exception e) {
			System.out.println("main/exception: " + e);
		}
	}
}
