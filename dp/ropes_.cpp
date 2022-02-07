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
    vector<int> coord(n); 
    for(int i = 0; i < n; i++) {
        cin >> coord[i];
    }   
    sort(coord.begin(), coord.end()); 
    vector<int> d(n); 
    d[0] = 0; 
    d[1] = coord[1] - coord[0]; 
    d[2] = coord[2] - coord[0]; 
    for(int i = 3; i < n; i++) {
        d[i] = min(d[i - 1], d[i - 2]) + coord[i] - coord[i - 1]; 
    } 
    cout << d[n - 1] << "\n";
    return 0;
}