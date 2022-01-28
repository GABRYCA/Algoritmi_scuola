import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class UtilList {
 public static void main(String[] args) { 
  ArrayList<Integer> list = new ArrayList<Integer>();
  for (int i = 0; i<10; i++){ 
   list.add(i,i);
  }
  list.add(0,1);		
  list.add(3,1);
  list.add(2,2);
  System.out.println("lista : "+list);
  eliminaDoppi(list);
  System.out.println("lista senza doppi : "+list);
  copiaInteriInversi();
  ArrayList<Integer> anotherList = new ArrayList<Integer>();
  for (int i = 3; i<6; i++){ 
    anotherList.add(i-3,i);
  }
  System.out.println("list : " + list + " anotherList : " + anotherList + " sottosequenza ? "+ sottoSequenza(list,anotherList));
 }
	
 /** 
 * Data due liste di interi restituisce vero se la seconda lista e' una sottosequenza della prima
 * falso altrimenti
 * 
 * @param list lista
 * @param seq sequenza
 * @return vero se seq e' una sottosequenza di lista
 * */
 private static boolean sottoSequenza(List<Integer> list, List<Integer> seq) {
  System.out.println("metodo da implementare");
  return false;
 }

 /**
  * Legge una sequenza di interi da ingresso, 
  * terminata da un carattere. 
  * Stampa la sequenza di interi letta dall'ultimo al primo.
  * 
  * */
 private static void copiaInteriInversi() {
  System.out.println("metodo da implementare");
 } 
	
 /**
 * Elimina tutte i doppioni dalla lista di interi, 
 * mantenendo solo la prima occorrenza di ogni elemento 
 * */
 private static void eliminaDoppi(List<Integer> list) {
  System.out.println("metodo da implementare");
 }
	
}