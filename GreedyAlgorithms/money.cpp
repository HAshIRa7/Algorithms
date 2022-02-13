#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std; 

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL);
    cout.tie(NULL); 

    int n; 
    cin >> n; 

    vector<int32_t> coins(n); 
    for(int i = 0; i < n; i++) {
        cin >> coins[i]; 
    }  
    sort(coins.begin(), coins.end());  
    int32_t sum = 0;
    for(int i = 0; i < n ; i++) {
        if(sum + 1 >= coins[i]) {
            sum += coins[i]; 
        } 
        else {
            break;
        }
    } 
    cout << sum + 1 << "\n";
    return 0;
}