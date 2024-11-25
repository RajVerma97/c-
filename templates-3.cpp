#include <iostream>
using namespace std;

template <class T, class U>

// The typename std::common_type<T, U>::type is a type
// trait in C++ that is used to determine
// the common type of two different types T and U (such as dur
// ing arithmetic operations, comparisons, or when working with multiple
// types in a template function). It provides a type that can safely store
// the result of an operation between T and U, ensuring that the result
// type is appropriate for both types.

typename std::common_type<T, U>::type findMax(T a, U b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << findMax<int, int>(10, 20) << endl;      // int, int
    cout << findMax<int, double>(10, 20.5) << endl; // int, double
    return 0;
}