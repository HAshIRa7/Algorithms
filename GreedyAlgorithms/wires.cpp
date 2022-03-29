#include <iostream> 
#include <vector>  
#include <climits>

using namespace std;   

int search(int l, int r, vector<int>& v, int k) { 
    if(l >= r) {
        return r; 
    }
    int mid = r - (r - l) / 2; 
    int res = 0; 
    for(size_t i = 0; i < v.size(); i++) {
        res += (v[i] / mid); 
    } 
    if(res >= k) {
        return search(mid, r, v, k);  
    } else {
        return search(l, mid - 1, v, k);
    }
}

int main() { 
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    int n, k; 
    cin >> n >> k; 
    vector<int> wires; 
    int min = INT_MAX; 
    int max = INT_MIN;  
    for(int i = 0; i < n; i++) {
        int x; 
        cin >> x;  
        if(x < min) {
            min = x; 
        }
        if(x > max) {
            max = x; 
        }
        wires.push_back(x);   
    } 

    cout << search(min, max, wires, k) << "\n";
    return 0;
}