#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

typedef unsigned long long ull;

using namespace std;

vector<bool> primes;

void find_primes(ull end) {
    primes.resize(end + 1, true);

    primes[0] = false;
    primes[1]= false;

    for (ull i = 2; i * i <= end; i++) {
        if (primes[i]) {
            for (ull j = i * i; j <= end; j += i) {
                primes[j] = false;
            }
        }
    }
}

ull find_number_of_primes(ull start, ull end) {
    find_primes(end);

    ull count = 0;
    for (ull i = start; i <= end; i++) {
        if (primes[i]) {
            count++;
        }
    }
    return count;
}

ull factors_2(ull n) {
    ull r = 0, p = 2;

    while (n >= p) {
        r += n / p; p *= 2;
    }

    return r;
}

string alice_or_bob(ull n, ull k) {
    if (factors_2(n + k - 1) > (factors_2(n - 1) + factors_2(k))) {
        return "Bob";
    } else {
        return "Alice";
    }
}

int main() { _

    int A, B;
    cin >> A >> B;

    if (A == B) {
        cout << "?" << endl;
        return 0;
    }

    ull num_factors = abs(A - B);

    ull start = min(A, B), end = max(A, B);

    ull number_of_primes = find_number_of_primes(start, end);

    if (number_of_primes == 0) {
        cout << "Bob" << endl;
    } else {
        cout << alice_or_bob(number_of_primes, num_factors) << endl;
    }
    
    return 0;
}
