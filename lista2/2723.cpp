#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

bool is_balanced(int A, int B) {
    return abs(A - B) <= 5;
}

void handle_case() {
    int A = 0, B = 0;
    int N; cin >> N;

    vector<int> weights;
    weights.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    for (int w : weights) {
        if (is_balanced(A + w, B)) {
            A += w;
        } else {
            B += w;
        }

        if (!is_balanced(A, B)) {
            cout << "Ho Ho Ho!" << endl;
            return;
        }
    }

    cout << "Feliz Natal!" << endl;
}

int main() { _

    int T; cin >> T;

    for (int t = 0; t < T; t++) {
        handle_case();
    }
    
    return 0;
}
