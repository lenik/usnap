
import java.sql.*;
import java.util.*;


public class MySQLJDBC2 {

	public static void main(String argv[]) throws Exception {
		Connection dbConn = null;
		Statement stmt = null;
		String sCreate;
		String sInert;

		try {
			Class.forName("org.gjt.mm.mysql.Driver");

			String sourceURL = "jdbc:mysql://localhost:3306/CruiseTicket";

			dbConn = DriverManager.getConnection(sourceURL, "root", "");

			System.out.println("The database connection is " + dbConn);
			System.out.println("Making connection...\n");

			stmt = dbConn.createStatement();

			try {
				stmt.execute("DROP TABLE CruiseReservation");
				stmt.execute("DROP TABLE CruiseCustomer");
				stmt.execute("DROP TABLE CruiseTicket");
				stmt.execute("DROP TABLE TravelAgency");
				stmt.execute("DROP TABLE CruiseBooking");
				stmt.execute("DROP TABLE Cruises");
				System.out.println("all tables dropped.");
			} catch (SQLException e) {
				System.out.println("table doesn't need to be dropped.");
			}

			sCreate = "CREATE TABLE CruiseReservation(resID int PRIMARY KEY, CustomerID int, CruiseLine VARCHAR(30), Ship VARCHAR(30), Port VARCHAR(30), Sailing VARCHAR(30), AgencyID int, AgentName VARCHAR(30))";
			stmt.executeUpdate(sCreate);
			System.out.println("T - CruiseReservation");

			sCreate = "CREATE TABLE CruiseCustomer(CustomerID int PRIMARY KEY, LastName VARCHAR(30), FirstName VARCHAR(30), MI VARCHAR(30), Address1 VARCHAR(30), Address2 VARCHAR(30), City VARCHAR(30), StateProv VARCHAR(30), PostalCode VARCHAR(30), Country VARCHAR(30), CreditCardType VARCHAR(30), CreditCardNumber VARCHAR(30), isGambler BIT, isDrinker BIT, isShortTourist BIT, isPitchable BIT)";
			stmt.executeUpdate(sCreate);
			System.out.println("T - CruiseCustomer");

			sCreate = "CREATE TABLE TravelAgency(AgencyID int PRIMARY KEY, AgencyName VARCHAR(30), Address1 VARCHAR(30), Address2 VARCHAR(30), City VARCHAR(30), StateProv VARCHAR(30), PostalCode VARCHAR(30), Coutnry VARCHAR(30), Telephone VARCHAR(30))";
			stmt.executeUpdate(sCreate);
			System.out.println("T - TravelAgency");

			sCreate = "CREATE TABLE CruiseTicket(TicketID int PRIMARY KEY, CustomerID int, Cruiseline VARCHAR(30), Ship VARCHAR(30), Port VARCHAR(30), Sailing VARCHAR(30), Price FLOAT, AgencyID int, BookingID int, AgentName VARCHAR(30))";
			stmt.executeUpdate(sCreate);
			System.out.println("T - CruiseTicket");

			sCreate = "CREATE TABLE CruiseBooking(BookingID int PRIMARY KEY, TicketID int, CustomerID int, Somking BIT, DiningPreference VARCHAR(30), LangPref VARCHAR(30))";
			stmt.executeUpdate(sCreate);
			System.out.println("T - CruiseBooking");

			sCreate = "CREATE TABLE Cruises(CruiseID int PRIMARY KEY, Destination VARCHAR(30), Port VARCHAR(30), Sailing VARCHAR(30))";
			stmt.executeUpdate(sCreate);
			System.out.println("T - Cruises");


			stmt.addBatch("INSERT INTO Cruises VALUES(3001, 'Tahiti', 'Aucklang', '1/15/02')");
			stmt.addBatch("INSERT INTO Cruises VALUES(3002, 'Caribbean', 'Tmpa', '2/15/02')");
			stmt.addBatch("INSERT INTO Cruises VALUES(3003, 'Hawaii', 'Honolulu', '3/15/02')");
			stmt.addBatch("INSERT INTO Cruises VALUES(3004, 'Alaska', 'Vancouver', '4/15/02')");
			stmt.addBatch("INSERT INTO Cruises VALUES(3005, 'Bermuda', 'Fort Lauderdale', '5/15/02')");
			stmt.addBatch("INSERT INTO Cruises VALUES(3006, 'Greek Isles', 'Venice', '6/15/02')");
			stmt.addBatch("INSERT INTO Cruises VALUES(3007, 'Bahamas', 'Port Canaveral', '7/15/02')");
			stmt.addBatch("INSERT INTO Cruises VALUES(3008, 'Mexico', 'Mobile', '8/15/02')");
			stmt.addBatch("INSERT INTO Cruises VALUES(3009, 'South America', 'San Juan', '9/15/02')");
			stmt.addBatch("INSERT INTO Cruises VALUES(3010, 'Indonesia', 'Perth', '10/15/02')");
			stmt.executeBatch();
			System.out.println("Data - Cruises");

			stmt.addBatch("INSERT INTO CruiseCustomer VALUES(1001, 'Carter', 'Joseph', 'D', '123 4th St.', '', 'Kennesaw',      'GA', '10064', 'USA', 'MC', '1234-1234-1234-1234', 0, 0, 0, 0)");
			stmt.addBatch("INSERT INTO CruiseCustomer VALUES(1002, 'Cain', 'Clay', 'F', '1203 5th St.', '', 'Macon',            'GA', '20064', 'USA', 'MC', '2234-2234-2234-2234', 0, 0, 0, 0)");
			stmt.addBatch("INSERT INTO CruiseCustomer VALUES(1003, 'Bush', 'Albert', 'R', '1523 6th St.', '', 'Cincinnati',     'OH', '30064', 'USA', 'MC', '3234-3234-3234-3234', 0, 0, 0, 0)");
			stmt.addBatch("INSERT INTO CruiseCustomer VALUES(1004, 'Skelton', 'Allison', 'T', '1523 7th St.', '', 'Middletown', 'AL', '40064', 'USA', 'MC', '4234-4234-4234-4234', 0, 0, 0, 0)");
			stmt.addBatch("INSERT INTO CruiseCustomer VALUES(1005, 'Davidson', 'Barco', 'G', '1823 8th St.', '', 'Dayton',      'OH', '50064', 'USA', 'MC', '5234-5234-5234-5234', 0, 0, 0, 0)");
			stmt.addBatch("INSERT INTO CruiseCustomer VALUES(1006, 'Rangitch', 'Maureen', 'B', '1223 9th St.', '', 'Cairo',     'KA', '60064', 'USA', 'MC', '6234-6234-6234-6234', 0, 0, 0, 0)");
			stmt.addBatch("INSERT INTO CruiseCustomer VALUES(1007, 'Milner', 'Grant', 'V', '1293 14th St.', '', 'Auberna',      'TN', '70064', 'USA', 'MC', '7234-7234-7234-7234', 0, 0, 0, 0)");
			stmt.addBatch("INSERT INTO CruiseCustomer VALUES(1008, 'Walker', 'Mike', 'C', '1223 24th St.', '', 'Spokane',       'WA', '80064', 'USA', 'MC', '8234-8234-8234-8234', 0, 0, 0, 0)");
			stmt.addBatch("INSERT INTO CruiseCustomer VALUES(1009, 'Cheney', 'Michael', 'L', '1723 25th St.', '', 'Orlando',    'FL', '90064', 'USA', 'MC', 'A234-8234-8234-8234', 0, 0, 0, 0)");
			stmt.addBatch("INSERT INTO CruiseCustomer VALUES(1010, 'Pfister', 'Darlene', 'D', '1233 9th St.', '', 'Bangor',     'MA', '10064', 'USA', 'MC', 'B234-8234-8234-8234', 0, 0, 0, 0)");
			stmt.executeBatch();
			System.out.println("Data - CruiseCustomer");

			stmt.addBatch("INSERT INTO TravelAgency VALUES(2001, 'CruiseJunction', '1233 Sego St.', '', 'Miami',            'FL', '10064', 'USA', '(800)242-4242')");
			stmt.addBatch("INSERT INTO TravelAgency VALUES(2002, 'Cruise and Snooze', '9387 Atlantic Ave.', '', 'New York', 'NY', '00064', 'USA', '(800)343-3434')");
			stmt.addBatch("INSERT INTO TravelAgency VALUES(2003, 'Pokeys Cruises', '98223 Baltic Dr.', '', 'Los Angeles',   'CA', '20064', 'USA', '(800)565-5656')");
			stmt.addBatch("INSERT INTO TravelAgency VALUES(2004, 'Cruise Animal', '2345 Lester Rd.', '', 'New Orleans',     'LA', '40064', 'USA', '(800)787-8787')");
			stmt.addBatch("INSERT INTO TravelAgency VALUES(2005, 'Cruisy Dot Com', '5435 Spring St.', '', 'Atlanta',        'GA', '30064', 'USA', '(800)879-6543')");
			stmt.executeBatch();
			System.out.println("Data - TravelAgency");

			System.out.println("All rows added successfully");
		} catch (Exception e) {
			System.out.println("Exception: " + e);
		} finally {
			try {
				if (stmt != null) stmt.close();
				if (dbConn != null) dbConn.close();
			} catch (SQLException sqle) {
				System.out.println("SQLException: " + sqle.getMessage());
			}
		}
	}
}
