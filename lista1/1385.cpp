#include <iostream>
#include <bits/stdc++.h>

#define INF 0x3F3F3F3F
#define endl '\n'
#define ll long long
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

vector<vector<vector<ll>>> numbers_possible_per_seller;
vector<vector<ll>> numbers_possible;
vector<vector<ll>> totals_possible;

void verify_sum(string text) {
    vector<ll> text_splited;

    string temp_text = "";

    for (int i = 0; i < text.size(); i++) {
        if (text.at(i) == ' ') {
            try {
                text_splited.push_back(stoll(temp_text));
            } catch(out_of_range &e) {
                return;
            }
            temp_text = "";
        } else {
            temp_text = temp_text + text.at(i);
        }
    }
    try {
        text_splited.push_back(stoll(temp_text));
    } catch(out_of_range &e) {
        return;
    }

    int sum = 0;
    for (int i = 0; i < text_splited.size() - 1; i++) {
        sum += text_splited[i];
    }

    if (sum == text_splited[text_splited.size() - 1]) {
        numbers_possible.push_back(text_splited);
    }
}

void all_permutation(string text, string acc_text, int count, int num_itens) {
    if (count == num_itens) {
        if (text[0] == '0' && text.size() > 1) return;
        acc_text = acc_text + text;
        verify_sum(acc_text);
        return;
    }

    string new_acc_text;

    for (int i = 1; i < text.size(); i++) {
        if (text.substr(0, i)[0] == '0') {
            new_acc_text = acc_text + text.substr(0, 1) + " ";
            all_permutation(text.substr(1), new_acc_text, count + 1, num_itens);
            return;
        } else {
            new_acc_text = acc_text + text.substr(0, i) + " ";
            all_permutation(text.substr(i), new_acc_text, count + 1, num_itens);
        }
    }
}

void get_name_and_numbers(string text, string* name, string *numbers) {
    int index_numbers;
    for (int i = 0; i < text.size(); i++) {
        if (isdigit(text[i])) {
            index_numbers = i; break;
        }
    }
    *name = text.substr(0, index_numbers);
    *numbers = text.substr(index_numbers);
}

void print_result(vector<string> all_names, int num_prods, int num_sellers, vector<int> lines, int line_total) {
    for (int i = 1; i <= num_prods; i++) {
        cout << "P" << i << " ";
    }
    cout << "Totals" << endl;

    for (int s = 0; s < all_names.size(); s++) {
        cout << all_names[s] << " ";
        for (int p = 0; p < numbers_possible_per_seller[s][lines[s]].size(); p++) {
            if (p == numbers_possible_per_seller[s][lines[s]].size() - 1) {
                cout << numbers_possible_per_seller[s][lines[s]][p] << endl;
            } else {
                cout << numbers_possible_per_seller[s][lines[s]][p] << " ";
            }
        }
    }

    cout << "TP ";
    for (int p = 0; p < totals_possible[line_total].size(); p++) {
        if (p == totals_possible[line_total].size() - 1) {
            cout << totals_possible[line_total][p] << endl;
        } else {
            cout << totals_possible[line_total][p] << " ";
        }
    }
}

bool finded = false;

void find_combination(int num_prods, int num_sellers, int seller, vector<int>& lines, vector<ll> totals) {
    if (seller == num_sellers) {
        int p_;
        int sum;
        for (int p = 0; p < num_prods; p++) {
            sum = 0;
            for (int s = 0; s < num_sellers; s++) {
                sum += numbers_possible_per_seller[s][lines[s]][p];
            }
            if (sum != totals[p]) return;
            p_ = p;
        }
        finded = true; return;
    }

    for (int i = 0; i < numbers_possible_per_seller[seller].size(); i++) {
        lines[seller] = i;
        find_combination(num_prods, num_sellers, seller + 1, lines, totals);
        if (finded) return;
    }
}

int main() { _
    int number_of_cases;

    cin >> number_of_cases;

    for (int i = 0; i < number_of_cases; i++) {
        string header, footer;
        vector<string> all_names;
        
        cin >> header;
        
        int num_prods = (header.size() - 6) / 2;
        int num_sellers = 0;
        
        numbers_possible_per_seller.clear();
        totals_possible.clear();

        while (true) {
            string line, name, numbers;
            cin >> line;
            if (line.substr(0, 2) == "TP") {
                footer = line.substr(2); break;
            }
            num_sellers++;
            get_name_and_numbers(line, &name, &numbers);
            all_names.push_back(name);
        
            numbers_possible.clear();
            all_permutation(numbers, "", 1, num_prods + 1);
            numbers_possible_per_seller.push_back(numbers_possible);
            
        }
        numbers_possible.clear();
        all_permutation(footer, "", 1, num_prods + 1);
        reverse(numbers_possible.begin(), numbers_possible.end());
        totals_possible = numbers_possible;

        vector<int> lines(num_sellers, 0);
        
        finded = false;
        int line_total;
        for (int t = 0; t < totals_possible.size(); t++) {
            find_combination(num_prods + 1, num_sellers, 0, lines, totals_possible[t]);
            if (finded) {
                line_total = t; break;
            }
        }
        print_result(all_names, num_prods, num_sellers, lines, line_total);
    }

    return 0;
}
