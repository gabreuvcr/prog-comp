#include <bits/stdc++.h>
#include <iostream>

#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

#define LEFT(K) K + 0 
#define UP(K) K + 1 
#define RIGHT(K) K + 2 
#define DOWN(K) K + 3

using namespace std;

int M, N, K;

typedef struct sensor {
    int x;
    int y;
    int radius;

    sensor(int x, int y, int radius) : x(x), y(y), radius(radius) {}
    sensor() : x(0), y(0), radius(0) {}
} sensor;

void dfs(int node, vector<int>* graph, bool* is_visited, bool* barrier) {
    is_visited[node] = true;

    if (node == RIGHT(K) || node == DOWN(K)) {
        (*barrier) = true; return;
    }

    for (int adj : graph[node]) {
        if (!is_visited[adj]) {
            dfs(adj, graph, is_visited, barrier);
        }
    }
}

bool find_path(vector<int>* graph) {
    bool* is_visited = new bool[K + 4];
    bool barrier1 = false, barrier2 = false;
    
    for (int i = 0; i < K + 4; i++) is_visited[i] = false;

    dfs(LEFT(K), graph, is_visited, &barrier1);
    
    for (int i = 0; i < K + 4; i++) is_visited[i] = false;
    
    dfs(UP(K), graph, is_visited, &barrier2);
    

    delete[] is_visited;
    return !(barrier1 || barrier2);
}

bool touch_wall_left(sensor p1) {
    return 0 >= (p1.x - p1.radius);
}

bool touch_wall_up(sensor p1) {
    return N <= (p1.y + p1.radius);
}

bool touch_wall_right(sensor p1) {
    return M <= (p1.x + p1.radius);
}

bool touch_wall_down(sensor p1) {
    return 0 >= (p1.y - p1.radius);
}

bool sensors_intersect(sensor p1, sensor p2) {
    return pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) <= pow(p1.radius + p2.radius, 2);
}

vector<int>* create_graph(sensor sensors[]) {
    vector<int>* graph = new vector<int>[K + 4];

    for (int s = 0; s < K; s++) {
        if (touch_wall_left(sensors[s])) {
            graph[s].push_back(LEFT(K));
            graph[LEFT(K)].push_back(s);
        }
        if (touch_wall_up(sensors[s])) {
            graph[s].push_back(UP(K));
            graph[UP(K)].push_back(s);
        }
        if (touch_wall_right(sensors[s])) {
            graph[s].push_back(RIGHT(K));
            graph[RIGHT(K)].push_back(s);
        }
        if (touch_wall_down(sensors[s])) {
            graph[s].push_back(DOWN(K));
            graph[DOWN(K)].push_back(s);
        }
    }

    for (int s1 = 0; s1 < K; s1++) {
        for (int s2 = s1 + 1; s2 < K; s2++) {
            if (sensors_intersect(sensors[s1], sensors[s2])) {
                graph[s1].push_back(s2);
                graph[s2].push_back(s1);
            }
        }
    }

    return graph;
}


int main() { _

    cin >> M >> N >> K;

    sensor sensors[K];

    for (int i = 0; i < K; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        sensors[i] = sensor(x, y, s);
    }

    vector<int>* graph = create_graph(sensors);

    bool possible = find_path(graph);
    
    cout << (possible ? "S" : "N") << endl;

    delete[] graph;

    return 0;
}
