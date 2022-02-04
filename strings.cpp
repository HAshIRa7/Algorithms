#include <iostream> 
#include <string> 
#include <vector> 
#include <unordered_map>

using namespace std;   
const uint32_t mod = 1024u * 1024u * 1024u * 4u - 1; 
const uint32_t p = 3000000019u;

uint32_t FindingMaxWeight(string src, vector<uint32_t>& pow) {
    uint32_t max_res = 0; 
    for(size_t len = 1; len <= src.size(); len++) {
        uint32_t mres = 0;
        //using rolling hashing;  

        unordered_map<uint32_t, uint32_t> s; 
        uint32_t h = 0; 
        for(size_t i = 0; i < len; i++){
            h = h * p + (src[i] - 'a' + 1);  
            s[h] += len; 
            if(s[h] > mres) {
                mres = s[h];
            }
        } 
        for(size_t i = 1; i < src.size() - len + 1; i++) {
            h = h * p - pow[len] * (src[i - 1] - 'a' + 1) + (src[i + len - 1] - 'a' + 1);  
            s[h] += len; 
            if(s[h] > mres) {
                mres = s[h]; 
            } 
        }
        //cout << "length " << len << " res " << mres << "\n";
        if(mres > max_res) {
            max_res = mres; 
        }
    }
    return max_res; 
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL); 

    string src; 
    cin >> src;  
    //we will be using rooling hashing for all strings  
    vector<uint32_t> pow(src.size() + 1); 
    pow[0] = 1;
    for(size_t i = 1; i < pow.size(); i++) {
        pow[i] = (pow[i - 1] * p) % mod; 
    }
    cout << FindingMaxWeight(src, pow) << "\n"; 
    return 0;
}