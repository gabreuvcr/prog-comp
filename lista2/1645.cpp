#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

using namespace std;

ll memo[110][110];
vector<int> numbers; 

ll dp(int N, int K) {
    for (int i = 1; i <= N; i++) {
        memo[i][1] = 1;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            for (int k = 1; k < i; k++) {
                if (numbers[i] > numbers[k]) {
                    memo[i][j] += memo[k][j - 1];
                }
            }
        }
    }

    ll value = 0;
    for (int i = 1; i <= N; i++) {
        value += memo[i][K];
    }

    return value;
}

int main() { _
    int N, K;

    while (cin >> N >> K) {
        if (N == 0 && K == 0) break;

        numbers.resize(N + 1);

        memset(memo, 0, sizeof(memo));

        for (int i = 1; i <= N; i++) {
            cin >> numbers[i];
        }

        ll value = dp(N, K);
        cout << value << endl;
    }
    
    return 0;
}
