public class EsempioSwitch {

	public static void main(String[] args){
		char c = 'A'; //AAAEEEddd (oppure c = 'C')
		c = 'D'; //EEEddd (oppure c = 'W')
		c = 'H'; //non viene eseguito nulla -> break
		c = 'J'; //KKKeee
		c = 'G'; //eee (oppure c = 'P')
		c = 'M'; //ddd
		switch(c) {
			case 'A':
			case 'C':
				System.out.print("AAA");
			case 'D':
			case 'W':
				System.out.print("EEE");
			default:
				System.out.print("ddd");
			case 'H':
				break;
			case 'J':
				System.out.print("KKK");
			case 'G':
			case 'P':
				System.out.print("eee");
		}
	}
}