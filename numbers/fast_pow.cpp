#include <iostream>   
#include <climits>
#define ll int64_t 

using namespace std;  

ll fast_pow(ll x, ll p, ll m) { 
    if(p == 0) {
        return 1; 
    }
    if(p & 1ll) {
        return (x % m) * (fast_pow(x, p - 1, m) % m) % m;
    } else {
        return (fast_pow(x, p / 2, m) % m) * (fast_pow(x, p / 2, m) % m) % m;  
    }
} 

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    ll x, p, m; 
    cin >> x >> p >> m;   
    //cout << INT64_MAX << "\n";
    cout << fast_pow(x, p, m) << "\n";
}