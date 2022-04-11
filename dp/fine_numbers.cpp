#include <iostream> 
#include <vector> 
#include <string> 

using namespace std; 

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    string src; 
    cin >> src; 
    vector<uint64_t> v(61);  
    v[0] = 0; v[1] = 2; 
    for(int i = 2; i < 61; i++) {
        v[i] = 2 * v[i - 1]; 
    } 
    uint64_t res = 0;  
    for(size_t i = 0; i < src.size(); i++) {
        res += v[i];
    } 
 
    for(size_t i = 0; i < src.size(); i++) {
        if(src[i] < '3') break; 
        if(src[i] > '3' && src[i] < '7') {
            res += v[src.size() - i] / 2; 
            break; 
        } 
        if(src[i] > '7') {
            res += v[src.size() - i];   
            break; 
        } 
        if(src[i] == '7') { 
            res += v[src.size() - i] / 2; 
            if(i + 1 == src.size()) {
                res +=v[src.size() - i] / 2; 
            }
        } 
        if(src[i] == '3' && i + 1 == src.size()) {  
            res++;
        }
    } 

    cout << res << "\n";
}