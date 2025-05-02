package Esercizio1.Dato;

public class Bank {
	int ccAmounts[] = { 0, 0, 0 };

//	Bank(){	}
	public Result executeOperation(OperationRequest op) {
		int ccNum = op.getCCnumber();
		String opType = op.getRequest();
		if (ccNum < 0 || ccNum > 2) {
			return new Result(-1, 0, opType, false);
		}
		if (opType.equals("Deposit")) {
			ccAmounts[ccNum] += op.getAmount();
			return new Result(ccNum, ccAmounts[ccNum], opType, true);
		} else if (opType.equals("Withdraw")) {
			if (op.getAmount() > ccAmounts[ccNum]) {
				return new Result(ccNum, 0, opType, false);
			} else {
				ccAmounts[ccNum] -= op.getAmount();
				return new Result(ccNum, ccAmounts[ccNum], opType, true);
			}
		} else {
			return new Result(ccNum, ccAmounts[ccNum], "unknown", false);
		}
	}
}
