
import java.io.*;
import javax.comm.*;
import java.util.*;


public class PortSniffer implements Runnable, SerialPortEventListener {

	static Enumeration ports;
	static CommPortIdentifier pid;
	InputStream ins;
	SerialPort com;
	Thread readThread;


	public PortSniffer() {
		try {
			com = (SerialPort)pid.open("PortSniffer", 2000);
		} catch (PortInUseException e) {
			System.out.println("exception: " + e);
		}

		try {
			ins = com.getInputStream();
		} catch (IOException e) {
			System.out.println("exception: " + e);
		}

		try {
			com.addEventListener(this);
		} catch (TooManyListenersException e) {
			System.out.println("exception: " + e);
		}

		com.notifyOnDataAvailable(true);
		com.notifyOnBreakInterrupt(true);
		com.notifyOnCarrierDetect(true);
		com.notifyOnCTS(true);
		com.notifyOnDSR(true);
		com.notifyOnFramingError(true);
		com.notifyOnOutputEmpty(true);
		com.notifyOnOverrunError(true);
		com.notifyOnParityError(true);
		com.notifyOnRingIndicator(true);

		try {
			com.setSerialPortParams(9600,
				SerialPort.DATABITS_8,
				com.STOPBITS_1,
				com.PARITY_NONE);

		} catch (UnsupportedCommOperationException e) {
			System.out.println("exception: " + e);
		}

		readThread = new Thread(this);
		readThread.start();

	}

	public void serialEvent(SerialPortEvent event) {
		switch (event.getEventType()) {
		case SerialPortEvent.BI:
			System.out.println("BI - Break Interrupt");
		case SerialPortEvent.OE:
			System.out.println("OE - Overrun Error");
		case SerialPortEvent.FE:
			System.out.println("FE - Framing Error");
		case SerialPortEvent.PE:
			System.out.println("PE - Parity Error");
		case SerialPortEvent.CD:
			System.out.println("CD - Carrier Detect");
		case SerialPortEvent.CTS:
			System.out.println("CTS - Clear Transfer");
		//case SerialPortEvent.RTS:
		//	System.out.println("RTS - Request Transfer");
		case SerialPortEvent.DSR:
			System.out.println("DSR - Data settlement? Ready");
		case SerialPortEvent.RI:
			System.out.println("RI - Ring Indicator");
		case SerialPortEvent.OUTPUT_BUFFER_EMPTY:
			System.out.println("---- Output buffer empty");
		case SerialPortEvent.DATA_AVAILABLE:
			System.out.println("---- Data available");

			byte[] readBuffer = new byte[20];

			try {
				while (ins.available() > 0) {
					int numBytes = ins.read(readBuffer);
				}
				System.out.print(new String(readBuffer));
			} catch (IOException e) {
				System.out.println("Exception: " + e);
			}
			break;
		}

	}

	public static void main(String[] args) {
		ports = CommPortIdentifier.getPortIdentifiers();

		while (ports.hasMoreElements()) {
			pid = (CommPortIdentifier)ports.nextElement();
			System.out.println("Port " + pid.getName());

			if (pid.getPortType() == CommPortIdentifier.PORT_SERIAL) {
				if (pid.getName().equals("COM1")) {
					PortSniffer pSniffer = new PortSniffer();
					System.out.println("COM1 found");
				}
			}
		}
	}

	public void run() {
		try {
			Thread.sleep(20000);
		} catch (InterruptedException e) {
			System.out.println("exception: " + e);
		}
	}
}

