package org.elsys.postfix;

import org.junit.Test;

public class AddOneTest extends CalculatorAbstractTest {

	@Test
	public void test() {
		input("\\add1");
		input("1");
		input("+");
		input("def");
		
		input("3");
		input("add1");
		inputCtrlC();
		
		runCalculator();
		assertCalculatorLastValue(4.0);
	}

}
