package ThreadEs6;

public class ThreadNumero extends Thread {
	public void run() {
		for (int i = 0; i < 10; i++) System.out.println(this.getName());
	}
	
	public ThreadNumero(int numero) {
		super(String.valueOf(numero));
	}

}
