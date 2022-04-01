#include <iostream>
#include <iomanip>
#include <math.h>
 
using namespace std;

int main() {
    
    int bills[] { 100, 50, 20, 10, 5, 2 };
    float coins[] { 1, 0.5, 0.25, 0.1, 0.05, 0.01 };
    float value;

    cin >> value;
    
    cout << setprecision(2) << fixed;

    cout << "NOTAS:" << endl;
    for (int bill : bills) {
        int n_bills = value / bill;
        cout << n_bills << " nota(s) de R$ " << (float)bill << endl;
        value -= n_bills * bill;
    }

    cout << "MOEDAS:" << endl;
    for (float coin: coins) {
        value = round(value * 100.0) / 100.0;
        int n_coins = value / coin;
        cout << n_coins << " moeda(s) de R$ " << coin << endl;
        value -= n_coins * coin;
    }

    return 0;
}
