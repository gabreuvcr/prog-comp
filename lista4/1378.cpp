#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

typedef unsigned long long ui64;

vector<ui64> x, y;
map<ui64, ui64> distances;

ui64 distance(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int main() { _

    int N;

    while(cin >> N && N != 0) {
        x.resize(N, 0); y.resize(N, 0);
        for (int i = 0; i < N; i++) {
            cin >> x[i] >> y[i];
        }

        int counter = 0;
        for (int i = 0; i < N; i++) {
            distances.clear();
            for (int j = 0; j < N; j++) {
                if (i == j) continue;

                ui64 dist = distance(i, j);

                if (distances.count(dist) == 1) {
                    distances[dist]++;
                } else {
                    distances[dist] = 1;
                }
            }

            for (const auto &it : distances) {
                counter += it.second * (it.second - 1) / 2;
            }
        }

        cout << counter << endl;
    }    
    return 0;
}
