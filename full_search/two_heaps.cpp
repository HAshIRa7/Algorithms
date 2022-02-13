#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <math.h> 

using namespace std;  

int32_t FindMin(vector<int32_t>& w, size_t index, int32_t sum_total, int32_t sum_calculated) { 
    if(index == w.size()) {
        return abs(sum_total - sum_calculated * 2); 
    }
    return min(FindMin(w, index + 1, sum_total, sum_calculated + w[index]), FindMin(w, index + 1, sum_total, sum_calculated)); 
}

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n; 
    cin >> n; 
     
    vector<int32_t> w(n); 
    int32_t sum_total = 0;
    for(int i = 0; i < n; i++) {
        cin >> w[i]; 
        sum_total += w[i]; 
    } 

    cout << FindMin(w, 0, sum_total, 0) << "\n";
    return 0;  
}