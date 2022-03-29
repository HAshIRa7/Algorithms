struct dsu {
    vector<int> p; 
    bool bar = true;  
    
    dsu(int n) {
        p.resize(n); 
        for(int i = 0; i < n; i++) { 
            p[i] = i; 
        }
    }
    
    int find(int u) {
        return (u == p[u]) ? p[u] : p[u] = find(p[u]); 
    } 
    
    bool merge(int u, int v) {
        u = find(u); 
        v = find(v); 
        if(u == v) return 0; 
        if(bar)    p[u] = v;
        if(!bar)   p[v] = u; 
        bar = !bar; 
        return true; 
    }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        /*sort(meetings.begin(), meetings.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];  
        });*/
        dsu d(n); 
        vector<vector<pair<int, int>>> adj(1000 * 100 + 1);
        d.merge(0, firstPerson); 
        for(size_t i = 0; i < meetings.size(); i++) {
            adj[meetings[i][2]].push_back({meetings[i][0], meetings[i][1]}); 
        } 
        for(int i = 0; i < 1000 * 100 + 1; i++) {
            for(size_t j = 0; j < adj[i].size(); j++) {
                d.merge(adj[i][j].first, adj[i][j].second); 
            }  
            
            for(size_t j = 0; j < adj[i].size(); j++) {
                if(d.find(adj[i][j].first) != d.find(0)) {
                    d.p[adj[i][j].first] = adj[i][j].first;
                    d.p[adj[i][j].second] = adj[i][j].second;
                }
            }
        } 
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(d.find(i) == d.find(0)) res.push_back(i);
        } 
        return res;
    }
};