
class MyJavaClass {
	public int aValue;
	public void divByTwo() { aValue /= 2; }
}

public class UseObjects {
	private native void changeObject(MyJavaClass obj);
	static {
		System.loadLibrary("UseObjImpl");
	}

	public static void main(String[] args) {
		UseObjects app = new UseObjects();
		MyJavaClass anObj = new MyJavaClass();
		anObj.aValue = 10;
		app.changeObject(anObj);
		System.out.println("Java: " + anObj.aValue);
	}
}
