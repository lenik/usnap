

public class TypeCheck {

	public String getType(Object o) {
		if (o instanceof String) {
			return "String";
		} else if (o instanceof Integer) {
			return "Integer";
		}
		return "Other";
	}

	public String getType2(Object o) {
		return o.getClass().getName();
	}

	public static void main(String[] args) {
		TypeCheck tc = new TypeCheck();

		System.out.println(tc.getType2("DFSJDKLFJ"));
		System.out.println(tc.getType2(new Integer(100)));

	}
}
