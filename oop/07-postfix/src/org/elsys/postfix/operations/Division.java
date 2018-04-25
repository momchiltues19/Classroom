package org.elsys.postfix.operations;

import org.elsys.postfix.Calculator;

public class Division extends BinaryOperation {

	public Division(Calculator calculator) {
		super(calculator, "/");
	}
	
	@Override
	protected double doCalculate(double value1, double value2) {
		return value2 / value1;
	}


}
