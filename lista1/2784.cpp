#include <iostream>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

int find_lowest_ping(vector<pair<int, int>> graph[], int island_with_server) {
    int lowest_ping = INF;

    for (pair<int, int> adj : graph[island_with_server]) {
        if (adj.second < lowest_ping) {
            lowest_ping = adj.second;
        }
    }
    return lowest_ping;
}

int find_highest_ping(vector<pair<int, int>> graph[], int number_of_islands, int island_with_server) {
    int highest_ping = 0;
    priority_queue<pair<int, int>> queue;
    vector<int> pings(number_of_islands, INF);
    vector<bool> is_visited(number_of_islands, false);

    queue.push(make_pair(0, island_with_server));
    pings[island_with_server] = 0;
    is_visited[island_with_server] = true;
    
    while (!queue.empty()) {
        pair<int, int> current = queue.top(); queue.pop();
        int current_island = current.second, current_ping = -current.first;

        for (pair<int, int> adj : graph[current_island]) {
            int adj_island = adj.first, adj_ping = adj.second;
            int new_ping = adj_ping + pings[current_island];

            if (!is_visited[adj_island] || pings[adj_island] > new_ping) {
                pings[adj_island] = new_ping;
                queue.push(make_pair(-new_ping, adj_island));
            }
            is_visited[adj_island] = true;
        }

    }
    
    for (int ping : pings) {
        if (ping > highest_ping) highest_ping = ping;
    }

    return highest_ping;
}

int main() {
    int number_of_islands, number_of_cables, island_with_server;

    cin >> number_of_islands >> number_of_cables;

    vector<pair<int, int>> graph[number_of_islands];

    int island_a, island_b, ping;
    
    for (int i = 0; i < number_of_cables; i++) {
        cin >> island_a >> island_b >> ping;
        graph[island_a - 1].push_back(make_pair(island_b - 1, ping));
        graph[island_b - 1].push_back(make_pair(island_a - 1, ping));
    }

    cin >> island_with_server;
    island_with_server--;

    int lowest_ping = find_lowest_ping(graph, island_with_server);
    int highest_ping = find_highest_ping(graph, number_of_islands, island_with_server);
    cout << highest_ping - lowest_ping << endl;

    return 0;
}
