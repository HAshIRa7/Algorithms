#include <iostream> 
#include <vector>  
#include <string> 
#include <algorithm>

using namespace std;  

void Print(vector<bool>& dp) {
    for(size_t i = 0; i < dp.size(); i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
}

int main() { 
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    string pattern, source; 
    //pattern = "*"; 
    //source = "";

    cin >> pattern >> source;
    //vector<vector<bool>> dp(pattern.size() + 1, vector<bool>(source.size() + 1));     
    vector<bool> dp(source.size() + 1, false); 
    vector<bool> helper(source.size() + 1, false); 
    dp[0] = 1; 
    //dp[0][0] = 1;  
    if(source.size() == 0 && pattern.size() == 0) {
        cout << "YES" << "\n";
        return 0;
    } 
    if(source.size() == 0) {
        for(size_t i = 0; i < pattern.size(); i++) {
            if(pattern[i] != '*') {
                cout << "NO" << "\n"; 
                return 0; 
            }
        }
        cout << "YES" << "\n"; 
        return 0;
    }

    for(size_t i = 0; i < pattern.size(); i++) {
        for(size_t j = 0; j < source.size(); j++) {
            if(pattern[i] == '*') {
                //dp[i + 1][0] = dp[i][0]; 
                helper[0] = dp[0]; 
                //dp[i + 1][j + 1] = (dp[i][j + 1] || dp[i + 1][j] || dp[i][j]);  
                helper[j + 1] = (dp[j + 1] || helper[j] || dp[j]); 
            }  else {
                //dp[i + 1][j + 1] = dp[i][j] && (pattern[i] == source[j] || pattern[i] == '?'); 
                helper[j + 1] = dp[j] && (pattern[i] == source[j] || pattern[i] == '?');
            }
        }  
        dp = helper; 
        helper.assign(source.size() + 1, false);  
        //helper = vector<bool>(source.size() + 1, false);
    } 
    //Print(dp);
    //cout << ((dp[pattern.size()][source.size()]) ? "YES" : "NO") << "\n"; 
    cout << (dp[source.size()] ? "YES\n" : "NO\n");
}
