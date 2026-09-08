#include <iostream>
#include <stack>
#include <string>

// Function to return the precedence of operators
int getPrecedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0; // For parenthesis
}

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to convert infix expression to postfix expression
std::string infixToPostfix(const std::string& infix) {
    std::stack<char> s;
    std::string postfix = "";

    for (char ch : infix) {
        // 1. If the character is an operand (alphanumeric), add it to output
        if (isalnum(ch)) {
            postfix += ch;
        }
        // 2. If the character is '(', push it onto the stack
        else if (ch == '(') {
            s.push(ch);
        }
        // 3. If the character is ')', pop and output until '(' is found
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) {
                s.pop(); // Remove '(' from stack
            }
        }
        // 4. If an operator is encountered
        else if (isOperator(ch)) {
            // Right-associative operator '^' needs special handling if chained,
            // but for standard left-associative (+, -, *, /):
            while (!s.empty() && getPrecedence(s.top()) >= getPrecedence(ch)) {
                // If it is the exponent operator, it associates right-to-left
                if (ch == '^' && s.top() == '^') {
                    break; 
                }
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // 5. Pop all the remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    std::string infix = "A+B*C-(D/E)";
    std::cout << "Infix Expression:   " << infix << std::endl;
    std::cout << "Postfix Expression: " << infixToPostfix(infix) << std::endl;
    return 0;
}
