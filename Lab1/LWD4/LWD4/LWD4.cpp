#include <iostream>

class Expression
{
public:
	virtual ~Expression()
	{}
	virtual double evaluate()
	{
		return 0;
	}

private:

};

class Number : public Expression
{
public:
	Number(double innumb);
	double evaluate() override;

private:
	double value;
};

class  BinaryOperation : public Expression

{
public:
	BinaryOperation(Expression* left, char op, Expression* right);
	double evaluate() override;
	~BinaryOperation();
private:
	Expression* left_p;
	Expression* right_p;
	char oper;
};

bool check_equals(Expression const* left, Expression const* right);

int main()
{
	setlocale(LC_ALL, "rus");
	Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
	Expression* expr = new BinaryOperation(new Number(3), '+', sube);
	std::cout << expr->evaluate() << '\n';
	std::cout << "Number and BinaryOperation:\n";
	if (check_equals(new Number(2), sube))
		std::cout << "одного класса\n";
	else
		std::cout << "разных классов\n";
	std::cout << "Number and Number:\n";
	if (check_equals(new Number(2), new Number(0)))
		std::cout << "одного класса\n";
	else
		std::cout << "разных классов\n";
	std::cout << "BinaryOperation and BinaryOperation:\n";
	if (check_equals(expr, sube))
		std::cout << "одного класса\n";
	else
		std::cout << "разных классов\n";
}

Number::Number(double innumb)
{
	value = innumb;
}

double Number::evaluate()
{
	return value;
}

BinaryOperation::BinaryOperation(Expression* left_in, char symb, Expression* right_in)
{
	oper = symb;
	left_p = left_in;
	right_p = right_in;
}

double BinaryOperation::evaluate()
{
	double left = left_p->evaluate();
	double right = right_p->evaluate();
	if (oper == '+')
	{
		return left + right;
	}
	if (oper == '-')
	{
		return left - right;
	}
	if (oper == '*')
	{
		return left * right;
	}
	if (oper == '/')
	{
		return left / right;
	}
}

BinaryOperation::~BinaryOperation()
{
	delete left_p;
	delete right_p;
}

bool check_equals(Expression const* left, Expression const* right) 
{
	return(*((long long*)left) == *((long long*)right));
}
