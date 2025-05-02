package Esercizio1;

import java.util.Hashtable;

public class Bank {
	Hashtable<Integer, Integer> ccAmounts;

	Bank(int size) {
		ccAmounts = new Hashtable<Integer, Integer>(size);
		for (Integer i = 0; i < size; i++) {
			ccAmounts.put(i, 0);
		}
	}

	public synchronized Result executeOperation(OperationRequest op) {
		Integer ccNum = op.getCCnumber();
		String opType = op.getRequest();
		Integer curValue = ccAmounts.get(ccNum);
		if (curValue == null) {
			return new Result(-1, 0, opType, false);
		}
		if (opType.equals("Deposit")) {
			ccAmounts.put(ccNum, curValue + op.getAmount());
			return new Result(ccNum, curValue + op.getAmount(), opType, true);
		} else if (opType.equals("Withdraw")) {
			if (op.getAmount() > curValue) {
				return new Result(ccNum, 0, opType, false);
			} else {
				ccAmounts.put(ccNum, curValue - op.getAmount());
				return new Result(ccNum, curValue - op.getAmount(), opType, true);
			}
		} else {
			return new Result(ccNum, 0, "unknown", false);
		}
	}
}
