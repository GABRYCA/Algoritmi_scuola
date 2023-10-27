/* Date due stringhe, la stringa shuffle delle due si ottiene alternando i caratteri della prima stringa con i caratteri della
seconda, e copiando i rimanenti caratteri nel caso le due stringhe abbiano diversa lunghezza. Ad esempio, date le
stringhe ”eae” e ”sm”, la stringa shuffle delle due `e ”esame”. Si implementi un metodo che restituisce la stringa shuffle
di s1 e s2, con il seguente prototipo:
public static String shuffle(String s1, String s2)
*/
public class ShuffleString {

	public static void main(String[] args) {
		String s1 = "eae";
		String s2 = "sm";
		String ris = "";
		
		if(s1.length() >= s2.length()) {
			for(int i=0; i < s2.length(); i++)
				ris += s1.charAt(i) + "" + s2.charAt(i);
				//oppure
				//ris += s1.substring(i,i+1) + s2.substring(i,i+1);
			ris += s1.substring(s2.length());
		} else {
			for(int i=0; i < s1.length(); i++)
				ris += s1.charAt(i) + "" +  s2.charAt(i);
				//oppure
				//ris += s1.substring(i,i+1) + s2.substring(i,i+1);
			ris += s2.substring(s1.length());
		}
		
		System.out.println("Stringa shuffle > "+ris);
	}
}
		