#include <bits/stdc++.h>
#include <iostream>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int find_number_of_soldiers(vector<int> graph[], vector<int> soldiers_per_point, int N, int source, int dest) {
    int highest_ping = 0;
    priority_queue<pair<int, int>> queue;
    vector<int> soldiers(N, INF);
    vector<bool> is_visited(N, false);

    queue.push(make_pair(-soldiers_per_point[source], source));
    soldiers[source] = soldiers_per_point[source];
    is_visited[source] = true;
    
    while (!queue.empty()) {
        pair<int, int> current = queue.top(); queue.pop();
        int current_point = current.second, current_soldiers = -current.first;

        for (int adj_point : graph[current_point]) {
            int adj_soldiers = soldiers_per_point[adj_point];
            int new_soldiers = adj_soldiers + soldiers[current_point];

            if (!is_visited[adj_point] || soldiers[adj_point] > new_soldiers) {
                soldiers[adj_point] = new_soldiers;
                queue.push(make_pair(-new_soldiers, adj_point));
            }
            is_visited[adj_point] = true;
        }

    }
    
    return soldiers[dest];
}

int main() { _
    int N, M, K, A;
    int source, dest;
    double P;

    cout.precision(3);
    
    while (cin >> N >> M >> K >> P) {
        vector<int> graph[N];

        int point_a, point_b, number_of_soldiers;
        
        for (int i = 0; i < M; i++) {
            cin >> point_a >> point_b;
            graph[point_a - 1].push_back(point_b - 1);
            graph[point_b - 1].push_back(point_a - 1);
        }

        vector<int> soldiers_per_point(N, 0);
        cin >> A;
        
        for (int i = 0; i < A; i++) {
            int point;
            cin >> point;
            soldiers_per_point[point - 1]++;
        }

        cin >> source >> dest;
        number_of_soldiers = find_number_of_soldiers(graph, soldiers_per_point, N, source - 1, dest - 1);
        
        if (number_of_soldiers > K) {
            cout << "0.000" << endl;
        } else {
            cout << fixed << pow(P, number_of_soldiers) << endl;
        }
    }
    
    return 0;
}
