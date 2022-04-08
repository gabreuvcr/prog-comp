#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fold_tape(vector<int> input, int index) {
    vector<int> input_folded;
    int input_length = input.size();
    int values_folded = input_length - index;
    int jump = 1;

    if (input.size() == index) return input;

    if (values_folded <= index) {
        for (int i = index; i < input_length; i++) {
            input[i - jump] += input[i];
            jump += 2;
        }
        for (int i = 0; i < index; i++) {
            input_folded.push_back(input[i]);
        }

        return input_folded;
    } else {
        int init_reversed = index * 2;

        for (int i = input_length - 1; i >= init_reversed ; i--) {
            input_folded.push_back(input[i]);
        }
        for (int i = index; i < init_reversed; i++) {
            input_folded.push_back(input[i - jump] + input[i]);
            jump += 2;
        }

        return input_folded;
    }
}

bool equal_tape(vector<int> folded, vector<int> output) {
    if (folded.size() != output.size()) return false;

    for (int i = 0; i < output.size(); i++) {
        if (output[i] != folded[i]) return false;
    }

    return true;
}

bool is_reverse(vector<int> input, vector<int> output) {
    reverse(input.begin(), input.end());

    return equal_tape(input, output);
}

bool recursive_fold(vector<int> folded, vector<int> output) {
    if (folded.size() < output.size()) return false;
   
    if (equal_tape(folded, output)) return true;
    if (is_reverse(folded, output)) return true;

    bool result = false;

    for (int fold = 1; fold < folded.size(); fold++) {
        result = result || recursive_fold(fold_tape(folded, fold), output);

        if (result) return result;
    }

    return result;
}

void handle_tape(vector<int> input, vector<int> output) {
    bool exist = recursive_fold(input, output);

    if (exist) {
        cout << "S" << endl;
        return;
    }
    cout << "N" << endl;
}

int main() {
    int input_length, output_length;

    while (cin >> input_length) {
        vector<int> input, output;
        int content;

        for (int i = 0; i < input_length; i++) {
            cin >> content;
            input.push_back(content);
        }

        cin >> output_length;

        for (int i = 0; i < output_length; i++) {
            cin >> content;
            output.push_back(content);
        }

        handle_tape(input, output);
    }
 
    return 0;
}
