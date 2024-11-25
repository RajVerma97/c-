#include <iostream>
using namespace std;

template <class T>

T findSum(T arr[], int n)
{

    T sum = 0;

    for (int i = 0; i < n; i++)
    {

        sum += arr[i];
    }

    return sum;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    cout << findSum<int>(arr, 5) << endl;

    float arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << findSum<float>(arr2, 5) << endl;
    return 0;
}