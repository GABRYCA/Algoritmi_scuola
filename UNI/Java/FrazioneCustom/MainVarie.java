package varie;

public class MainVarie {

	public static void main(String[] args) {
		
		FrazioneCustom f1 = new FrazioneCustom(32,128);
		FrazioneCustom f2 = new FrazioneCustom(1,4);
		
		FrazioneCustom per = f1.per(f2);
		System.out.println("per > "+per.toString());
		//f2 = f1;
		System.out.println("equals >"+f1.equals(f2));
	
		valoreAssoluto(3.2);
		valoreAssoluto(-3);
	}
	
	public static double valoreAssoluto(double x) {
		if (x > 0)
			return x;
		else
			return -x;
	}
	
	public static int valoreAssoluto(int x) {
		return (int) valoreAssoluto((double)x);
	}
}
