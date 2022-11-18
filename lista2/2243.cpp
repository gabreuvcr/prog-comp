#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define endl '\n'

#define _ ios::sync_with_stdio(false); cin.tie(NULL);


int main() { _
    int N; cin >> N;
    vector<int> heights(N, 0), left(N, 0), right(N, 0);
    int higher_triangle = 0;

    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            left[i] = 1;
        } else {
            left[i] = min(left[i - 1] + 1, heights[i]);
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        if (i == N - 1) {
            right[i] = 1;
        } else {
            right[i] = min(right[i + 1] + 1, heights[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        higher_triangle = max(higher_triangle, min(left[i], right[i]));
    }

    cout << higher_triangle << endl;

    return 0;
}
