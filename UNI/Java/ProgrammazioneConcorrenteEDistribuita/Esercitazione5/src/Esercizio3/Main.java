package Esercizio3;

import Esercizio3.basic.TableBasic;
import Esercizio3.fair.TableFair;
import Esercizio3.fair_no_waiter.TableFairNoWaiter;

public class Main {

	public static void main(String[] args) {
		System.out.println("Filosofi vari con Waiter: ");
		System.out.println("Filosofo Basic: ");
		TableBasic tBasic = new TableBasic();
		
		System.out.println("Filosofo Fair: ");
		TableFair tFair = new TableFair();
		
		System.out.println("Filosofo Fair senza Waiter: ");
		TableFairNoWaiter tFairNoWaiter = new TableFairNoWaiter();
		
		System.out.println("Fine!");
		
	}

}
