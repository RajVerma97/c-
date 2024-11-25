#include <iostream>
#include <vector>
#include <string>

using namespace std;

class PropositionEvaluator
{
private:
    string expression;
    vector<char> variables;
    vector<vector<bool>> truthTable;
    vector<bool> results;

    // Check if a string is an operator
    bool isOperator(const string &op)
    {
        return op == "AND" || op == "OR" || op == "NOT" || op == "->" || op == "^" || op == "∨" || op == "||";
    }

    // Evaluate the expression based on current truth values
    bool evaluateExpression(const vector<bool> &values)
    {
        bool p = values[0]; // p
        bool q = values[1]; // q

        // Handle AND operator (p ∧ q)
        if (expression == "p^q" || expression == "p AND q" || expression == "p ∧ q")
        {
            return p && q; // Logical AND
        }
        // Handle implication (p -> q)
        else if (expression == "p->q" || expression == "p → q")
        {
            return !p || q; // Logical implication
        }
        // Handle OR operator (p ∨ q)
        else if (expression == "p OR q" || expression == "p ∨ q" || expression == "p || q")
        {
            return p || q; // Logical OR
        }
        return false; // Default case
    }

    // Generate the truth table recursively
    void generateTruthTable(int index, vector<bool> &currentRow)
    {
        if (index == variables.size())
        {
            bool result = evaluateExpression(currentRow);
            truthTable.push_back(currentRow);
            results.push_back(result);
            return;
        }

        // Assign both possible truth values for each variable
        for (int i = 0; i < 2; i++)
        {
            currentRow.push_back(i == 1);
            generateTruthTable(index + 1, currentRow);
            currentRow.pop_back();
        }
    }

public:
    // Initialize and generate the truth table for the expression
    void evaluate(const string &expr)
    {
        expression = expr;
        variables = {'p', 'q'}; // Assuming p and q for simplicity

        vector<bool> currentRow;
        generateTruthTable(0, currentRow);

        // Display the truth table
        cout << "\nTruth Table for: " << expression << endl;
        cout << "-----------------------" << endl;
        for (char var : variables)
            cout << var << " | ";
        cout << "Result" << endl;
        cout << "-----------------------" << endl;

        for (size_t i = 0; i < truthTable.size(); i++)
        {
            for (bool val : truthTable[i])
                cout << (val ? "T" : "F") << " | ";
            cout << (results[i] ? "T" : "F") << endl;
        }
    }
};

int main()
{
    PropositionEvaluator evaluator;
    string expr;

    cout << "Enter the logical expression (e.g., 'p -> q' or 'p^q'): ";
    getline(cin, expr);

    evaluator.evaluate(expr);
    return 0;
}