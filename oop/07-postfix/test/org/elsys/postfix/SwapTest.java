package org.elsys.postfix;

import org.junit.Test;

public class SwapTest extends CalculatorAbstractTest {

	@Test
	public void test() {
		input("10");
		input("20");
		input("swap");
		inputCtrlC();
		runCalculator();
		assertCalculatorLastValue(10);
		assertCalculatorStackSize(2);
	}

	@Test
	public void testDuplicateSwapAndNegate() {
		input("10");
		input("20");
		input("swap");
		input("dup");
		input("neg");
		input("swap");
		inputCtrlC();
		runCalculator();
		assertCalculatorLastValue(10);
		assertCalculatorStackSize(3);
	}
}
