#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define endl '\n'

#define _ ios::sync_with_stdio(false); cin.tie(NULL);

vector<int> monsters_life, damages_increase;
int number_of_rooms, mage_mana, mage_damage;

double memo[1001][101];

double knapsack(int i, int cap) {
    if (cap < 0) return 0;

    if (i < 0) return 0;

    double& s = memo[i][cap];

    if (s != -1) return s;

    double time_without_increase = (double)monsters_life[i] / mage_damage;
    double time_with_increase = (double)monsters_life[i] / (mage_damage + damages_increase[i]);

    return s = min(
        knapsack(i - 1, cap) + time_without_increase, 
        (cap > 0 ? knapsack(i - 1, cap - 1) + time_with_increase : INF)
    );  
}

int main() { _
    while (cin >> number_of_rooms >> mage_mana >> mage_damage) {

        monsters_life.resize(number_of_rooms);
        damages_increase.resize(number_of_rooms);

        for (int i = 0; i < number_of_rooms; i++) {
            cin >> monsters_life[i] >> damages_increase[i];
        }

        for (int i = 0; i <= number_of_rooms; i++) {
            for (int j = 0; j <= mage_mana; j++) {
                memo[i][j] = -1;
            }
        }

        cout.precision(4);

        double min_time = knapsack(number_of_rooms - 1, mage_mana);
        cout << fixed << min_time << endl;
    }

    return 0;
}
