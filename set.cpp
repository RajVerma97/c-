#include <iostream>
#include <set>

using namespace std;

// Function to print the elements of a set
void printSet(const set<int> &s)
{
    cout << "Set elements: ";
    for (const auto &elem : s)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    // Create a set and insert elements
    set<int> mySet = {10, 20, 30, 40, 50};

    // Display the set
    printSet(mySet);

    // Insert elements
    mySet.insert(60); // Insert a new element
    mySet.insert(20); // Inserting a duplicate element (ignored)
    cout << "After inserting 60 and trying to insert 20 again:" << endl;
    printSet(mySet);

    // Find elements
    auto it = mySet.find(30); // Find the element 30
    if (it != mySet.end())
    {
        cout << "Element 30 found in the set." << endl;
    }
    else
    {
        cout << "Element 30 not found in the set." << endl;
    }

    // Count occurrences of an element
    cout << "Count of 40: " << mySet.count(40) << endl;
    cout << "Count of 70: " << mySet.count(70) << endl;

    // Erase an element
    mySet.erase(20); // Erase the element 20
    cout << "After erasing 20:" << endl;
    printSet(mySet);

    // Check if the set is empty
    cout << "Is the set empty? " << (mySet.empty() ? "Yes" : "No") << endl;

    // Get the size of the set
    cout << "Size of the set: " << mySet.size() << endl;

    // Clear all elements
    mySet.clear();
    cout << "After clearing the set:" << endl;
    printSet(mySet);

    // Check if the set is empty after clearing
    cout << "Is the set empty after clearing? " << (mySet.empty() ? "Yes" : "No") << endl;

    return 0;
}