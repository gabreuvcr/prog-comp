#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);
#define MAX 1000000000

using namespace std;

typedef unsigned long long ull;

bool is_prime(ull number) {
    if (number == 0 || number == 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) return false;
    }

    return true;
}

int main() { _

    ull T; cin >> T;

    for (ull t = 0; t < T; t++) {
        ull N; cin >> N;

        vector<ull> numbers(N);

        for (ull n = 0; n < N; n++) {
            cin >> numbers[n];
        }

        sort(numbers.begin(), numbers.end());
        numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

        if (numbers[0] != 1) {
            cout << 0 << endl; continue;
        }
        
        ull i = 0, n = 1;
        ull smallest_prime = 2;

        while (n <= MAX) {
            if (numbers[i] != n and is_prime(n)) {
                smallest_prime = n; break;
            } else if (numbers[i] != n) {
                n++;
            } else {
                i++; n++;
            }
        }

        cout << smallest_prime - 1 << endl;
    }
    
    return 0;
}
