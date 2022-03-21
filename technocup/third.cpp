#include <iostream> 
#include <vector> 
#include <map>  
#include <climits> 
#include <string> 
#include <algorithm> 
#include <queue>

using namespace std;  

map<int64_t, int64_t> p;  

bool f(int64_t s) {
    if(s == 0) {
        return 0;  
    } 

    if(p[s]) {
        p[s]--;
        return 1; // we find this element in tree 
    } 

    return f(s/2)&&f(s - s/2); 
} 

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t; 
    cin >> t; 
    while(t--) { 
        p.clear();
        int n; 
        cin >> n;   
        int64_t s = 0;
        for(int i = 0; i < n; i++) {
            int64_t x; 
            cin >> x; 
            s += x; 
            p[x]++; 
        } 

        cout << (f(s) ? "YES" : "NO") << "\n"; 
    }
    return 0;
}