#include <iostream>  
#include <string>
#include <vector> 
#include <set> 
#include <algorithm> 
#include <stack>
 
using namespace std;   

struct graph {
    size_t N; 
    vector<set<int>> adjancy_list; 
    vector<int> time_in; 
    vector<int> time_out;  
    stack<int> L; 
    int time = 0; 
    graph(size_t number) {
        N = number; 
        adjancy_list.resize(N);  
        time_in.resize(N); 
        time_out.resize(N); 
    } 

    void add(int from, int to) { 
        adjancy_list[from].insert(to);  
    } 

    void dfs() { 
        for(size_t i = 0; i < N; i++) { 
            if(time_in[i] == 0) {
                dfs_search(i); 
            }
        }
    } 

    void dfs_search(int vertex) {
        time++; 
        time_in[vertex] = time;
        for(auto q : adjancy_list[vertex]) {
            if(time_in[q] == 0) { 
                dfs_search(q); 
            }
        }  
        time++;
        time_out[vertex] = time;  
        L.push(vertex);
    }  

    void Top_Sort() {
        dfs(); 
        while(!L.empty()) {
            cout << static_cast<char>(L.top() + 'A');
            L.pop();
        } 
        cout << "\n";
    }
};

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL);
    cout.tie(NULL); 
    int l; 
    cin >> l;
    graph G(l);
    int n; 
    cin >> n;  
    vector<string> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i]; 
    }  
    for(int i = 0; i < n - 1; i++) {
        size_t len = min(v[i].size(), v[i + 1].size()); 
        for(size_t j = 0; j < len; j++) {
            if(v[i][j] != v[i + 1][j]) { 
                G.add(v[i][j] - 'A', v[i + 1][j] - 'A');
                break;
            }
        }
    }     
    G.Top_Sort();
    return 0;
}