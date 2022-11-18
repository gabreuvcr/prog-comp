#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int stacks[3][100];
int memo[101][101][101];
int N;

bool solve(int i, int j, int k) {

    if (i == j && j == k && k == N) return memo[i][j][k] = 1;
    
    if (memo[i][j][k] != -1) return memo[i][j][k];

    if (i < N && stacks[0][i] % 3 == 0 && solve(i + 1, j, k)) {
        return memo[i][j][k] = 1;
    } else if (j < N && stacks[1][j] % 3 == 0 && solve(i, j + 1, k)) {
        return memo[i][j][k] = 1;
    } else if (k < N && stacks[2][k] % 3 == 0 && solve(i, j, k + 1)) {
        return memo[i][j][k] = 1;
    } else if (i < N && j < N && (stacks[0][i] + stacks[1][j]) % 3 == 0 && solve(i + 1, j + 1, k)) {
        return memo[i][j][k] = 1;
    } else if (i < N && k < N && (stacks[0][i] + stacks[2][k]) % 3 == 0 && solve(i + 1, j, k + 1)) {
        return memo[i][j][k] = 1;
    } else if (j < N && k < N && (stacks[1][j] + stacks[2][k]) % 3 == 0 && solve(i, j + 1, k + 1)) {
        return memo[i][j][k] = 1;
    } else if (i < N && j < N && k < N && (stacks[0][i] + stacks[1][j] + stacks[2][k]) % 3 == 0 && solve(i + 1, j + 1, k + 1)) {
        return memo[i][j][k] = 1;
    }

    return memo[i][j][k] = 0;
}

int main() { _
    
    while (cin >> N) {
        if (N == 0) break;

        for (int j = 0; j < N; j++) {
            for (int i = 0; i < 3; i++) {
                cin >> stacks[i][j];
            }
        }

        memset(memo, -1, sizeof(memo));

        cout << solve(0, 0, 0) << endl;
    }
    
    return 0;
}
