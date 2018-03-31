package org.elsys.postfix;

import java.util.EmptyStackException;

import org.junit.Test;

public class NegativeTripleMultiplicationTest extends CalculatorAbstractTest {

	@Test(expected = EmptyStackException.class)
	public void testWithNotEnoughValuesInStack() {
		input("3");
		input("2");
		input("\\*-\\*");
		inputCtrlC();
		runCalculator();
	}

	@Test
	public void test() {
		input("2");
		input("3");
		input("4");
		input("\\*-\\*");
		inputCtrlC();
		runCalculator();
		assertCalculatorLastValue(-24);
		assertCalculatorStackSize(1);
	}
	
	@Test
	public void testNegtrimulDupNegatgeAndSubtraction() {
		input("-2");
		input("dup");
		input("neg");
		input("3");
		input("4");
		input("\\*-\\*");
		input("-");
		inputCtrlC();
		runCalculator();
		assertCalculatorLastValue(22);
		assertCalculatorStackSize(1);
	}
}