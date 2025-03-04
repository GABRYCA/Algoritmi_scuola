package ThreadEs3;

public class ThreadNome extends Thread {
	
	public void run() {
		for (int i = 0; i < 3; i ++) System.out.println(this.getName());
	}
	
	public ThreadNome(String nome) {
		super(nome);
	}

}
