package dato;

public class Main {
	static final int numUser=10;
	static final int numResources=4;
	public static void main(String[] args) {
		ResourceManager rm=new ResourceManager();
		for(int i=0; i<numResources; i++) {  // Attenzione!
			// le risorse di ciascun tipo sono meno degli utilizzatori!
			rm.put(new Resource(ResourceType.A));
			rm.put(new Resource(ResourceType.B));
		}
		for(int i=0; i<numUser; i++) {
			new User(rm).start();
		}
	}
}
