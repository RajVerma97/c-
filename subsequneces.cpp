#include <iostream>
using namespace std;

void generateSubsequences(string str, string current, int index)
{
    if (index == str.length())
    {
        cout << current << endl;
        return;
    }

    generateSubsequences(str, current + str[index], index + 1);
    generateSubsequences(str, current, index + 1);
}

int main()
{
    string input;
    cout << "Enter a string: ";
    cin >> input;

    cout << "Subsequences of the string are: " << endl;
    generateSubsequences(input, "", 0);

    return 0;
}