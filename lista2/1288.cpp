#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define endl '\n'

#define _ ios::sync_with_stdio(false); cin.tie(NULL);

typedef struct shell {
    int power;
    int weight;

    shell(int power, int weight) 
        : power(power), weight(weight) {}
} shell;

int knapsack_dynamic(vector<shell> shells, int weight_limit) {
    int number_of_shells = shells.size();

    int** matrix = new int*[number_of_shells + 1];

    for (int i = 0; i < number_of_shells + 1; i++) {
        matrix[i] = new int[weight_limit + 1];
    }

    for (int j = 0; j < weight_limit + 1; j++) {
        matrix[0][j] = 0;
    }

    for (int i = 1; i < number_of_shells + 1; i++) {
        for (int j = 0; j < weight_limit + 1; j++) {
            int without_current_shell = matrix[i - 1][j];

            if (shells[i - 1].weight > j) {
                matrix[i][j] = without_current_shell;
            }
            else {
                int with_current_shell = shells[i - 1].power;
                with_current_shell += matrix[i - 1][j - shells[i - 1].weight];
                matrix[i][j] = max(without_current_shell, with_current_shell);
            }
        }
    }

    int number_of_shells_selected = 0;
    int column_control = weight_limit;
    int weight_of_selected_shells = 0;

    for (int i = number_of_shells; i >= 1; i--) {
        if (matrix[i][column_control] != matrix[i - 1][column_control]) {
            column_control = column_control - shells[i - 1].weight;
            number_of_shells_selected++;
            weight_of_selected_shells += shells[i - 1].weight;
        }
    }

    int power = matrix[number_of_shells][weight_limit];

    for (int i = 0; i < number_of_shells + 1; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    return power;
}

void handle_case() {
    int number_of_shells;
    int weight_limit;
    int castle_resistance;

    vector<shell> shells;

    cin >> number_of_shells;

    for (int i = 0; i < number_of_shells; i++) {
        int power, weight;
        cin >> power >> weight;

        shells.push_back(shell(power, weight));
    }

    cin >> weight_limit;
    cin >> castle_resistance;

    int power = knapsack_dynamic(shells, weight_limit);

    if (power >= castle_resistance) {
        cout << "Missao completada com sucesso" << endl;
    } else {
        cout << "Falha na missao" << endl;
    }
}

int main() { _
    int number_of_cases; cin >> number_of_cases;
    
    for (int i = 0; i < number_of_cases; i++) {
        handle_case();
    }

    return 0;
}
