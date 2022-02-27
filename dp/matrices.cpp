#include <iostream>  
#include <vector>  
#include <algorithm>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int N; 
    cin >> N; 

    vector<int64_t> sizes; 
    for(int i = 0; i < N; i++) { 
        int64_t x; 
        cin >> x; 
        sizes.push_back(x);  
    } 

    vector<vector<int64_t>> dp(sizes.size(), vector<int64_t> (sizes.size())); 
    for(size_t i = 0; i < sizes.size(); i++) {
        for(size_t j = 0; (j < i + 2) && (j < sizes.size()); j++) {
            dp[i][j] = 0;  
        } 
    }   

    for(size_t i = 0; i < sizes.size(); i++) {
        for(size_t j = i + 2; j < sizes.size(); j++) {
            dp[i][j] = -1; 
        }
    } 

    /*for(size_t i = 0; i < sizes.size(); i++) {
        for(size_t j = 0; j < sizes.size(); j++) {
            cout << dp[i][j] << " "; 
        }
        cout << "\n";
    }*/

    for(size_t p = 2; p < sizes.size(); p++) {
        for(size_t i = 0; i + p < sizes.size(); i++) { 
            for(size_t k = i + 1; k < i + p; k++) { 
                int64_t x = dp[i][k] + dp[k][i + p] + sizes[i] * sizes[k] * sizes[i + p];
                if(dp[i][i + p] > x || dp[i][i + p] == -1) {
                    dp[i][i + p] = x; 
                }
            }
        }
    }  

    /*for(size_t i = 0; i < sizes.size(); i++) {
        for(size_t j = 0; j < sizes.size(); j++) {
            cout << dp[i][j] << " "; 
        }
        cout << "\n";
    }*/

    cout << dp[0][sizes.size() - 1] << "\n"; 
    return 0; 
}