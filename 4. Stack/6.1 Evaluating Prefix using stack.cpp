#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool IsNumericDigit(char C) {
    return (C >= '0' && C <= '9');
}

bool IsOperator(char C) {
    return (C == '+' || C == '-' || C == '*' || C == '/');
}

int PerformOperation(char operation, int operand1, int operand2) {
    if (operation == '+') return operand1 + operand2;
    else if (operation == '-') return operand1 - operand2;
    else if (operation == '*') return operand1 * operand2;
    else if (operation == '/') return operand1 / operand2;
    else {
        cout << "Unexpected Error \n";
        return -1;
    }
}

int EvaluatePrefix(string expression) {
    stack<int> S;

    for (int i = expression.length() - 1; i >= 0; i--) {
        if (expression[i] == ' ' || expression[i] == ',') continue;

        else if (IsOperator(expression[i])) {
            int operand1 = S.top(); S.pop();
            int operand2 = S.top(); S.pop();
            int result = PerformOperation(expression[i], operand1, operand2);
            S.push(result);
        }
        else if (IsNumericDigit(expression[i])) {
            int operand = 0;
            while (i >= 0 && IsNumericDigit(expression[i])) {
                operand = (operand * 10) + (expression[i] - '0');
                i--;
            }
            i++; // Increment i to point to the last numeric digit
            S.push(operand);
        }
    }
    return S.top();
}

int main() {
    string expression;
    cout << "Enter Prefix Expression \n";
    getline(cin, expression);
    int result = EvaluatePrefix(expression);
    cout << "Output = " << result << "\n";
}
