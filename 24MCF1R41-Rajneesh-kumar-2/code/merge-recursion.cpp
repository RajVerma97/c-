#include <iostream>
using namespace std;

void mergeArrays(int arr1[], int size1, int arr2[], int size2, int merged[], int index1 = 0, int index2 = 0, int indexMerged = 0)
{
    if (index1 == size1)
    {
        while (index2 < size2)
        {
            merged[indexMerged++] = arr2[index2++];
        }
        return;
    }
    if (index2 == size2)
    {
        while (index1 < size1)
        {
            merged[indexMerged++] = arr1[index1++];
        }
        return;
    }

    if (arr1[index1] < arr2[index2])
    {
        merged[indexMerged] = arr1[index1];
        mergeArrays(arr1, size1, arr2, size2, merged, index1 + 1, index2, indexMerged + 1);
    }
    else
    {
        merged[indexMerged] = arr2[index2];
        mergeArrays(arr1, size1, arr2, size2, merged, index1, index2 + 1, indexMerged + 1);
    }
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int merged[size1 + size2];

    mergeArrays(arr1, size1, arr2, size2, merged);

    cout << "Merged sorted array: ";
    for (int i = 0; i < size1 + size2; i++)
    {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}