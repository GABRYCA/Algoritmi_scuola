package Esercizio2;

public class Chopstick {
	public enum State {AVAILABLE, BUSY}
	private State state;
	private int id;
	
	public Chopstick(int id) {
		this.id = id;
		this.state = Chopstick.State.AVAILABLE;
	}
	
	public boolean isAvaliable() {
		return state == Chopstick.State.AVAILABLE;
	}
	
	public void take( ) {
		this.state = Chopstick.State.BUSY;
	}
	
	public void leave() {
		this.state = Chopstick.State.AVAILABLE;
	}
	
	public String getName() {
		return "bacchetta "+id;
	}
	
	public String toString() {
		return "bacchetta "+id;
	}
	
	public int getId() {
		return this.id;
	}
}
