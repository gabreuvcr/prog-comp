#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int find_shortest_path(vector<pair<int, int>> graph[], int number_of_entrances) {
    int min_cost = 0;

    priority_queue<pair<int, int>> queue;
    vector<bool> is_visited(number_of_entrances, false);

    queue.push(make_pair(0, 0));

    while (!queue.empty()) {
        pair<int, int> x = queue.top(); queue.pop();
        int x_entrance = x.second, x_cost = x.first;

        if (is_visited[x_entrance]) continue;

        min_cost += -x_cost;
        is_visited[x_entrance] = true;

        for (pair<int, int> adj : graph[x_entrance]) {
            int adj_entrance = adj.first, adj_cost = adj.second;
            queue.push(make_pair(-adj_cost, adj_entrance));
        }
    }

    return min_cost;
}

void invert_cost(vector<pair<int, int>> graph[], int number_of_entrances) {
    for (int i = 0; i < number_of_entrances; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            graph[i][j].second = -graph[i][j].second;
        }
    }
}

int main() {
    int number_of_galleries;

    cin >> number_of_galleries;

    int number_of_entrances = (1 + sqrt(1 + 8 * number_of_galleries)) / 2;

    vector<pair<int, int>> graph[number_of_entrances];

    int node_a, node_b, cost;
    
    while(cin >> node_a >> node_b >> cost) {
        graph[node_a - 1].push_back(make_pair(node_b - 1, cost));
        graph[node_b - 1].push_back(make_pair(node_a - 1, cost));
    }

    int min_cost = find_shortest_path(graph, number_of_entrances);
    invert_cost(graph, number_of_entrances);
    int max_cost = abs(find_shortest_path(graph, number_of_entrances));

    cout << max_cost << endl;
    cout << min_cost << endl;
 
    return 0;
}
