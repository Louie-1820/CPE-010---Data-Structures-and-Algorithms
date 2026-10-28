#include <iostream>
#include <vector>
#include <algorithm> 

const int max = 1000;
std::vector<int> memo(max, -1); 

int getMinSteps(int n)
{
    if (n == 1) return 0; // Base case
    
    if (memo[n] != -1) return memo[n]; // We have solved it already :)
    
    int r = 1 + getMinSteps(n - 1); // '-1' step. 'r' will contain the optimal answer finally
    
    if (n % 2 == 0) {
        r = std::min(r, 1 + getMinSteps(n / 2)); // '/2' step
    }
    
    if (n % 3 == 0) {
        r = std::min(r, 1 + getMinSteps(n / 3)); // '/3' step 
    }
    
    memo[n] = r; // Save the result. If you forget this step, then it's same as plain recursion.
    return r;
}

int main()
{
    int n = 100;
    
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    std::cout << "======== Memoization Implementation ========" << std::endl;

    std::cout << "Minimum steps for n = " << n << " is: " << getMinSteps(n) << std::endl;

    std::cout << "============================================" << std::endl;

    return 0;
}