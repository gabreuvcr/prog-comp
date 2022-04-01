#include <iostream>
#include <algorithm>
#include <vector>

#define SIDES 2
#define M 0
#define N 1

using namespace std;

void output(int counter_woods[]) {
    if (counter_woods[M] == -1 && counter_woods[N] == -1) {
        cout << "impossivel" << endl;
    }
    else if (counter_woods[M] == -1) {
        cout << counter_woods[N] << endl;
    }
    else if (counter_woods[N] == -1) {
        cout << counter_woods[M] << endl;
    }
    else {
        cout << min(counter_woods[N], counter_woods[M]) << endl;
    }
}

void handle_floor(int sides[]) {
    vector<int> woods;
    int wood_width, number_of_woods;
    int counter_woods[2], number_of_lines, completed_lines;
    
    sides[M] *= 100; sides[N] *= 100;
    
    cin >> wood_width;
    cin >> number_of_woods;

    for (int w = 0; w < number_of_woods; w++) {
        int wood_length;
        cin >> wood_length;
        woods.push_back(wood_length * 100);
    }

    sort(woods.begin(), woods.end());

    counter_woods[M] = 0; counter_woods[N] = 0;

    for (int s = 0; s < SIDES; s++) {
        if (sides[1 - s] % wood_width != 0) {
            counter_woods[s] = -1;
            continue;
        }

        number_of_lines = sides[1 - s] / wood_width;
        completed_lines = 0;

        int left_pointer = 0, right_pointer = woods.size() - 1;

        do {
            if (woods[right_pointer] == sides[s]) {
                completed_lines++;
                counter_woods[s]++;
                right_pointer--;
            }
            else if (woods[left_pointer] == sides[s]) {
                completed_lines++;
                counter_woods[s]++;
                left_pointer++;
            } 
            else if (left_pointer != right_pointer) {
                int sum_woods = woods[left_pointer] + woods[right_pointer];
                if (sum_woods == sides[s]) {
                    completed_lines++;
                    counter_woods[s] += 2;
                    right_pointer--; left_pointer++;
                }
                else if (sum_woods > sides[s]) {
                    right_pointer--;
                }
                else if (sum_woods < sides[s]) {
                    left_pointer++;
                }
            } 
            else {
                break;
            }
        } while(left_pointer <= right_pointer && completed_lines != number_of_lines);

        if (completed_lines != number_of_lines) {
            counter_woods[s] = -1;
        }
    }

    output(counter_woods);
}

int main() {
    int sides[2];

    while (true) {
        cin >> sides[M] >> sides[N];

        if (sides[M] == 0 && sides[N] == 0) break;
        handle_floor(sides);
    }

    return 0;
}
