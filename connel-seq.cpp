#include <iostream>
using namespace std;

class NumberGenerator
{
protected:
    virtual bool checkNumber(int num, bool isOdd)
    {
        return isOdd ? (num % 2 != 0) : (num % 2 == 0);
    }
};

class ConnellSequence : public NumberGenerator
{
private:
    int n;

public:
    ConnellSequence(int terms) : n(terms) {}

    friend void generateSequence(ConnellSequence &cs);

    bool checkNumber(int num, bool isOdd) override
    {
        return NumberGenerator::checkNumber(num, isOdd);
    }
};

void generateSequence(ConnellSequence &cs)
{
    int count = 0;          // Numbers printed
    int groupSize = 1;      // Current group size
    bool isOddGroup = true; // Start with odd group
    int nextNum = 1;        // Next number to consider

    while (count < cs.n)
    {
        int groupCount = 0; // Count in current group

        // Keep looking for numbers until we fill current group
        while (groupCount < groupSize && count < cs.n)
        {
            if (cs.checkNumber(nextNum, isOddGroup))
            {
                cout << nextNum << " ";
                groupCount++;
                count++;
            }
            nextNum++;
        }

        // Switch group type and increase size
        isOddGroup = !isOddGroup;
        groupSize++;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    ConnellSequence sequence(n);
    generateSequence(sequence);

    return 0;
}