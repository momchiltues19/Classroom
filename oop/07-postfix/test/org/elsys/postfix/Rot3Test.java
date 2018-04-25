package org.elsys.postfix;

import org.junit.Test;

public class Rot3Test extends CalculatorAbstractTest {

	@Test
	public void test() {
		input("1");
		input("2");
		input("3");
		input("rot3");
		inputCtrlC();
		runCalculator();
		assertCalculatorLastValue(2);
		assertCalculatorStackSize(3);
	}

	@Test
	public void testRot3SwapDuplicateAndNegate() {
		input("1");
		input("2");
		input("3");
		input("rot3");
		input("swap");
		input("dup");
		input("neg");
		input("swap");
		inputCtrlC();
		runCalculator();
		assertCalculatorLastValue(1);
		assertCalculatorStackSize(4);
	}
}
