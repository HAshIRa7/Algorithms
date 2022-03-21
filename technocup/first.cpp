#include<iostream> 
#include<vector> 
#include <map>  
#include <climits>

using namespace std;  

int f(vector<int>& a) {
    int max1 = INT_MIN; 
    int max2 = INT_MIN;
    for(size_t i = 0; i < a.size(); i++) {
        if(a[i] > max1) {
            if(max1 != INT_MIN) {
                max2 = max1; 
            } 
            max1 = a[i];
        } else if(a[i] >= max2) {
            max2 = a[i]; 
        }
    } 

    return max1 + max2;
}

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t; 
    cin >> t; 
    while(t--) {
        int n;
        cin >> n; 
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i]; 
        } 
        cout << f(a) << "\n";
    }
    return 0;
}