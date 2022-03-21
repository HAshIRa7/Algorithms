#include<iostream> 
#include<vector> 
#include <map>  
#include <climits> 
#include <string>

using namespace std;   

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t; 
    cin >> t; 
    while(t--) {
        string s; 
        cin >> s;  
        int i = 0;  
        while(true) { 
            bool flag = false;
            for(size_t j = i + 1; j < s.size(); j++) {
                if(s[j] == s[i]) {
                    i++;  
                    flag = true;
                    break;
                }
            } 
            if(!flag) break;
        } 
        for(size_t j = i; j < s.size(); j++) {
            cout << s[j];
        } 
        cout << "\n";
    }
    return 0;
}