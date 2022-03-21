#include <iostream> 
#include <vector>  
#include <utility> 
#include <algorithm> 
#include <map>  
#include <set>

using namespace std;  

struct point {
    int x; 
    int y; 
    point(int x, int y) : x(x), y(y) {}
};  

bool operator < (point const &p1, point const &p2) {
    if(p1.x < p2.x) return true;  
    if(p1.x > p2.x) return false; 
    if(p1.y < p2.y) return true; 
    return false; 
} 

bool operator ==(point const &p1,  point const &p2) {
    return (p1.x == p2.x) && (p1.y == p2.y);
}

bool operator ==(point& p1, point& p2) {
    return (p1.x == p2.x) && (p1.y == p2.y);
}
 
struct graph {
    map<point, set<point>> adj;   
    map<point, int> color; 
    int ccount = 0;  
    int pcount = 0;
    void add(int x, int y) { 
        if(x == y) pcount++; 
        point p1(x, y); 
        point p2(x, x); 
        point p3(y, y); 
        adj[p1].insert(p2); 
        adj[p1].insert(p3); 
        adj[p2].insert(p1);
        adj[p3].insert(p1);
    } 

    void dfs() {
        for(auto & it : adj) {
            if(!color[it.first]) { 
                const point prev(-1, -1); 
                dfs_rec(it.first, prev);   
            }
        }
    } 

    void dfs_rec(const point& p1, const point& prev) { 
        //cout << p1.x << " " << p1.y << "\n";
        color[p1] = 1;  
        for(auto &item : adj[p1]) { 
            if(item == p1) continue;
            if(item == prev) continue;  
            if(color[item] == 1) { 
                //cout << "There "<< p1.x << " " << p1.y << "\n";
                ccount++;  
                color[item] = 2;
                break;;
            } else if(color[item] == 0) {
                dfs_rec(item, p1);
            }
        } 
        color[p1] = 2; 
    } 
};

int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL); 
    cout.tie(NULL); 

    int t; 
    cin >> t;
    while(t--) {
        int n, m; 
        cin >> n >> m;  
        graph g; 
        for(int i = 0; i < m; i++) {
            int x, y; 
            cin >> x >> y; 
            g.add (x, y); 
        } 
        g.dfs();  
        cout << m + g.ccount - g.pcount << "\n";  
    }
    return 0;
}