#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b % a, a) * b / a : 1;
}

ll fast_pow(ll x, ll y, ll m) {
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

int tot(int n){
	int ret = n;

	for (int i = 2; i*i <= n; i++) if (n % i == 0) {
		while (n % i == 0) n /= i;
		ret -= ret / i;
	}
	if (n > 1) ret -= ret / n;

	return ret;
}

ll find_d(ll N, ll E) {
    ll T = tot(N);
    ll D = inv(E, T);
    return D;
}

ll decrypt_message(ll N, ll E, ll C) {
    ull message;
    ll D = find_d(N, E);
    message = fast_pow(C, D, N);
    return message;
}

int main() { _

    ll N, E, C;
    cin >> N >> E >> C;

    cout << decrypt_message(N, E, C) << endl;
    
    return 0;
}
