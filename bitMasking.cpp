#include <iostream>
using namespace std;

int main()
{

    unsigned int num = 42;
    // Example 4: Checking the 4th bit (0-indexed)

    unsigned int mask = 1 << 4;
    bool isSet = num & mask;

    cout << "is 4th bit set: " << (isSet ? "Yes" : "No") << endl;

    // Example 5: Setting the 2th bit (0-indexed)
    mask = 1 << 2;
    num = num | mask;

    cout << "set 2th bit: " << num << endl;

    // Example Clearing the 3th bit (0-indexed)
    mask = ~(1 << 3);
    num = num & mask;

    cout << "clear 3th bit: " << num << endl;

    // Example Toggling the 1th bit (0-indexed)

    mask = 1 << 1;
    num=num^mask;
    cout<<"toggle 1th bit: "<<num<<endl;

    return 0;
}