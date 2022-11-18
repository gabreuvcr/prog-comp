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

map<string, int> sizes = {
    { "XXL", 0 },
    { "XL", 1 },
    { "L", 2 },
    { "M", 3 },
    { "S", 4 },
    { "XS", 5 }
};

void handle_case() {
    int N, M; cin >> N >> M;
    int N_per_type = N / 6;

    int origin = 0;
    int offset_M = 1;
    int offset_N = 1 + M;
    int source = 1 + N + M;
    dinic D(1 + M + N + 1);

    for (int m = offset_M; m < M + offset_M; m++) {
        D.add(origin, m, 1);
    }

    for (int m = offset_M; m < M + offset_M; m++) {
        for (int i = 0; i < 2; i++) {
            string size; cin >> size;
            for (int j = 0; j < N_per_type; j++) {
                D.add(m, sizes[size] + (j * 6) + offset_N, 1);
            }
        }
    }

    for (int n = offset_N; n < N + offset_N; n++) {
        D.add(n, source, 1);
    }

    int value = D.max_flow(origin, source);
    cout << (value >= M ? "YES" : "NO") << endl;
}

int main() { _
    int T; cin >> T;

    for (int t = 0; t < T; t++) {
        handle_case();
    }    
    
    return 0;
}
