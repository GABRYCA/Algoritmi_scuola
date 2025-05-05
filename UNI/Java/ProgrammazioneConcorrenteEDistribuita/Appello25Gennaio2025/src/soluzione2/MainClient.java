package soluzione2;

public class MainClient {

	public static void main(String[] args) {
		System.out.println("Avviando utente...");
		User user = new User();
		Thread thread = new Thread(user);
		thread.start();
	}
}
