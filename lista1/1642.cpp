#include <iostream>
#include <string>
#include <algorithm>
#include <map>
 
using namespace std;

void largest_substring(int number_of_keys, string text) {
    int i = 0;
    int largest_substr = 0;
    map<char, int> occurr;

    for (int j = 0; j < text.length(); j++) {
        int len = j - i + 1;

        if (occurr.count(text[j]) == 1) {
            occurr[text[j]]++;
        } 
        else {
            occurr[text[j]] = 1;
        }
    
        if (occurr.size() <= number_of_keys && len >= largest_substr) {
            largest_substr = len;
        }
        else if (occurr.size() > number_of_keys) {
            if (occurr.count(text[i]) == 1 && occurr[text[i]] == 1) {
                occurr.erase(text[i]);
            } else {
                occurr[text[i]]--;
            }
            i++;
        }
    }
    cout << largest_substr << endl;
}
 
int main() {
    int number_of_keys;
    string text;

    while (cin >> number_of_keys) {
        if (number_of_keys == 0) break;

        cin.ignore();

        getline(cin, text);

        largest_substring(number_of_keys, text);
    }

    return 0;
}
