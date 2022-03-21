#include <iostream> 
#include <vector>  
#include <unordered_map>

using namespace std; 

// C++ program for the above approach
using namespace std;

// Function that finds the longest
// arithmetic subsequence having the
// same absolute difference
int lenghtOfLongestAP(vector<int>& nums) {
        int n = nums.size(),res = 2,diff;
        vector<vector<int>>dp(n,vector<int>(1001,0));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                diff = nums[j]-nums[i]+500;
                dp[j][diff] = max(2,dp[i][diff]+1);
                res = max(res,dp[j][diff]);
            }
        }
        return res;
    }

// Driver Code
int main()
{
	ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n; 
    cin >> n;   
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }  
    if (n <= 2) {
        cout << 0 << "\n";
        return 0;
    } 
    cout << n - lenghtOfLongestAP(a) + 1 << "\n";
	return 0;
}
