package org.elsys.postfix.operations;

import java.util.EmptyStackException;

import org.elsys.postfix.Calculator;

public abstract class BinaryOperation extends AbstractOperation {

	public BinaryOperation(Calculator calculator, String token) {
		super(calculator, token);
	}
	
	@Override
	public void calculate() {
		try
		{
			double value1 = getCalculator().popValue();
			double value2 = getCalculator().popValue();
			double result = doCalculate(value1,value2);
			getCalculator().addValue(result);	
		}
		catch(Exception e)
		{
			throw new EmptyStackException();
		}
	}

	protected abstract double doCalculate(double value1, double value2);
}
