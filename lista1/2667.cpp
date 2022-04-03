#include <iostream>
 
using namespace std;
 
int main() {
    string value;
    
    cin >> value;

    int number = 0;
    
    for (int i = 0; i < value.length(); i++) {
        number = (number * 10 + stoi(value.substr(i, 1))) % 3;
    }

    cout << number << endl;
 
    return 0;
}
