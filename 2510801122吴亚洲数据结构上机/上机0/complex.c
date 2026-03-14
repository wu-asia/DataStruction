#include<stdio.h>

typedef struct complex_number
{
	double real;
	double imag;
}complex;
complex create_complex(double real_part, double imag_part);
complex add(complex x, complex y);
void print_complex(complex num);

int main()
{
	complex num1 = create_complex(1, 2);
	complex num2 = create_complex(2, 4);
	complex ret = add(num1, num2);
	print_complex(ret);
	return 0;
}

complex create_complex(double real_part, double imag_part)
{
	complex num = { 0, 0 };
	num.real = real_part;
	num.imag = imag_part;
	return num;
}

complex add(complex x, complex y)
{
	complex ret = { 0, 0 };
	ret.real = x.real + y.real;
	ret.imag = x.imag + y.imag;
	return ret;
}

void print_complex(complex num)
{
	printf("%lf + %lfi\n", num.real, num.imag);
}