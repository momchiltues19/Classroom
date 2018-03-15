package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Negtrimul extends TernaryOperation {

	public Negtrimul(Calculator calculator) {
		super(calculator, "*-*");
	}
	
	@Override
	protected double doCalculate(double value1, double value2, double value3) {
		return - (value1 * value2 * value3);
	}


}
