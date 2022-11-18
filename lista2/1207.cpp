#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

struct dinic {
    struct edge {
        int to, cap, rev, flow;
        bool res;
        edge(int to_, int cap_, int rev_, bool res_)
            : to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
    };
 
    vector<vector<edge>> g;
    vector<int> lev, beg;
    long long F;
    dinic(int n) : g(n), F(0) {}
 
    void add(int a, int b, int c) {
        g[a].emplace_back(b, c, g[b].size(), false);
        g[b].emplace_back(a, 0, g[a].size()-1, true);
    }
    bool bfs(int s, int t) {
        lev = vector<int>(g.size(), -1); lev[s] = 0;
        beg = vector<int>(g.size(), 0);
        queue<int> q; q.push(s);
        while (q.size()) {
            int u = q.front(); q.pop();
            for (auto& i : g[u]) {
                if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
                lev[i.to] = lev[u] + 1;
                q.push(i.to);
            }
        }
        return lev[t] != -1;
    }
    int dfs(int v, int s, int f = 0x3f3f3f3f) {
        if (!f or v == s) return f;
        for (int& i = beg[v]; i < g[v].size(); i++) {
            auto& e = g[v][i];
            if (lev[e.to] != lev[v] + 1) continue;
            int foi = dfs(e.to, s, min(f, e.cap - e.flow));
            if (!foi) continue;
            e.flow += foi, g[e.to][e.rev].flow -= foi;
            return foi;
        }
        return 0;
    }
    long long max_flow(int s, int t) {
        while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
        return F;
    }
};

int main() { _

    int N, M;

    while (cin >> N >> M) {
        int origin = 0;
        int dest = N + M + 1;

        int category_offset = 1;
        int vodka_offset = 1 + M;
        int sum_benefit = 0;

        dinic D(N + M + 2);

        vector<int> costs(N);
        for (int c = 0; c < N; c++) {
            cin >> costs[c];
        }

        vector<int> types(M);
        for (int t = 0; t < M; t++) {
            cin >> types[t];
        }

        vector<vector<int>> benefits;
        benefits.resize(M);
        for (int b = 0; b < M; b++) {
            benefits[b].resize(types[b] + 1);
            cin >> benefits[b][0];
            sum_benefit += benefits[b][0];
            for (int t = 0; t < types[b]; t++) {
                cin >> benefits[b][t + 1];
            }
        }

        for (int c = category_offset; c < M + category_offset; c++) {
            D.add(origin, c, benefits[c - category_offset][0]);
        }

        for (int c = category_offset; c < M + category_offset; c++) {
            for (int b = 1; b <= types[c - category_offset]; b++) {
                D.add(c, benefits[c - category_offset][b] + vodka_offset - 1, INF);
            }
        }

        for (int v = vodka_offset; v < N + vodka_offset; v++) {
            D.add(v, dest, costs[v - vodka_offset]);
        }

        cout << sum_benefit - D.max_flow(origin, dest) << endl;
    }
    
    return 0;
}
