#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int dp[301][301];

int calculate_seats(int x, int i, int c, int j) {
    if (x == 0 && c == 0) {
        return dp[i][j];
    } else if (x == 0) {
        return dp[i][j] - dp[i][c - 1];
    } else if (c == 0) {
        return dp[i][j] - dp[x - 1][j];
    } else {
        return dp[i][j] - (dp[i][c - 1] + dp[x - 1][j]) + dp[x - 1][c - 1];
    }
}

int main() { 

    int R, C, K;

    while (cin >> R >> C >> K) {
        if (R == 0 && C == 0 && K == 0) break;
        
        for (int i = 0; i < R; i++) {
            string seat; cin >> seat;
            for (int j = 0; j < C; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 0;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
                }

                dp[i][j] += (seat[j] == '.' ? 1 : 0);
            }
        }

        int x = 0;
        int smaller_area = INF;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (dp[i][j] >= K) {
                    for (int c = 0; c <= j; c++) {
                        int num_seats = calculate_seats(x, i, c, j);

                        while (x < i && num_seats >= K) {
                            x++;
                            num_seats = calculate_seats(x, i, c, j);
                        }

                        while (x > 0 && num_seats < K) {
                            x--;
                            num_seats = calculate_seats(x, i, c, j);
                        }

                        if (num_seats >= K) {
                            smaller_area = min(smaller_area, (i - x + 1) * (j - c + 1));
                        }
                    }
                }
            }
        }

        cout << smaller_area << endl;
    }
    
    
    return 0;
}
