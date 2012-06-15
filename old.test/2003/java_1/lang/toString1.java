
import java.io.*;

public class toString1 {
	String s = null;
	toString1(String s) { this.s = s; }

	public String toString() { return s; }

	public static void main(String[] args) {
		toString1 tos = new toString1("Hello");

		System.out.println(tos);
	}
}
