#include <iostream>
#include <set>

using namespace std;

int main() {
    set<string> unique_jewelry;

    string jewelry_input;

    while (cin >> jewelry_input) {
        unique_jewelry.insert(jewelry_input);
    }

    cout << unique_jewelry.size() << endl;

    return 0;
}
