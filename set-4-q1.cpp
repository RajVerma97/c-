#include <iostream>
using namespace std;

int x = 10;
void fun()
{
    int x = 2;
    {
        int x = 1;
        cout << ::x << endl;//10 
    }
}
// If Scope Resolution Operator is placed before a variable name
// then the global variable is referenced. So if we remove the following line from the above program then it will fail in compilation.

int main()
{
    fun();
    return 0;
}
