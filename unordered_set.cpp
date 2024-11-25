#include <iostream>
#include <unordered_set>

using namespace std;

// print the unordered set
void printUnorderedSet(unordered_set<int> s)
{
    // loop through the unordered set
    for (auto it = s.begin(); it != s.end(); it++)
    {
        // print the value of the current element
        cout << *it << " ";
    }
    // print a newline
    cout << endl;
}

int main()
{
    // create an unordered set
    unordered_set<int> s;

    // insert elements into the unordered set
    s.insert(4);
    s.insert(5);
    s.insert(8);
    s.insert(1);
    s.insert(2);
    s.insert(9);

    // print the unordered set
    printUnorderedSet(s);

    // print a newline
    cout << endl;

    // check if 5 is present in the unordered set
    s.count(5) == 1 ? cout << "5 is present" : cout << "5 is not present";

    // print the unordered set again
    printUnorderedSet(s);

    // check if 5 is present in the unordered set
    if (s.find(5) != s.end())
    {
        cout << "5 is present in the unordered set" << endl;
    }
    else
    {
        cout << "5 is not present in the unordered set" << endl;
    }

    // erase 9 from the unordered set
    s.erase(9);

    // print the unordered set again
    printUnorderedSet(s);

    // check if the unordered set is empty
    if (s.empty())
    {
        cout << "unordered set is empty" << endl;
    }
    else
    {
        // print the size of the unordered set
        cout << s.size() << endl;
    }

    // clear the unordered set
    s.clear();

    // print the unordered set again
    printUnorderedSet(s);
    

    return 0;
}

