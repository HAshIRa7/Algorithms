#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <cassert>
#include <algorithm>
#include <time.h>
using namespace std;

struct edge {
    int from;
    int to;
    int cost;
    void print() const {
        cout << "(" << from << "," << to << "," << cost << ")\n";
    }

};

bool operator < (edge const &l, edge const &r) {
    if (l.cost < r.cost) return true;
    if (l.cost > r.cost) return false;
    if (l.from < r.from) return true;
    if (l.from > r.from) return false;
    return l.to < r.to;
}

struct dsu {
    dsu(size_t n) {
        p.resize(n);
        for (size_t i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    size_t find(size_t u) {
        return u == p[u] ? u: p[u] = find(p[u]);
    }

    bool merge(size_t u, size_t v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (dir) p[u] = v;
        else     p[v] = u;
        dir = !dir;
        return true;
    }

    vector<size_t> p;   
    bool dir = true;
};

struct graph {
    graph(int N) : N(N) {
        adj.resize(N);
    }

    void add_edge(int from, int to, int cost) {
        assert(from >= 0 && from < N);
        assert(to >= 0   && to   < N);
        adj[from].push_back({from, to, cost});
        adj[to].push_back({to, from, cost});
        ways.push_back({to, from, cost});
    }

    auto kruscal() {
        cout << "kruscal()\n";
        vector<edge> ret;

        sort(ways.begin(), ways.end());
        dsu d(N);
        for (size_t cur = 0; ret.size() < N-1; cur++) {
            auto e = ways[cur];
            if (d.merge(e.from, e.to)) {
                ret.push_back(e);
            }
        }
        cout << "end of kruscal\n";
        return ret;

    }

    auto prim(int start) {
        cout << "prim(" << start << ")\n";
        assert(start >= 0 && start < N);
        vector<edge> ret;
        vector<bool> MST(N);
        set<edge> q;
        MST[start] = true;
        for (auto const &e: adj[start]) {
            if (MST[e.from] && !MST[e.to]) {
              q.insert(e);
            }
        }  
        while (ret.size() < N-1) {
            auto it = q.begin();
            auto ed = *it;
            q.erase(it);
            // ed.print();
            assert (MST[ed.from]);
            if (MST[ed.to]) continue;
            ret.push_back(ed);
            MST[ed.to] = true;
            for (auto const &e: adj[ed.to]) {
                if (MST[e.from] && !MST[e.to]) {
                  q.insert(e);
                }
            }  

        }
        cout << "end of prim\n";
        return ret;
    }

    vector<vector<edge>> adj;
    vector<edge> ways;
    int N;
};

int main() {
    int N, M;
    cin >> N >> M;
    graph g(N);
    for (int i = 0; i < M; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        g.add_edge(from-1, to-1, cost);
    }
    
    clock_t start1 = clock();
    auto edges = g.prim(0);
    clock_t end1 = clock();
    int sum = 0;
    for (auto const &q: edges) {
        sum += q.cost;
        cout << "(" << q.from << "," << q.to << "," << q.cost << ") ";
    }
    cout << "\n";
    int sum1 = 0;
    clock_t start2 = clock();
    edges = g.kruscal();
    clock_t end2 = clock();
    for (auto const &q: edges) {
        sum1 += q.cost;
        cout << "(" << q.from << "," << q.to << "," << q.cost << ") ";
    }
    cout << "\n";
    cout << "sum=" << sum << " " << "sum1=" << sum1 << "\n";
    cout << "clock1=" << end1 - start1 << "  clock2=" << end2 - start2 << "\n"; 
}