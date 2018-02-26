#include <iostream>

using namespace std;

struct complex_t 
{
	complex_t() 
	{
		real = 0.0f;
		imag = 0.0f;
	}

	complex_t add(complex_t other) const 
	{
		complex_t result;
		result.real = real + other.real;
		result.imag = imag + other.imag;
		return result;
	}
	complex_t sub(complex_t other) const 
	{
		complex_t result;
		result.real = real - other.real;
		result.imag = imag - other.imag;
		return result;
	}
	complex_t mul(complex_t other) const 
	{
		complex_t result;
		result.real = real * other.real - imag * other.imag;
		result.imag = imag * other.real + real * other.imag;
		return result;
	}
	complex_t div(complex_t other) const 
	{
		complex_t result;
		result.real = (real*other.real + imag * other.imag) / (other.real*other.real + other.imag*other.imag);
		result.imag = (imag*other.real - real * other.imag) / (other.real*other.real + other.imag*other.imag);
		return result;
	}

	istream & read(istream & stream) 
	{
		char op;
		return  stream >> op >> real>> op >> imag >> op;
	}

	ostream & write(ostream & stream) const
	{
		return stream  << "(" << real << ", " << imag << ")";
	}
	float real;
	float imag;
};

int main() 
{
	char op;
	complex_t r1, r2;

	if (r1.read(cin) && (cin >> op) && r2.read(cin)) 
	{
		
			if (op == '+') (r1.add(r2)).write(cout);
			if (op == '-') (r1.sub(r2)).write(cout);
			if (op == '*') (r1.mul(r2)).write(cout);
			if (op == '/') (r1.div(r2)).write(cout);
	}
	else cout << "An error has occured while reading input data.\n";
	return 0;
}
