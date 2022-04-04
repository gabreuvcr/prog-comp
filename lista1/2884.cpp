#include <iostream>
#include <vector>
 
using namespace std;

bool all_lamps_off(bool* states, int number_of_lamps) {
    for (int i = 0; i < number_of_lamps; i++) {
        if (states[i]) return false;
    }
    return true;
}
 
bool is_cycle(vector<vector<bool>> previous_states, vector<int> previous_switches, 
    bool* current_states, int current_switch) {
    bool equal;
    for (int i = 0; i < previous_states.size(); i++) {
        if (current_switch != previous_switches[i]) continue;
        equal = true;
        for (int j = 0; j < previous_states[i].size(); j++) {
            if (previous_states[i][j] != current_states[j]) {
                equal = false;
                break;
            }
        }
        if (equal) return true;
    }
    return false;
}

int number_of_times_flipped(int number_of_switches, int number_of_lamps, 
    bool* states, vector<int>* switch_associations) {
    int counter = 0;
    vector<vector<bool>> previous_states;
    vector<int> previous_switches;


    while (true) {
        for (int i = 0; i < number_of_switches; i++) {
            vector<bool> current_states;

            for (int j = 0; j < switch_associations[i].size(); j++) {
                int lamp = switch_associations[i][j];
                states[lamp - 1] = !states[lamp - 1];
            }

            for (int i = 0; i < number_of_lamps; i++) {
                current_states.push_back(states[i]);
            }

            if (is_cycle(previous_states, previous_switches, states, i)) return - 1;

            previous_states.push_back(current_states);
            previous_switches.push_back(i);

            counter++;
            if (all_lamps_off(states, number_of_lamps)) return counter;
        }
    }
}

void init_states(bool* states, int number_of_lamps) {
    int next_lamps, lamp;

    cin >> next_lamps;

    for (int i = 0; i < number_of_lamps; i ++) {
        states[i - 1] = false;
    }
    
    for (int i = 0; i < next_lamps; i++) {
        cin >> lamp;
        states[lamp - 1] = true;
    }
}

void init_switches(vector<int>* switch_associations, int number_of_switches) {
    int next_lamps, lamp;

    for (int i = 0; i < number_of_switches; i++) {
        cin >> next_lamps;
        for (int j = 0; j < next_lamps; j++) {
            cin >> lamp;
            switch_associations[i].push_back(lamp);
        }
    }
}

int main() {
    int number_of_lamps, number_of_switches;
    int next_lamps, lamp;
    
    cin >> number_of_switches >> number_of_lamps;

    bool* states = new bool[number_of_lamps];
    vector<int>* switch_associations = new vector<int>[number_of_switches];

    init_states(states, number_of_lamps);
    init_switches(switch_associations, number_of_switches);


    cout << number_of_times_flipped(number_of_switches, number_of_lamps, states, switch_associations) << endl;

    delete[] states;
    delete[] switch_associations;

    return 0;
}
