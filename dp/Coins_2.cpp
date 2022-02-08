#include <vector> 
#include <iostream> 

using namespace std; 
class Solution {
public:
    int change(int amount, vector<int>& coins) { 
        vector<int32_t> dp(amount + 1, 0); 
        dp[0] = 1; 
        for (size_t k = 0; k < coins.size(); k++) {
            for(int i = 1; i < amount + 1; i++) {
                if(i >= coins[k]) { 
                    dp[i] += dp[i - coins[k]]; 
                }
            }
        }
        return dp[amount];
    }
}; 

int main() { 
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int amount;
    cin >> amount;  
    int k;
    cin >> k; 

    vector<int> coins(k); 
    for(int i = 0; i < k; i++) {
        cin >> coins[i];
    } 
    Solution it; 
    cout << it.change(amount, coins) << "\n";
    return 0;
}