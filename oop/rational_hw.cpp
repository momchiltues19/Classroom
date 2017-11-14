#include <iostream>
using namespace std;

int gcd(int n1, int n2)
{
	int gcd = n1 < n2 ? n1 : n2;
	while (gcd != 1)
	{
		if(n1%gcd == 0 && n2%gcd == 0)
			return gcd;
		gcd--;
	}
	return gcd;
}

class Rational
{
	int numerator_;
	int denominator_;
public:
	Rational(int numerator, int denominator)
	{
		int gcds = gcd(numerator, denominator);		
		numerator_ = numerator/gcds;
		denominator_ = denominator/gcds;	
			
	}
	int get_numerator()
	{
		return numerator_;
	}
	
	void set_numerator(int numerator)
	{
		numerator_ = numerator;
	}

	int get_denominator()
	{
		return denominator_;
	}
	
	void set_denominator(int denominator)
	{
		denominator_ = denominator;
	}
	
	void make_nice() //temp name
	{
		numerator_ /= gcd(numerator_, denominator_);
		denominator_ /= gcd(numerator_, denominator_);
	}	
	
	void print()
	{
		cout << numerator_ << "/" << denominator_ << endl;
	}

	Rational operator+(const Rational other) const
	{
		Rational result(1,1);		
		result.numerator_ = numerator_ * other.denominator_ + other.numerator_ * denominator_;
		result.denominator_ = denominator_ * other.denominator_;
		result.make_nice();
		return result;
	}
	
};

int main()
{
	Rational mynum(2,4), yonum(10,20);
	mynum.print();
	mynum = mynum + yonum;
	mynum.print();
	return 0;	
}
