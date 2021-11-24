#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

int evaluatePrefix(string exp)
{
	stack<int> S;
	for (int i = exp.length() - 1; i >= 0; i--)
	{
		if (exp[i] >= '0' && exp[i] <= '9')
			S.push(exp[i] - '0');
		else
		{
			int a = S.top();
			S.pop();
			int b = S.top();
			S.pop();
			switch (exp[i])
			{
			case'+':
				S.push(a + b);
				break;
			case'-':
				S.push(a - b);
				break;
			case'*':
				S.push(a * b);
				break;
			case'/':
				S.push(a / b);
				break;
			case'^':
				S.push(pow(a, b));
				break;
			}
		}
	}
	return S.top();
}

int evaluatePostfix(string exp)
{
	stack<int> S;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] >= '0' && exp[i] <= '9')
			S.push(exp[i] - '0');
		else
		{
			int a = S.top();
			S.pop();
			int b = S.top();
			S.pop();
			switch (exp[i])
			{
			case'+':
				S.push(a + b);
				break;
			case'-':
				S.push(b - a);
				break;
			case'*':
				S.push(a * b);
				break;
			case'/':
				S.push(b / a);
				break;
			case'^':
				S.push(pow(b, a));
				break;
			}
		}
	}
	return S.top();
}

int main()
{
	string type;
	string exp;
	cout << "Enter pre for prefix and post for postfix:" << endl;
	cin >> type;
	if (type == "pre")
	{
		cout << "Enter the expression:" << endl;
		cin >> exp;
		cout << "Answer: " << evaluatePrefix(exp);
		return 0;
	}
	else if (type == "post")
	{
		cout << "Enter the expression:" << endl;
		cin >> exp;
		cout << "Answer: " << evaluatePostfix(exp);
		return 0;
	}
	else
	{
		cout << "Enter correct value";
		return 0;
	}
}