#include <iostream>

using namespace std;

struct complex_t 
{
	float real;
	float imag;
};

complex_t add(complex_t other) const 
{
	complex_t result;
	result.real=real+other.real;
	result.imag=imag+other.imag;
	return result;
}

complex_t sub(complex_t other) const
{
	complex_t result;
	result.real=real-other.real;
	result.imag=imag-other.imag;
	return result;
}

complex_t mul(complex_t other) const
{
	complex_t result;
	result.real = real*other.real - imag*other.imag;
	result.imag = imag*other.real + real*other.imag;
	return result;
}

complex_t div(complex_t other) const
{
	complex_t result;
	result.real = (real*other.real + imag*other.imag) / (other.real*other.real + other.imag*other.imag);
	result.imag = (imag*other.real - real*other.imag) / (other.real*other.real + other.imag*other.imag);
	return result;
}

std::istream & read(std::istream & stream) 
{
	char a, b, c;
	float real;
	float imag;
	if (stream >> a && a == '(' && stream >> real && stream >> b && b == ',' && stream >> imag && stream >> c && c == ')') 
	{
		complex.real = real;
		complex.imag = imag;
	}
	else stream.setstate(std::ios::failbit);
	return stream;
}

std::ostream & write(std::ostream & stream) 
{
	stream << "(" << real << "," << imag << ")";
	return stream;
}

int main()
{
	char op;
	complex_t r1, r2;

	if (read(cin, r1) && (cin >> op) && read(cin, r2))
	{
		if (op == '+') write(cout, add(r1, r2));
		if (op == '-') write(cout, sub(r1, r2));
		if (op == '*') write(cout, mul(r1, r2));
		if (op == '/') write(cout, div(r1, r2));
	}
	else cout << "An error has occured while reading input data\n";
	return 0;
}
