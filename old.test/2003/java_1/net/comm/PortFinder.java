

import java.io.*;
import javax.comm.*;
import java.util.*;

public class PortFinder {

	public PortFinder() {}

	public static void main(String[] args) {

		System.out.println("Enumerating...");

		Enumeration ports = CommPortIdentifier.getPortIdentifiers();

		while (ports.hasMoreElements()) {

			CommPortIdentifier cpi = (CommPortIdentifier)ports.nextElement();

			System.out.println("Port: " + cpi.getName());
		}
	}
}
