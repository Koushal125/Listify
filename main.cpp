#include <iostream>
#include <iomanip>
#include <unordered_map>
using namespace std;

unordered_map<int, double> memo; // Memoization table to store calculated values

double print(int x)
{
    if (x == 0) return 0;
    if (x == 1) return 1;

    // Check if the result is already calculated and stored in the memoization table
    if (memo.find(x) != memo.end()) {
        return memo[x];
    }

    // If not calculated, calculate the value and store it in the memoization table
    double result = ((0.5 * print(x - 1)) + print(x - 2));
    memo[x] = result; // Store the result in the memoization table
    return result;
}

int main()
{
    double n = print(1000);
    cout << fixed << setprecision(10);
    cout << n << endl;
    return 0;
}
