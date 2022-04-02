#include <iostream>

using namespace std;

int main() {
    string ciphered, crib;
    int possible_positions = 0;

    cin >> ciphered >> crib;

    int init_pointer = 0, last_pointer = crib.length() - 1;

    while (last_pointer < ciphered.length()) {
        possible_positions++;

        for (int i = 0; i < crib.length(); i++) {
            if (crib.at(i) == ciphered.at(init_pointer + i)) {
                possible_positions--;
                break;
            }
        }

        init_pointer++; last_pointer++;
    }

    cout << possible_positions << endl;
    return 0;
}
