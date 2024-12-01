#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

// Function to evaluate a postfix expression
int evaluatePostfix(const string& expression) {
    stack<int> s;
    for (char ch : expression) {
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert char to int
        } else {
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
                case '^': s.push(pow(operand1, operand2)); break;
            }
        }
    }
    return s.top();
}

// Function to evaluate a prefix expression
int evaluatePrefix(const string& expression) {
    stack<int> s;
    for (auto it = expression.rbegin(); it != expression.rend(); ++it) {
        char ch = *it;
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert char to int
        } else {
            int operand1 = s.top(); s.pop();
            int operand2 = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(operand1 + operand2); break;
                case '-': s.push(operand1 - operand2); break;
                case '*': s.push(operand1 * operand2); break;
                case '/': s.push(operand1 / operand2); break;
                case '^': s.push(pow(operand1, operand2)); break;
            }
        }
    }
    return s.top();
}

int main() {
    string postfixExp = "53+82-*"; // Example postfix expression
    string prefixExp = "-+53*82";  // Example prefix expression

    cout << "Postfix Evaluation of \"" << postfixExp << "\": " << evaluatePostfix(postfixExp) << endl;
    cout << "Prefix Evaluation of \"" << prefixExp << "\": " << evaluatePrefix(prefixExp) << endl;

    return 0;
}