#include <iostream>
#include <vector>
 
using namespace std;

typedef struct package {
    int amount_of_toy;
    int weight;

    package(int amount, int weight) 
        : amount_of_toy(amount), weight(weight) {}
} package;

void knapsack_dynamic(vector<package> packages, int weight_limit) {
    int number_of_packages = packages.size();

    int** matrix = new int*[number_of_packages + 1];

    for (int i = 0; i < number_of_packages + 1; i++) {
        matrix[i] = new int[weight_limit + 1];
    }

    for (int j = 0; j < weight_limit + 1; j++) {
        matrix[0][j] = 0;
    }

    for (int i = 1; i < number_of_packages + 1; i++) {
        for (int j = 0; j < weight_limit + 1; j++) {
            int without_current_package = matrix[i - 1][j];

            if (packages[i - 1].weight > j) {
                matrix[i][j] = without_current_package;
            }
            else {
                int with_current_package = packages[i - 1].amount_of_toy;
                with_current_package += matrix[i - 1][j - packages[i - 1].weight];
                matrix[i][j] = max(without_current_package, with_current_package);
            }
        }
    }

    int number_of_packages_selected = 0;
    int column_control = weight_limit;
    int weight_of_selected_packages = 0;

    for (int i = number_of_packages; i >= 1; i--) {
        if (matrix[i][column_control] != matrix[i - 1][column_control]) {
            column_control = column_control - packages[i - 1].weight;
            number_of_packages_selected++;
            weight_of_selected_packages += packages[i - 1].weight;
        }
    }

    cout << matrix[number_of_packages][weight_limit] << " brinquedos" << endl;
    cout << "Peso: " << weight_of_selected_packages << " kg" << endl;
    cout << "sobra(m) "<< number_of_packages - number_of_packages_selected << " pacote(s)" << endl;
    cout << endl;


    for (int i = 0; i < number_of_packages + 1; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void handle_case() {
    int weight_limit = 50;
    int number_of_packages;

    vector<package> packages;

    cin >> number_of_packages;

    for (int i = 0; i < number_of_packages; i++) {
        int amount, weight;
        cin >> amount >> weight;

        packages.push_back(package(amount, weight));
    }

    knapsack_dynamic(packages, weight_limit);
}
 
int main() {

    int number_of_cases;

    cin >> number_of_cases;

    for (int i = 0; i < number_of_cases; i++) {
        handle_case();
    }
 
    return 0;
}
