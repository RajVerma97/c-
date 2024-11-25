#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

bool isOperand(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

string infixToPostfix(string infix)
{
    string postfix = "";
    stack<char> st;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(ch))
        {
            postfix += ch;
        }
        // If the character is an opening parenthesis, push it to the stack
        else if (ch == '(')
        {
            st.push('(');
        }
        // If the character is a closing parenthesis, pop until '(' is found
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // pop the '('
        }
        else
        {
            // ch is an operator, pop from the stack to postfix based on precedence
            while (!st.empty() && precedence(ch) <= precedence(st.top()))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop all the operators left in the stack
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Function to convert postfix expression to infix expression
string postfixToInfix(string postfix)
{
    stack<string> st;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        // If the character is an operand, push it to the stack
        if (isOperand(ch))
        {
            string operand(1, ch); // Convert char to string
            st.push(operand);
        }
        // If the character is an operator, pop two elements from the stack
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string subExpr = "(" + op2 + ch + op1 + ")";
            st.push(subExpr);
        }
    }

    // The final element in the stack is the full infix expression
    return st.top();
}

string infixToPrefix(string infix)
{
    // Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Swap '(' with ')' and vice versa
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Get postfix from the modified infix
    string postfix = infixToPostfix(infix);

    // Reverse the postfix expression to get the prefix expression
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

// Function to convert prefix expression to infix expression
string prefixToInfix(string prefix)
{
    stack<string> st;

    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        // If the character is an operand, push it onto the stack
        if (isOperand(ch))
        {
            string operand(1, ch); // Convert char to string
            st.push(operand);
        }
        // If the character is an operator, pop two elements from the stack
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string subExpr = "(" + op1 + ch + op2 + ")";
            st.push(subExpr);
        }
    }

    // The final element in the stack is the full infix expression
    return st.top();
}

string postfixToPrefix(string postfix)
{
    stack<string> st;

    // Traverse the postfix expression from left to right
    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        // If the character is an operand, push it to the stack
        if (isOperand(ch))
        {
            string operand(1, ch); // Convert char to string
            st.push(operand);
        }
        // If the character is an operator, pop two operands from the stack
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            // Form the prefix expression
            string prefix = ch + op2 + op1;
            // Push the resulting prefix expression back to the stack
            st.push(prefix);
        }
    }

    // The final element in the stack is the full prefix expression
    return st.top();
}

// Function to convert prefix expression to postfix expression
string prefixToPostfix(string prefix)
{
    stack<string> st;

    // Traverse the prefix expression from right to left
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        // If the character is an operand, push it to the stack
        if (isOperand(ch))
        {
            string operand(1, ch); // Convert char to string
            st.push(operand);
        }
        // If the character is an operator, pop two operands from the stack
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            // Form the postfix expression
            string postfix = op1 + op2 + ch;
            // Push the resulting postfix expression back to the stack
            st.push(postfix);
        }
    }

    // The final element in the stack is the full postfix expression
    return st.top();
}

int main()
{
    string infix = "A+B*C";

    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
    cout << "Prefix Expression: " << infixToPrefix(infix) << endl;

    string postfix = "ABC*+D-";
    cout << "Postfix Expression: " << postfix << endl;
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    cout << "Prefix Expression: " << postfixToPrefix(postfix) << endl;

    string prefix = "*+AB-CD";
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Infix Expression: " << prefixToInfix(prefix) << endl;
    cout << "Postfix Expression: " << prefixToPostfix(prefix) << endl;

    return 0;
}