#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

typedef unsigned long long ll;
 
using namespace std;

bool is_prime(ll number) {
    if (number == 0 || number == 1) return false;
    if (number % 2 == 0 && number != 2) return false;
    if (number == 2) return true;

    int counter = 0;

    for (int i = 3; i <= sqrt(number); i += 2) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}
 
int main() {
    ll number;

    while (cin >> number) {
        bool prime = is_prime(number);
        bool super_prime = true;

        ll rest = number;

        while (prime && rest > 0) {
            int digit = rest % 10;
            rest = rest / 10;

            if (!is_prime(digit)) {
                super_prime = false; 
                break;
            }
        }

        if (prime && super_prime) {
            cout << "Super" << endl;
        } else if (prime) {
            cout << "Primo" << endl;
        } else {
            cout << "Nada" << endl;
        }
    }


    return 0;
}
