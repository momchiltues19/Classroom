package org.elsys.postfix;

import java.io.InputStream;
import java.io.PrintStream;
import java.util.EmptyStackException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

import org.elsys.postfix.operations.Addition;
import org.elsys.postfix.operations.Cos;
import org.elsys.postfix.operations.Division;
import org.elsys.postfix.operations.Duplicate;
import org.elsys.postfix.operations.Multiplication;
import org.elsys.postfix.operations.Negate;
import org.elsys.postfix.operations.Negtrimul;
import org.elsys.postfix.operations.Operation;
import org.elsys.postfix.operations.Sin;
import org.elsys.postfix.operations.Subtraction;

public class Calculator {

	private Map<String, Operation> operations = new HashMap<>();

	private List<Double> stack = new LinkedList<>();

	private InputStream in;

	private PrintStream out;
	
	public Calculator(InputStream in, PrintStream out) {
		this.in = in;
		this.out = out;
		addOperation(new Negate(this));
		addOperation(new Duplicate(this));
		addOperation(new Sin(this));
		addOperation(new Cos(this));
		addOperation(new Addition(this));
		addOperation(new Subtraction(this));
		addOperation(new Multiplication(this));
		addOperation(new Division(this));
		addOperation(new Negtrimul(this));
	}

	public void run() {
		String input;
		try (Scanner scanner = new Scanner(in)) {
			while (scanner.hasNext()) {
				out.print(stack.size() + ": ");
				input = scanner.next();
				if (isDouble(input)) {
					stack.add(Double.valueOf(input));
				} else {
					Operation operation = getOperation(input);
					if (operation != null) {
						operation.calculate();
					} else {
						throw new UnsupportedOperationException();
					}
				}
			}
		}
	}

	private static boolean isDouble(String input) {
		try {
			Double.valueOf(input);
		} catch (NumberFormatException e) {
			return false;
		}
		return true;
	}

	public void addOperation(Operation operation) {
		operations.put(operation.getToken(), operation);
	}

	public Operation getOperation(String token) {
		return operations.get(token);
	}

	public Double popValue() {
		int lastIndex = stack.size() - 1;
		if(lastIndex < 0) throw new EmptyStackException();
		Double value = stack.get(lastIndex);
		stack.remove(lastIndex);
		return value;
	}

	Double lastValue() {
		return stack.get(stack.size() - 1);
	}

	public void addValue(double value) {
		out.println(value);
		stack.add(value);
	}

	int stackSize() {
		return stack.size();
	}
}
