#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct rational_number
{
	int numerator;
	int denominator;
}Rnum;

char operator[] = { '@', '+', '-', '*', '/' };
int gcd(int a, int b);
Rnum create_Rnum(int a, int b);
Rnum add(Rnum x, Rnum y);
Rnum sub(Rnum x, Rnum y);
Rnum mul(Rnum x, Rnum y);
Rnum divs(Rnum x, Rnum y);
void input_num(Rnum* num);
void print_Rnum(Rnum num);
void calculator(int op, Rnum x, Rnum y, Rnum* ret);
void menu();
int main()
{

	int input = 0;
	do
	{
		menu();
		printf("your option:>");
		scanf("%d", &input);
		if (!input) break;
		if (!(input == 1 || input == 2 || input == 3 || input == 4))
		{
			printf("option error, input again!\n");
			continue;
		}
		Rnum num1 = { 0, 1 };
		Rnum num2 = { 0, 1 };
		input_num(&num1);
		input_num(&num2);
		Rnum ret = { 0, 1 };
		calculator(input, num1, num2, &ret);
		print_Rnum(num1);
		printf(" %c ", operator[input]);
		print_Rnum(num2);
		printf(" = ");
		print_Rnum(ret);
		printf("\n");
	} while (input);
	
	return 0;
}

int gcd(int a, int b)//great common dividor
{
	int tmp = 0;
	do
	{
		tmp = a % b;
		a = b;
		b = tmp;
	} while (tmp);
	return a;
}

Rnum create_Rnum(int a, int b)
{
	assert(b != 0);
	Rnum tmp;
	int divs = gcd(a, b);
	tmp.numerator = a / divs;
	tmp.denominator = b / divs;
	return tmp;
}

Rnum add(Rnum x, Rnum y)//addition
{
	Rnum ret = { 0, 1 };
	ret.denominator = x.denominator * y.denominator;
	ret.numerator = x.numerator * y.denominator + y.numerator * x.denominator;
	ret = create_Rnum(ret.numerator, ret.denominator);
	return ret;
}

Rnum sub(Rnum x, Rnum y)//substraction
{
	Rnum ret = { 0, 1 };
	ret.denominator = x.denominator * y.denominator;
	ret.numerator = x.numerator * y.denominator - y.numerator * x.denominator;
	ret = create_Rnum(ret.numerator, ret.denominator);
	return ret;
}

Rnum mul(Rnum x, Rnum y) //multiplication
{
	Rnum ret = { 0, 1 };
	ret.denominator = x.denominator * y.denominator;
	ret.numerator = x.numerator * y.numerator;
	ret = create_Rnum(ret.numerator, ret.denominator);
	return ret;
}

Rnum divs(Rnum x, Rnum y) //divisoin
{
	assert(y.numerator != 0);
	Rnum ret = { 0, 1 };
	ret.denominator = x.denominator * y.numerator;
	ret.numerator = x.numerator * y.denominator;
	ret = create_Rnum(ret.numerator, ret.denominator);
	return ret;
}
void input_num(Rnum* num)
{
	int a = 0, b = 0;
	printf(" Please input numerator and denomator:>");
	while (scanf("%d %d", &a, &b))
	{
		if (b != 0)
		{
			*num = create_Rnum(a, b);
			break;
		}
		else
			printf("denominator can not be zero!\n");

	}
}

void print_Rnum(Rnum num)
{
	int numerator_negative = 0;
	int denominator_negative = 0;
	if (num.denominator < 0)
	{
		denominator_negative = 1;
		num.denominator = -num.denominator;
	}

	if (num.numerator < 0)
	{
		numerator_negative = 1;
		num.numerator = -num.numerator;
	}
	if (num.numerator == 0)
		printf("%d", 0);
	else if ((denominator_negative && numerator_negative) || (!denominator_negative && !numerator_negative))
	{
		if (num.denominator != 1)
			printf("%d/%d", num.numerator, num.denominator);
		else
			printf("%d", num.numerator);
	}
	else if ((denominator_negative && !numerator_negative) || (!denominator_negative && numerator_negative))
	{
		if (num.denominator != 1)
			printf("-%d/%d", num.numerator, num.denominator);
		else
			printf("-%d", num.numerator);
	}
}

void calculator(int op, Rnum x, Rnum y, Rnum* ret)
{
	switch (op)
	{
	case 1:
		*ret = add(x, y);
		break;
	case 2:
		*ret = sub(x, y);
		break;
	case 3:
		*ret = mul(x, y);
		break;
	case 4:
		*ret = divs(x, y);
	/*default:
		printf("input opition error, input again!\n");*/
	}
}

void menu()
{
	printf("-----------------------------\n");
	printf("----input 0: exit------------\n");
	printf("----input 1: addition--------\n");
	printf("----input 2: subtraction-----\n");
	printf("----input 3: multiplication--\n");
	printf("----input 4: division--------\n");
	printf("----input other: nothing-----\n");
	printf("-----------------------------\n");
}