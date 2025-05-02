package Esercizio1.Dato;

public class OperationRequest {
	int CCnumber;
	int amount;
	String request;

	OperationRequest(int cc, int val, String what) {
		CCnumber = cc;
		amount = val;
		request = what;
	}

	public int getCCnumber() {
		return CCnumber;
	}

	public int getAmount() {
		return amount;
	}

	public String getRequest() {
		return request;
	}
}
