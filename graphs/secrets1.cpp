#include <iostream> 
#include <vector> 
#include <algorithm>
#include <climits> 

using namespace std; 

bool operator<(pair<int, int>& f, pair<int, int>& s) {
    return f.second < s.second;
}

struct edge { 
    int to; 
    int w;  
    edge(int to, int w) : to(to), w(w) {}  
};  

struct graph { 
    vector<vector<edge>> adj;  
    vector<int> dist;  
    int n;
    graph(int n) : n(n) {
        adj.resize(n);  
        dist.resize(n);
        for(int i = 0; i < n; i++) {
            dist[i] = INT_MAX; 
        } 
        dist[0] = 0;
    }  
    void add(int u, int v, int time) { 
        adj[u].push_back(edge(v, time)); 
        adj[v].push_back(edge(u, time)); 
    } 
    void Dijikstra() { 
        set<pair<int, int>> S; 
        for(int i = 0; i < n; i++) { 
            S.insert({i, dist[i]}); 
        } 
        while(!S.empty()) {
            auto t = *S.begin();  
            S.erase(S.begin());  
            for(auto it : adj[t.first]) { 
                if(it.w < dist[t.first]) continue;  
                if(dist[it.to] > it.w) {
                    S.erase({it.to, dist[it.to]});
                    dist[it.to] = it.w;
                    S.insert({it.to, dist[it.to]});
                }
            }
        } 
    }  
};
class Solution { 
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {  
        graph g(n); 
        g.add(0, firstPerson, 0);
        for(size_t i = 0; i < meetings.size(); i++) {
            g.add(meetings[i][0], meetings[i][1], meetings[i][2]);
        }    
        g.Dijikstra();
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(g.dist[i] < INT_MAX) {
                res.push_back(i);
            }
        }
        return res; 
    }
}; 