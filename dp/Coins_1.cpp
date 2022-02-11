#include <iostream> 
#include <vector> 
#include <limits> 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {  
        vector<int32_t> dp(amount + 1, INT32_MAX - 1);
        dp[0] = 0;
        for(int  i = 0; i < amount + 1; i++) {
            for(size_t k = 0; k < coins.size(); k++) {
                if(i >= coins[k]) { 
                    if(dp[i] > dp[i - coins[k]] + 1) {
                        dp[i] = dp[i - coins[k]] + 1; 
                    }
                }
            }
        } 
        if (dp[amount] == INT32_MAX - 1) {
            return -1; 
        } else {
            return dp[amount];
        }
    }
}; 

int main() 