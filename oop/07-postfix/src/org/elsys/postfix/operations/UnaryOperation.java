package org.elsys.postfix.operations;

import java.util.EmptyStackException;

import org.elsys.postfix.Calculator;

public abstract class UnaryOperation extends AbstractOperation {

	public UnaryOperation(Calculator calculator, String token) {
		super(calculator, token);
	}

	@Override
	public void calculate() {
		try
		{
			double value = getCalculator().popValue();
			double result = doCalculate(value);
			getCalculator().addValue(result);		
		}
		catch(Exception e)
		{
			throw new EmptyStackException();
		}
	}

	protected abstract double doCalculate(double value);
}
