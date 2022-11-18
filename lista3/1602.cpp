#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

vector<bool> is_prime;
vector<int> dividers;
vector<int> num_hiper_primes;

void pre_calculate_hiper_primes(int MAX) {
    MAX = MAX + 1;
    int numDividers, tam;

    is_prime.resize(MAX, true);
    dividers.resize(MAX, 0);
    num_hiper_primes.resize(MAX, 0);

    for (int i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            dividers[i] = 2;
            for (int j  = i * 2; j < MAX; j += i) {
                is_prime[j] = false;
                tam = j;

                numDividers = 0;
                while (tam % i == 0) {
                    tam /= i;
                    numDividers++;
                }

                if (dividers[j] == 0) {
                    dividers[j] = numDividers + 1;
                } else {
                    dividers[j] *= numDividers + 1;
                }
            }
        }
    }
    for (int i = 2; i < MAX; i++) {
        num_hiper_primes[i] = num_hiper_primes[i - 1];
        if (is_prime[dividers[i]]) {
            num_hiper_primes[i]++;
        }
    }
}

int main() { _
    vector<int> all_nums;
    int num, higher_num = 0;

    while (cin >> num) {
        all_nums.push_back(num);
        higher_num = max(higher_num, num);
    }
    
    pre_calculate_hiper_primes(higher_num);

    for (int num : all_nums) {
        cout << num_hiper_primes[num] << endl;
    }
    
    return 0;
}
