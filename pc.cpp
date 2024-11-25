#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

class PCNFGenerator
{
private:
    string expression;
    vector<char> variables;
    vector<vector<bool>> truthTable;
    vector<bool> results;

    bool isOperator(const string &c)
    {
        return (c == "∧" || c == "∨" || c == "¬" || c == "→" || c == "↔" || c == "^");
    }

    bool evaluateRecursive(const string &expr, const vector<bool> &values)
    {
        if (expr.length() == 1)
        {
            if (isalpha(expr[0]))
            {
                int idx = find(variables.begin(), variables.end(), expr[0]) - variables.begin();
                return values[idx];
            }
            return expr[0] == '1';
        }

        int parenthesesCount = 0;
        int mainOpIndex = -1;

        for (int i = expr.length() - 1; i >= 0; i--)
        {
            if (expr[i] == ')')
                parenthesesCount++;
            else if (expr[i] == '(')
                parenthesesCount--;
            else if (parenthesesCount == 0 && isOperator(string(1, expr[i])))
            {
                mainOpIndex = i;
                break;
            }
        }

        if (mainOpIndex == -1)
        {
            return evaluateRecursive(expr.substr(1, expr.length() - 2), values);
        }

        string leftExpr = expr.substr(0, mainOpIndex);
        string rightExpr = expr.substr(mainOpIndex + 1);
        string op = string(1, expr[mainOpIndex]);

        if (op == "¬")
        {
            return !evaluateRecursive(rightExpr, values);
        }

        bool leftResult = evaluateRecursive(leftExpr, values);
        bool rightResult = evaluateRecursive(rightExpr, values);

        if (op == "∧" || op == "^")
            return leftResult && rightResult;
        if (op == "∨")
            return leftResult || rightResult;
        if (op == "→")
            return !leftResult || rightResult;
        if (op == "↔")
            return leftResult == rightResult;

        return false;
    }

    void generateTruthTableRecursive(int varIndex, vector<bool> &currentRow)
    {
        if (varIndex == variables.size())
        {
            bool result = evaluateRecursive(expression, currentRow);
            truthTable.push_back(currentRow);
            results.push_back(result);
            return;
        }

        for (int i = 0; i < 2; i++)
        {
            currentRow.push_back(i == 1);
            generateTruthTableRecursive(varIndex + 1, currentRow);
            currentRow.pop_back();
        }
    }

    string generatePCNFClause(const vector<bool> &row)
    {
        string clause = "(";
        for (size_t i = 0; i < variables.size(); i++)
        {
            if (i > 0)
                clause += " ∨ ";
            if (!row[i])
                clause += variables[i];
            else
                clause += "¬" + string(1, variables[i]);
        }
        clause += ")";
        return clause;
    }

public:
    void generatePCNF(const string &expr)
    {
        expression = expr;
        variables.clear();
        truthTable.clear();
        results.clear();

        for (char c : expr)
        {
            if (isalpha(c) && find(variables.begin(), variables.end(), c) == variables.end())
            {
                variables.push_back(c);
            }
        }
        sort(variables.begin(), variables.end());

        vector<bool> currentRow;
        generateTruthTableRecursive(0, currentRow);

        cout << "\nTruth Table for: " << expression << endl;
        cout << string(50, '-') << endl;

        for (char var : variables)
        {
            cout << var << " | ";
        }
        cout << "Result" << endl;
        cout << string(50, '-') << endl;

        for (size_t i = 0; i < truthTable.size(); i++)
        {
            for (bool val : truthTable[i])
            {
                cout << (val ? "1" : "0") << " | ";
            }
            cout << (results[i] ? "1" : "0") << endl;
        }
        cout << string(50, '-') << endl;

        cout << "\nPCNF: ";
        bool first = true;
        for (size_t i = 0; i < results.size(); i++)
        {
            if (!results[i])
            {
                if (!first)
                    cout << " ∧ ";
                cout << generatePCNFClause(truthTable[i]);
                first = false;
            }
        }
        if (first)
            cout << "1 (Tautology)";
        cout << endl;
    }
};

int main()
{
    PCNFGenerator generator;
    string expr;

    cout << "PCNF Generator" << endl;
    cout << "Available operators:" << endl;
    cout << "∧ (AND), ∨ (OR), ¬ (NOT), → (IMPLIES), ↔ (EQUIVALENT), ^ (AND)" << endl;
    cout << "\nExample expressions:" << endl;
    cout << "p ∧ q" << endl;
    cout << "p → q" << endl;
    cout << "(p ∧ q) ∨ r" << endl;

    while (true)
    {
        cout << "\nEnter logical expression (or 'quit' to exit): ";
        getline(cin, expr);

        if (expr == "quit")
            break;

        generator.generatePCNF(expr);
    }

    return 0;
}