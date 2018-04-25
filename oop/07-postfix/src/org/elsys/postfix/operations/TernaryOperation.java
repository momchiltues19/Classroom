package org.elsys.postfix.operations;

import java.util.EmptyStackException;

import org.elsys.postfix.Calculator;

public abstract class TernaryOperation extends AbstractOperation {

	public TernaryOperation(Calculator calculator, String token) {
		super(calculator, token);
	}
	
	@Override
	public void calculate() {
		try	
		{
			double value1 = getCalculator().popValue();
			double value2 = getCalculator().popValue();
			double value3 = getCalculator().popValue();
			double result = doCalculate(value1,value2, value3);
			getCalculator().addValue(result);
		}
		catch(Exception e)
		{
			throw new EmptyStackException();
		}
		
	}

	protected abstract double doCalculate(double value1, double value2, double value3);
}
