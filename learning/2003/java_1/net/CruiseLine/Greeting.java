
import java.io.*;


public class Greeting implements Serializable {
	String str1;

	public Greeting() {}

	public Greeting(String _str1) { str1 = _str1; }

	public String getStr1() { return str1; }

	public void setStr1(String _str1) { str1 = _str1; }

}
