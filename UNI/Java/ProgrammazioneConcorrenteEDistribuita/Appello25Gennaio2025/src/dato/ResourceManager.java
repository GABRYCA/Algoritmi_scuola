package dato;

import java.util.LinkedList;

public class ResourceManager {
	LinkedList<Resource> listA;  
	LinkedList<Resource> listB;  
	ResourceManager(){
		 listA = new LinkedList<>();  
		 listB = new LinkedList<>();  
	}
	private void printout() {
		Resource r;
		System.out.print("[A:");
		for(int i=0; i<listA.size(); i++) {
			r=listA.get(i);
			System.out.print(" "+r.getType()+r.getNum());
		}
		System.out.print("] [B:");
		for(int i=0; i<listB.size(); i++) {
			r=listB.get(i);
			System.out.print(" "+r.getType()+r.getNum());
		}
		System.out.println("]");
	}
	public synchronized Resource getA() {
		Resource r;
		if(listA.isEmpty()) {
			return (Resource) null;
		} else {
			r=listA.remove(0);
			printout();
			return r;
		}
	}
	public synchronized Resource getB() {
		Resource r;
		if(listB.isEmpty()) {
			return (Resource) null;
		} else {
			r=listB.remove(0);
			printout();
			return r;
		}
	}
	public synchronized void put(Resource r) {
		if(r.getType()==ResourceType.A) {
			listA.add(r);
		}
		if(r.getType()==ResourceType.B) {
			listB.add(r);
		}
		printout();
	}
}
