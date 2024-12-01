// Evaluation of Postfix
#include <iostream>
#include <stack>
#include <string>
#include <math.h>

using namespace std;

double evaluatePostfix(const string& expression) {
    stack<double> stack;
    int operandCount = 0;

    for (char c : expression) {
         
        // When you subtract the ASCII value
        // of '0' (which is 48) from the ASCII value
        // of any digit character, you get the
        // integer value of that digit.

        if (isdigit(c)) {
            stack.push(c - '0');       
            operandCount++;
        }
        
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            // Check if there are enough operands on the stack
            if (operandCount < 2) {
                cout << "Error: Invalid postfix expression" << endl;
                exit(1);
            }

            // Perform the operation and push the result onto the stack
            double result = stack.top();
            stack.pop();
            operandCount--;

            while (operandCount > 0) {
                double operand = stack.top();
                stack.pop();
                operandCount--;

                switch (c) {
                    case '+':
                        result += operand;
                        break;
                    case '-':
                        result -= operand;
                        break;
                    case '*':
                        result *= operand;
                        break;
                    case '/':
                        if (operand == 0) {
                            cout << "Error: Division by zero" << endl;
                            exit(1);
                        }
                        result /= operand;
                        break;
                    case '^':
                        result = pow(result, operand);
                        break;
                }
            }

            stack.push(result);
            operandCount = 1;
        }
    }

    if (stack.size() != 1) {
        cout << "Error: Invalid postfix expression" << endl;
        exit(1);
    }

    return stack.top();
}

int main() {
    string expression;
    cout << "Enter a postfix notation expression: ";
    cin >> expression;

    double result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;

    return 0;
}