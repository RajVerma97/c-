#include <iostream>
using namespace std;

double findMaxAverage(int nums[], int n, int k)
{

    // Get sum for starting window
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += nums[i];

    int maxSum = sum;

    // Start sliding window
    int startIndex = 0;
    int endIndex = k;
    while (endIndex < n)
    {

        sum -= nums[startIndex]; // Remove previous element
        startIndex++;

        sum += nums[endIndex]; // Add next element
        endIndex++;

        maxSum = max(maxSum, sum); // Update max sum
    }

    // Return the average
    return (double)maxSum / k;
}

int main()
{

    int nums[6] = {1, 12, -5, -6, 50, 3};
    int k = 4;

    int n = sizeof(nums) / sizeof(nums[0]); // Get the number of elements in the array
    double ans = findMaxAverage(nums, n, k);

    cout << ans << endl;

    // Output: 12.75

    return 0;
}