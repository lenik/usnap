
import java.util.*;

public class TicketRequest2 implements java.io.Serializable {
	int custID;
	String lastName;
	String firstName;

	int cruiseID;
	String destination;
	String port;
	String sailing;

	int numberOfTickets;
	boolean commissionable;
	boolean approved;

	public TicketRequest2() {}

	public TicketRequest2(int custID, String lastName, String firstName, int cruiseID, String destination, String port, String sailing, int numberOfTickets, boolean isCommissionable) {
		this.custID = custID;
		this.lastName = lastName;
		this.firstName = firstName;
		this.cruiseID = cruiseID;
		this.destination = destination;
		this.port = port;
		this.sailing = sailing;
		this.numberOfTickets = numberOfTickets;
		this.commissionable = isCommissionable;
		this.approved = false;
	}

	public int getCustID() { return custID; }
	public String getLastName() { return lastName; }
	public String getFirstName() { return firstName; }
	public int getCruiseID() { return cruiseID; }
	public String getDestination() { return destination; }
	public String getPort() { return port; }
	public String getSailing() { return sailing; }
	public int getNumberOfTickets() { return numberOfTickets; }
	public boolean isCommissionable() { return commissionable; }
	public boolean isApproved() { return approved; }
	public void setCustID(int custID) { this.custID = custID; }
	public void setLastName(String lastName) { this.lastName = lastName; }
	public void setFirstName(String firstName) { this.firstName = firstName; }
	public void setCruiseID(int cruiseID) { this.cruiseID = cruiseID; }
	public void setDestination(String destination) { this.destination = destination; }
	public void setPort(String port) { this.port = port; }
	public void setSailing(String sailing) { this.sailing = sailing; }
	public void setNumberOfTickets(int numberOfTickets) { this.numberOfTickets = numberOfTickets; }
	public void setCommissionable(boolean commissionable) { this.commissionable = commissionable; }
	public void approved() { approved = true; }
	public void disApprove() { approved = false; }
	public String toString() {
		String s;
		s = "custID = " + custID + "\n"
			+ "lastName = " + lastName + "\n"
			+ "firstName = " + firstName + "\n"
			+ "cruiseID = " + cruiseID + "\n"
			+ "destination = " + destination + "\n"
			+ "port = " + port + "\n"
			+ "sailing = " + sailing + "\n"
			+ "numberOfTickets = " + numberOfTickets + "\n"
			+ "commissionable = " + commissionable + "\n"
			+ "approved? = " + approved + "\n"
			;

		return s;
	}
}
