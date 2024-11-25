#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
    // 1. Range-Based For Loop with Ordinary Array
    cout << "Ordinary Array:\n";
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    // Print the array
    for (const auto &elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Modify the array (doubling each element)
    for (auto &elem : arr)
    {
        elem *= 2;
    }

    // Print the modified array
    for (const auto &elem : arr)
    {
        cout << elem << " ";
    }
    cout << endl;

    // 2. Range-Based For Loop with vector
    cout << "\nvector:\n";
    vector<int> vec = {10, 20, 30, 40, 50};

    // Print the vector
    for (const auto &elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Modify the vector (adding 5 to each element)
    for (auto &elem : vec)
    {
        elem += 5;
    }

    // Print the modified vector
    for (const auto &elem : vec)
    {
        cout << elem << " ";
    }
    cout << endl;

    // 3. Range-Based For Loop with unordered_set
    cout << "\nunordered_set:\n";
    unordered_set<int> mySet = {1, 2, 3, 4, 5};

    // Print the unordered_set
    for (const auto &elem : mySet)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Modify the unordered_set (adding 10 to each element)
    // Note: unordered_set does not allow modification of existing elements
    // So, we will add new elements instead
    unordered_set<int> modifiedSet;
    for (const auto &elem : mySet)
    {
        modifiedSet.insert(elem + 10);
    }
    mySet = std::move(modifiedSet);

    // Print the modified unordered_set
    for (const auto &elem : mySet)
    {
        cout << elem << " ";
    }
    cout << endl;

    // 4. Range-Based For Loop with unordered_map
    cout << "\nunordered_map:\n";
    unordered_map<string, int> myMap = {
        {"apple", 3},
        {"banana", 5},
        {"cherry", 2}};

    // Print the unordered_map
    for (const auto &pair : myMap)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Modify the unordered_map (adding 10 to each value)
    for (auto &pair : myMap)
    {
        pair.second += 10;
    }

    // Print the modified unordered_map
    for (const auto &pair : myMap)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
