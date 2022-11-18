#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int main() { _

    string text; cin >> text;

    for_each(text.begin(), text.end(), [](char &c) {
        c = tolower(c);
    });

    if (text.find("zelda") == string::npos) {
        cout << "Link Tranquilo" << endl;
    } else {
        cout << "Link Bolado" << endl;
    }
    
    return 0;
}
