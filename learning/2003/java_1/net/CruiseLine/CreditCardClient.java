

import java.io.*;
import java.rmi.*;
import java.util.*;
import javax.rmi.*;


public class CreditCardClient {
	public CreditCardClient() {}

	public static void main(String[] args) throws Exception {
		try {
			Finder finder =
				(Finder)Naming.lookup("rmi://localhost:1099/FinderService");

			Customer cust1 = new Customer(1001);

			Object obj2 = finder.addCreditCardNumber(cust1);
			Customer cust2 = (Customer)obj2;

			System.out.println("obj2 = " + obj2);

			System.out.println("The credit card number for " + cust2.getCustID()
				+ " is " + cust2.getCreditCardNumber());

		} catch (Exception e) {
			System.out.println("Exception: " + e);
		}
	}
}
