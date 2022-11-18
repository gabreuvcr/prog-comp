#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define endl '\n'

#define _ ios::sync_with_stdio(false); cin.tie(NULL);

vector<int> numbers;

int memo[2][1000][1000];

int is_even(int num) {
    return num % 2 == 0;
}

int dp(int l, int r, int player) {
    if (l > r) return 0;

    if (memo[player][l][r] != -1) return memo[player][l][r];

    if (player == 0) {
        return memo[player][l][r] = max(
            dp(l + 1, r, 1) + is_even(numbers[l]),
            dp(l, r - 1, 1) + is_even(numbers[r])
        );
    } else {
        return memo[player][l][r] = min(
            dp(l + 1, r, 0),
            dp(l, r - 1, 0)
        );
    }
}

int main() { _
    int N;

    while (cin >> N) {
        if (N == 0) break;
        N = N * 2;

        numbers.resize(N);

        for (int i = 0; i < N; i++) {
            cin >> numbers[i];
        }

        memset(memo, -1, sizeof(memo));

        int value = dp(0, N - 1, 0);
        cout << value << endl;
    }
    
    return 0;
}
