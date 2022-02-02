#include <iostream> 
#include <string>  
#include <vector>
#include <utility>
#include <unordered_set>

using namespace std;

pair<string, bool> IsRepeated(string src, size_t len, vector<uint32_t>& pow) {  
    unordered_set<uint32_t> hashed;  
    string res = "";
    bool exist = false;  
    uint32_t h = 0; 
    for(size_t i = 0; i < len; i++) {
        h = h * 31 + (src[i] - 'A' + 1);
    }
    hashed.insert(h); 
    for(size_t i = 1; i < src.size() - len + 1; i++) { 
        h = h * 31 - pow[len] * (src[i - 1] - 'A' + 1) + (src[i + len - 1] - 'A' + 1); 
        //using rolling hashing 
        //ex : abcd  len = 3  
        // hash(abc) =  a * 31^2 + b * 31^1 + c * 31^0  
        if(hashed.find(h) != hashed.end()){ 
            res = src.substr(i, len);
            exist = true; 
            return{res, exist};
        } else {
            hashed.insert(h);
        }
    }
    return {res, exist};
}

string LongestRepeatingSubstring(string src, vector<uint32_t>& pow) {
    string res = ""; 
    size_t len = src.size(); 
    size_t left = 0; 
    size_t right = len - 1;
    //answer in left  
    //answer wiil be when right == left;
    //answer can be [left, right]  
    while(left < right) { 
        size_t mid = left + (right - left + 1) / 2; // writing like that to exit from cycle and not to get overflow 
        //example if right = 4 and left = 3; right - left = 1 -> mid = 3 + 0 = 3, also 3 < 4 and we get infinity cycle, that is why we need add 1 
        pair<string, bool> ex = IsRepeated(src, mid, pow);
        if (ex.second == true) { 
            res = ex.first; 
            left = mid; 
        } else {
            right = mid - 1; 
        }
    }
    return res; 
}

int main() { 
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);  

    string src; 
    cin >> src;  

    uint32_t m = 1024u * 1024u * 1024u * 4u - 1; 
    vector<uint32_t> pow(src.size()); 
    pow[0] = 1; 
    for(size_t j = 1; j < pow.size(); j++) {
        pow[j] = (pow[j - 1] * 31) % m;
    }

    cout << LongestRepeatingSubstring(src, pow) << "\n";
    return 0;
}