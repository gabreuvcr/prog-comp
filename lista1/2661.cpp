#include <iostream>
#include <vector>
#include <map>
#include <cmath>

#define ll unsigned long long
 
using namespace std;

vector<ll> get_dividers(ll number) {
    vector<ll> dividers;

    for (int i = 1; i <= sqrt(number); i++) {
        if (number % i == 0) {
            if (number / i == i) {
                dividers.push_back(number / i);
            }
            else {
                dividers.push_back(i);
                dividers.push_back(number / i);
            }
        }
    }
    return dividers;
}

int times_was_divided(ll* number, int divider) {
    int counter = 0;
    while ((*number) % divider == 0) {
        counter++;
        (*number) = (*number) / divider;
    }
    return counter;
}

bool is_despojado(ll number) {
    map<int, int> primes;

    int value = times_was_divided(&number, 2);
    if (value > 0) primes[2] = value;

    for (int i = 3; i <= sqrt(number); i += 2) {
        value = times_was_divided(&number, i);
        if (value > 0) primes[i] = value;
    }

    if (number > 2) primes[number] = 1;

    if (primes.size() <= 1) return false;

    for (auto const& p : primes) {
        if (p.second > 1) return false;
    }

    return true;
}
 
int main() {
    ll number;
    int counter = 0;
    vector<ll> dividers;

    cin >> number;

    dividers = get_dividers(number);

    for (ll d : dividers) {
        if (is_despojado(d)) counter++;
    }

    cout << counter << endl;

    return 0;
}
