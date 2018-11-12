#include<iostream>
using namespace std;
#include<stack>
#include<string>
#include<list>
#include<cmath>
#include<stdexcept>
#include<algorithm>
#include<cstring>

inline size_t precedence(const char op)
{
	if (op == '+' || op == '-')
	{
		return 1;
	}
	if (op == '*' || op == '/')
	{
		return 2;
	}
	if (op == '^')
	{
		return 3;
	}
	throw runtime_error{ string{"invalid operator:"}+op };
}

double execute(stack<char>& ops, stack<double> &operands)
{
	double result{};
	double rhs{ operands.top() };
	operands.pop();
	double lhs{ operands.top() };
	operands.pop();

	switch (ops.top())
	{
	case '+':
		result = lhs + rhs;
		break;
	case '-':
		result = lhs - rhs;
		break;
	case '*':
		result = lhs * rhs;
		break;
	case '^':
		result = pow(lhs, rhs);
		break;
	case'/':
		result = lhs / rhs;
		break;
	default:
		throw runtime_error{ string{"invalid operator:"}+ops.top() };
	}
	ops.pop();
	operands.push(result);
	return result;
}
int main()
{
	stack<double>operands;
	stack<char>operators;
	string exp{ 6*5+3 };
	
	cout << "An arithmetic expression can include the operators+,-,*,/," << "and ^ for exponentiation" << endl;
	try
	{
		while (true)
		{
			cout << "Enter an arithmetic expression and press Enter" << "- enter an empty line to end:" << endl;
			getline(cin, exp, '\n');
			if (exp.empty())break;
			exp.erase(remove(begin(exp), end(exp), ' '), end(exp));
			size_t index{ };

			operands.push(stod(exp, &index)); //左操作数
			while (true)
			{
				operators.push(exp[++index]); //符号

				size_t i{};
				operands.push(stod(exp.substr(++index), &i));//右操作数
				//index += i;
				cout << index << endl;
				if (index == exp.length())
				{
					while (!operators.empty())
					{
						execute(operators, operands);
					}
					break;
				}
				while (!operators.empty() && precedence(exp[++index]) <= precedence(operators.top()))
				{
					execute(operators, operands);
				}
				

			}
			cout << "result =" << operands.top() << endl;
		}
		
		
	}
	catch (const exception &e)
	{
		cerr << e.what() << endl;
	}
	cout << "Calculator ending ..." << endl;
//	size_t index=0;
//	operands.push(stod(exp, &index));
	getchar();
	return 0;
}