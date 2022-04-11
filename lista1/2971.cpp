#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define INF 0x3F3F3F3F
 
map<char, int> card_values = {
    {'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
    {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'D', 10},
    {'Q', 11}, {'J', 12}, {'K', 13}
};

void remove_card(string* cards, char card) {
    auto pos = (*cards).find(card);
    if (pos != string::npos) {
        (*cards).erase(pos, 1);
    }
}

char next_card(string cards) {
    char n_card;
    int less_card = INF;
    for (char c : cards) {
        if (c == 'C') continue;
        int count_c = count(cards.begin(), cards.end(), c);
        if (count_c == less_card && card_values[c] < card_values[n_card]) {
            n_card = c;
        }
        else if (count_c < less_card) {
            less_card = count_c;
            n_card = c;
        }
    }
    return n_card;
}

int has_a_winner(vector<string> all_cards) {
    int winner = INF;
    for (int i = 0; i < all_cards.size(); i++) {
        bool all_equal = true;
        char card_aux = all_cards[i][0];
        for (char card : all_cards[i]) {
            if (card_aux != card) {
                all_equal = false; break;
            }
        }
        if (all_equal && winner > i) {
            winner = i;
        }
    }
    
    return winner == INF ? -1 : winner;
}

int game(vector<string> all_cards, int first_competitor, int number_of_competitors) {
    int is_with_joker = first_competitor;
    int N = number_of_competitors;
    int winner = -1;
    bool can_pass_joker = false;
    
    while (true) {
        for (int i = first_competitor; i < (all_cards.size() + first_competitor); i++) {
            if (can_pass_joker && is_with_joker == (i % N)) {
                all_cards[(i + 1) % N] += "C";
                can_pass_joker = false;
                is_with_joker = (i + 1) % N;
                remove_card(&all_cards[i % N], 'C');
            } 
            else {
                char n_card = next_card(all_cards[i % N]);
                all_cards[(i + 1) % N] += n_card;
                remove_card(&all_cards[i % N], n_card);
            }
            winner = has_a_winner(all_cards);
            
            if (winner != -1) return winner;
        }
        can_pass_joker = true;
    }
}

int main() {
    int number_of_competitors, first_competitor;
    string i_cards;

    cin >> number_of_competitors >> first_competitor;
    first_competitor -= 1;

    vector<string> all_cards;

    for (int i = 0; i < number_of_competitors; i++) {
        cin >> i_cards;
        all_cards.push_back(i_cards);
        if (i == first_competitor) all_cards[i] = all_cards[i] + "C";
    }

    cout << game(all_cards, first_competitor, number_of_competitors) + 1 << endl;
    return 0;
}
