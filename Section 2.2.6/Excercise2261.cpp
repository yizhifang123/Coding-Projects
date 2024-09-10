#include <iostream>
#include <stack>
using namespace std;

bool isOperand(char c)
{
    return isdigit(c);
}

int evaluatePrefix(string original_expression)
{
    stack<int> s;

    for (int j = original_expression.size() - 1; j >= 0; j--) {
        if (isOperand(original_expression[j]))
            s.push(original_expression[j] - '0');
        else {
            int operator1 = s.top();
            s.pop();
            int operator2 = s.top();
            s.pop();
            switch (original_expression[j]) {
            case '+':
                s.push(operator1 + operator2);
                break;
            case '*':
                s.push(operator1 * operator2);
                break;
            case '/':
                s.push(operator1 / operator2);
                break;
            case '-':
                s.push(operator1 - operator2);
                break;
            }
        }
    }

    return s.top();
}
