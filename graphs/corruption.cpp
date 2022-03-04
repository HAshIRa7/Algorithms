#include <iostream> 
#include <vector>    
#include <algorithm>

using namespace std; 

struct edge { 
    int32_t from; 
    int32_t to; 
    uint64_t cost; 
};   

struct dsu {
    vector<int32_t> p;  
    bool dir = true; 
    dsu(int32_t v) {
        p.resize(v);
        for(int32_t i = 0; i < v; i++) {
            p[i] = i; 
        }
    }  

    int32_t find(int32_t u) {
        return u == p[u] ? u : p[u] = find(p[u]); 
    } 

    bool merge(int32_t u, int32_t v) {
        u = find(u); 
        v = find(v); 
        if(u == v) return false; 
        if(dir) p[u] = v; 
        else    p[v] = u; 
        return true ; 
    }
};

bool operator < (edge const &l, edge const &r) {
    if(l.cost < r.cost) return true; 
    if(l.cost > r.cost) return false;  
    if(l.from < r.from) return true; 
    if(l.from > r.from) return false; 
    return l.to < r.to; 
}

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int n; 
    cin >> n;  
    vector<edge> edges; 
    for(int32_t i = 0; i < n; i++) {
        for(int32_t j = 0; j < n; j++) { 
            uint64_t cost; 
            cin >> cost;  
            if (cost != 0) edges.push_back({i, j, cost});
        }
    }   
    sort(edges.begin(), edges.end());  

    dsu uni(n);  
    uint64_t total = 0; 
    for(size_t i = 0; i < edges.size(); i++) {
        if(uni.merge(edges[edges.size() - i - 1].from, edges[edges.size() - i - 1].to)) { 
            total += edges[edges.size() - i - 1]. cost; 
        }
    } 
    cout << total << "\n"; 
    return 0; 
}