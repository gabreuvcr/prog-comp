#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<int, string> dict_digit_to_braile = {
    {1, "*....."}, {2, "*.*..."}, {3, "**...."},
    {4, "**.*.."}, {5, "*..*.."}, {6, "***..."},
    {7, "****.."}, {8, "*.**.."}, {9, ".**..."},
    {0, ".***.."}
};

map<string, int> dict_braile_to_digit = {
    {"*.....", 1}, {"*.*...", 2}, {"**....", 3},
    {"**.*..", 4}, {"*..*..", 5}, {"***...", 6},
    {"****..", 7}, {"*.**..", 8}, {".**...", 9},
    {".***..", 0}
};

void decimal_to_braile(int num_digits) {
    vector<int> digits;
    string input_digit;
    
    cin >> input_digit;

    for (int i = 0; i < num_digits; i++) {
        digits.push_back(stoi(input_digit.substr(i, 1)));
    }

    for (int line = 0; line < 6; line += 2) {
        for (int i = 0; i < num_digits; i++) {
            int digit = digits[i];
            string braile_value = dict_digit_to_braile[digit];
            if (i == num_digits - 1) {
                cout << braile_value.at(line) << braile_value.at(line + 1);
            }
            else {
                cout << braile_value.at(line) << braile_value.at(line + 1) << " ";
            }
        }
        cout << endl;
    }
}

void braile_to_decimal(int num_digits) {
    vector<string> brailes;
    string braile;
    
    for (int line = 0; line < 3; line++) {
        for (int i = 0; i < num_digits; i++) {
            cin >> braile;

            if (brailes.size() < num_digits) {
                brailes.push_back(braile); continue;
            }

            brailes[i] = brailes[i] + braile;
        }
    }

    for (string braile : brailes) {
        int digit_value = dict_braile_to_digit[braile];
        cout << digit_value;
    }
    cout << endl;
}

int main() {
    int num_digits;
    char type;

    while (cin >> num_digits) {
        if (num_digits == 0) break;

        cin >> type;

        switch (type)
        {
            case 'S':
                decimal_to_braile(num_digits);
                break;
            case 'B':
                braile_to_decimal(num_digits);
                break;
            default:
                break;
        }
    }
    return 0;
}
