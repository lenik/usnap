
import javax.ejb.*;
import javax.naming.InitialContext;
import javax.naming.NamingException;

public class HelloWorldBean implements SessionBean {
	// SessionBean interface
	public void ejbActivate() {}
	public void ejbRemove() {}
	public void ejbPassivate() {}
	public void setSessionContext(SessionContext ctx) {}
	public void ejbCreate() throws CreateException {}

	//
	public String sayIt() {
		System.out.println("Hello world EJB is called");
		return "[Hello World is said.]";
	}
}
