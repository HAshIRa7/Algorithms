#include <iostream> 
#include <vector> 

using namespace std; 

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    string n; 
    cin >> n; 

    vector<vector<uint32_t>> dp(n.size(), vector<uint32_t> (n.size())); 
    for(size_t i = 0; i < n.size(); i++) {
        for(size_t j = 0; j <= i; j++) {
            if(i == j) {
                dp[i][j] = 1; 
            } else {
                dp[i][j] = 0;
            }
        }
    } 

    for(size_t k = 1; k < n.size(); k++) {
        for(size_t j = k; j < n.size(); j++) { 
            //example aca 
            // you should understand that  d[i + 1][j - 1] <= d[i + 1][j] && d[i + 1][j - 1] <= d[i][j - 1] 
            // and they contains d[i + 1][j - 1] twice, but we should count this twice if n[i] = n[j] and count n[i]n[j] 
            // if not  we should sub dp[i + 1][j - 1]
            dp[j - k][j] = dp[j - k + 1][j] + dp[j - k][j - 1] + 
            (n[j - k] == n[j] ? 1 : (-1) * dp[j - k + 1][j - 1]); 
        } 
    } 
    cout << dp[0][n.size() - 1] << "\n";
    return 0;
}
