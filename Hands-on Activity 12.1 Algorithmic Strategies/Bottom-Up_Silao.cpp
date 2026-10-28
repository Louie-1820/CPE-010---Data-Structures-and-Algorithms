#include <iostream>
#include <vector>
#include <algorithm> 

int getMinSteps(int n) 
{
    std::vector<int> dp(n + 1);
    
    dp[1] = 0; // Trivial case

    for (int i = 2; i <= n; i++) 
    {
        dp[i] = 1 + dp[i - 1];
        
        if (i % 2 == 0) {
            dp[i] = std::min(dp[i], 1 + dp[i / 2]);
        }
        
        if (i % 3 == 0) {
            dp[i] = std::min(dp[i], 1 + dp[i / 3]);
        }
    }
    
    return dp[n];
}

int main() 
{
    int n = 100;

    std::cout << "======== Bottom-Up Dynamic Programming Implementation ========" << std::endl;

    std::cout << "Minimum steps for n = " << n << " is: " << getMinSteps(n) << std::endl;
    
    std::cout << "==============================================================" << std::endl;

    return 0;
}
