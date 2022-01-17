#include <iostream> 
#include <string>
#include <set>
using namespace std;  

int64_t hash_(string s) { 
    int64_t hashed = 0; 
    for(size_t i = 0; i < s.size(); i++) {
        int64_t t = s[i] * 22814881337; 
        hashed += t ^ (t>>8);
    }
    return hashed;
}

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int N;
    string s; 
    set<int64_t> keys;
    cin >> N; 

    for(int i = 0; i < N; i++) {
        cin >> s; 
        int64_t key = hash_(s); 
        keys.insert(key);
    } 

    cout << keys.size() << "\n";
    return 0;
}