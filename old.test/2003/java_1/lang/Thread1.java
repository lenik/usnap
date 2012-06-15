
public class Thread1 {

	public static void main(String[] args) {
		new Thread(
			new Runnable() {

				public void run() {

					System.out.println("[Thread] Hello");
				}

			}
		).start();
	}
}
