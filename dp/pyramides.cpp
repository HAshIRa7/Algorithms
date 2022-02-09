#include <iostream> 
#include <vector>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n; 
    cin >> n; 

    vector<vector<uint32_t>> dp(n + 1, vector<uint32_t>(n + 1));     
    for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j <= i; j++){
            dp[i][j] = 0;
            if(i == j) {
                dp[i][j] = 1; 
            }
        }
    }  

    for(int i = 0; i < n + 1; i++) {
        dp[0][i] = 0;
    }

    for(int i = 0; i < n + 1; i++) { 
        for(int j = i + 1; j < n + 1; j++) { 
            for(int k = i - 1; k >= 0; k--) {
                dp[i][j] += dp[k][j - i];
            }
        }
    } 

    /*for(int i = 0; i < n + 1; i++) {
        for(int j = 0; j < n + 1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }*/

    uint32_t res = 0; 
    for(int i = 0; i < n + 1; i++) {
        res += dp[i][n];
    } 

    cout << res  << "\n";
    return 0;
}