#include <iostream> 
#include <vector>  
#include <utility>
#include <set>

using namespace std;  

struct dsu {
    vector<int> p; 
    bool dir = true;  
    dsu(int V) {
        p.resize(V);  
        for(int i = 0; i < V; i++) {
            p[i] = i; 
        } 
    }  
    int find(int u) {
        return u == p[u] ? u : p[u] = find(p[u]); 
    }  

    bool merge(int u, int v) {
        u = find(u); 
        v = find(v); 
        if(u == v) return false; 
        if(dir) p[u] = v; 
        else    p[v] = u;
        dir = !dir; 
        return true; 
    } 
};

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int v, e, m; 
    cin >> v >> e >> m; 

    dsu uni(v); 
    vector<pair<int, int>> edges;  
    for(int i = 0; i < e; i++) { 
        int from, to; 
        cin >> from >> to; 
        edges.push_back(from <= to ? make_pair(from, to) : make_pair(to, from));  
    }   

    vector<pair<int, int>> dis; 
    for(int i = 0; i < m; i++) {
        int from, to; 
        cin >> from >> to;
        dis.push_back(from <= to ? make_pair(from, to) : make_pair(to, from)); 
        //cout << "{" << dis[i].first << ", " << dis[i].second << "}" << " ";  
    }  
    //cout << "\n";
    
    int components = v;
    for(int i = 0; i < e; i++) { 
        char is_add = true;
        for(int j = 0; j < m; j++) {
            if(dis[j] == edges[i]) {
                is_add = false; 
                break;
            }  
        }  
        if(is_add) {
                if(uni.merge(edges[i].first, edges[i].second)) components--;  
        }
    } 
    vector<int> res;  
    res.push_back(components);  
    for(int j = m - 1; j >= 0; j--) {   
        if(uni.merge(dis[j].first, dis[j].second)) components--;
        //cout << "{" << dis[j].first << ", " << dis[j].second << ") " << "components: " << components << "\n"; 
        res.push_back(components);
    }   

    for(size_t i = 0; i < res.size(); i++) {
        cout << res[res.size() - i - 1] << "\n";
    }
    return 0;
}