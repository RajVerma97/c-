#include <iostream>
#include <vector>

using namespace std;

int fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int fib_top_down(int n, vector<int> &memo)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (memo[n] != -1)
        return memo[n]; // Return the result if already computed

    memo[n] = fib_top_down(n - 1, memo) + fib_top_down(n - 2, memo); // Store the computed result
    return memo[n];
}

int fib_bottom_up(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    vector<int> memo(n + 1);

    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}

int main()
{
    int n = 6;
    int result;

    // Naive recursive approach
    result = fib(n);
    cout << "Fibonacci (Recursive) of " << n << " is " << result << endl;

    // Bottom-up dynamic programming approach
    result = fib_bottom_up(n);
    cout << "Fibonacci (Bottom-Up) of " << n << " is " << result << endl;

    // Top-down dynamic programming approach with memoization
    vector<int> memo(n + 1, -1); // Initialize memoization array with -1
    result = fib_top_down(n, memo);
    cout << "Fibonacci (Top-Down) of " << n << " is " << result << endl;

    return 0;
}




/*

ynamic programming (DP), “bottom-up” and “top-down” are two approaches used to solve problems by breaking them down into smaller subproblems and solving them systematically. Both approaches aim to avoid redundant calculations by storing the results of subproblems, but they differ in how they achieve this.

Top-Down Approach (with Memoization)

	•	Concept: The top-down approach starts with the original problem and breaks it down into smaller subproblems. It solves each subproblem recursively, storing the results (also called “memoizing”) to avoid recalculating them. If a subproblem has already been solved, the stored result is used directly.
	•	How it works:
	•	You write a recursive function to solve the problem.
	•	Before computing the result of a subproblem, you check if the result is already available in a “memo” (a storage, typically an array or hash table).
	•	If it is, you return the stored result; if not, you compute the result, store it in the memo, and then return it.
	•	Example: Calculating the Fibonacci sequence.
	•	Instead of recalculating the Fibonacci number for fib(n-1) and fib(n-2) multiple times, you store the results of fib(n-1) and fib(n-2) after they are computed once. Subsequent calls use these stored results, reducing the number of recursive calls.
	•	Advantages: Easy to implement using recursion, and intuitive for many problems.
	•	Disadvantages: Recursive calls can lead to deep call stacks, which might cause stack overflow for large inputs.

Bottom-Up Approach (Iterative)

	•	Concept: The bottom-up approach starts by solving the smallest subproblems first and then uses their solutions to build up the solution to the original problem. It eliminates the need for recursion and builds the solution iteratively.
	•	How it works:
	•	You identify the base cases (smallest subproblems) and solve them first.
	•	You then iteratively compute the results of larger subproblems using the solutions of smaller subproblems that have already been computed.
	•	The final solution to the original problem is obtained after solving all subproblems.
	•	Example: Calculating the Fibonacci sequence.
	•	You start by solving for fib(0) and fib(1).
	•	Then, using these, you compute fib(2), followed by fib(3), and so on, until you reach fib(n).
	•	Advantages: Efficient in terms of space (can often reduce space complexity) and avoids issues with recursion depth.
	•	Disadvantages: Might be less intuitive for some problems compared to the top-down approach.

Summary:

	•	Top-Down (Memoization):
	•	Recursive, starts with the original problem and works down to the base cases.
	•	Uses a memo to store results of subproblems.
	•	Suited for problems with overlapping subproblems where recursion is natural.
	•	Bottom-Up (Tabulation):
	•	Iterative, starts with the base cases and builds up to the solution of the original problem.
	•	Often uses a table (array) to store results of subproblems.
	•	More efficient in terms of space and avoids deep recursion.

Both approaches are used in dynamic programming to ensure that each subproblem is solved only once, leading to optimized solutions for problems that exhibit overlapping subproblems and optimal substructure properties.

*/