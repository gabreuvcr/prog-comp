#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;

bool is_possible(int n_comp, int p_per_comp, int all_popcorns, vector<int> popcorns, int p_bags) {
    int n_current_comp = 0, current_bag = 0, total = 0;

    while (n_current_comp <= n_comp) {
        int sum = 0;
        n_current_comp++;
        for (int p = current_bag; p < p_bags; p++) {
            sum += popcorns[p];
            current_bag++;
            if (sum > p_per_comp) {
                sum -= popcorns[p];
                current_bag--;
                break;
            }
        }
        total += sum;

        if (n_comp == n_current_comp && total < all_popcorns) return false;
    }
    return true;
}

int min_seconds(int p_bags, int n_comp, int max_p_s, vector<int> popcorns) {
    int p_per_comp = 0;

    for (int p : popcorns) {
        p_per_comp += p;
    }

    int left = 0, right = p_per_comp;
    int all_popcorns = p_per_comp;
    int last_possible = p_per_comp;

    while (left <= right) {
      
        if (floor((right + left) / 2) == p_per_comp) {
            break;
        }
        p_per_comp = floor((right + left) / 2);
        bool possible = is_possible(n_comp, p_per_comp, all_popcorns, popcorns, p_bags);
        
        if (possible) {
            last_possible = p_per_comp;
            right = p_per_comp;
        } else {
            left = p_per_comp;
        }

    }
    cout << (int)ceil((double)last_possible / max_p_s) << endl;
    return 0;
}
 
int main() {
 
    int p_bags, n_comp, max_p_s; 
    vector<int> popcorns;

    cin >> p_bags >> n_comp >> max_p_s;

    for (int i = 0; i < p_bags; i++) {
        int p;
        cin >> p;
        popcorns.push_back(p);
    }

    int min_secs = min_seconds(p_bags, n_comp, max_p_s, popcorns);

    return 0;
}
