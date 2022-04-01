#include <iostream>
#include <algorithm>
#include <vector>

#define ASCII_ALFA 97

using namespace std;

void dfs(int node, vector<int>* graph, int* is_visited, vector<char>* component) {
    is_visited[node] = 1;
    
    (* component).push_back((char)(node + ASCII_ALFA));

    for (int adj : graph[node]) {
        if (is_visited[adj] == -1) {
            dfs(adj, graph, is_visited, component);
        }
    }
}

void find_connecteds_components(vector<int>* graph, int number_of_nodes, int number_of_edges) {
    int* is_visited = new int[number_of_nodes];
    int connected_components_counter = 0;
    
    for (int node = 0; node < number_of_nodes; node++) {
        is_visited[node] = -1;
    }

    for (int node = 0; node < number_of_nodes; node++) {
        vector<char> component;
        if (is_visited[node] == -1) {
            dfs(node, graph, is_visited, &component);

            sort(component.begin(), component.end());
            for (char comp_node : component) {
                cout << comp_node << ",";
            }
            cout << endl;

            connected_components_counter++;
        }
    }
    cout << connected_components_counter << " connected components" << endl << endl;
    delete[] is_visited;
}

void handle_case(int n_case) {
    int number_of_nodes, number_of_edges;
    
    cin >> number_of_nodes >> number_of_edges;

    vector<int>* graph = new vector<int>[number_of_nodes];

    for (int edge = 0; edge < number_of_edges; edge++) {
        char first_node, second_node;

        cin >> first_node >> second_node;

        graph[first_node - ASCII_ALFA].push_back(second_node - ASCII_ALFA);
        graph[second_node - ASCII_ALFA].push_back(first_node - ASCII_ALFA);
    }

    cout << "Case #" << n_case << ":" << endl;
    find_connecteds_components(graph, number_of_nodes, number_of_edges);
    
    delete[] graph;
}

int main() {
    int number_of_cases;

    cin >> number_of_cases;

    for (int i = 1; i <= number_of_cases; i++) {
        handle_case(i);
    }

    return 0;
}
