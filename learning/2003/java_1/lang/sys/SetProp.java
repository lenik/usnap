

public class SetProp {

	/** Creates a new instance of SetProp */
	public SetProp() {

	}

	public static void main(String[] args) {
		System.setProperty("MyName", "Danci.Z");
		System.out.println(
			System.getProperty("MyName")
			);
	}
}
