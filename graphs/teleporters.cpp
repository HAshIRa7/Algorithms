#include <iostream>  
#include <vector> 
#include <bitset> 
#include <algorithm>

using namespace std;   

struct graph {
    vector<bitset<2000>> adj;
    int n;  

    graph(int n) : n(n) {
        adj.resize(n);
    }

    void add(int i, string s) { 
        bitset<2000> a(s);
        adj[i] = a; 
    } 

    void Get(int i) {
        cout << "this is" << adj[i] << "\n";
    }
     
    void FloydWarshall() {
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                if(adj[i][k]) {
                    adj[i] |= adj[k]; 
                }
            }
        }
    }  

    void ReClos() {
        FloydWarshall(); 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << adj[i][j]; 
            }
            cout << "\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n;
    cin >> n;  

    graph g(n); 
    for(int i = 0; i < n; i++) {
        string s; 
        cin >> s;  
        reverse(s.begin(), s.end());
        g.add(i, s);
    }
    
    g.ReClos(); 
    return 0;
}