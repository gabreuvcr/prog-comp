#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int N, P;
vector<int> damage, mana;

int memo[1000][2000];

int dp(int i, int life) {
    if (life <= 0) return 0;

    if (i < 0) return INF;

    int& d = memo[i][life];

    if (d != -1) return d;

    return d = min(
        dp(i - 1, life - damage[i]) + mana[i],
        dp(i - 1, life)
    );
}

int main() { _

    while (cin >> N >> P) {
        damage.resize(N); mana.resize(N);

        for (int i = 0; i < N; i++) {
            cin >> damage[i] >> mana[i];
        }

        memset(memo, -1, sizeof(memo));

        int value = dp(N - 1, P);
        cout << (value == INF ? - 1 : value) << endl;
    }
    
    return 0;
}
