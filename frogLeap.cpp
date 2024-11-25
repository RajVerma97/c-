#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the number of ways to reach the top of n steps
int countWays(int n)
{
    // Base casesp
    if (n == 0)
        return 1; // One way to stay at the ground
    if (n == 1)
        return 1; // One way to reach step 1
    if (n == 2)
        return 2; // Two ways to reach step 2

    // Create a dp array to store the number of ways for each step
    int dp[100];
    dp[0] = 1; // One way to stay at ground level
    dp[1] = 1; // One way to reach step 1
    dp[2] = 2; // Two ways to reach step 2

    // Fill the dp array for steps 3 to n
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n]; // Return the total ways to reach step n
}

int main()
{
    int n = 10; // You can change this to any number of steps
    cout << "Total number of ways to reach the top of " << n << " steps: " << countWays(n) << endl;
    return 0;
}