#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);
#define SEARCH 1
#define CHANGE 2

using namespace std;

const int MAX = 100000;
const int MAX_MONSTERS = 50;

int search_query(vector<set<int>> &monsters_position_by_type, int M, int left, int right) {
    int num_monsters = 0;
    for (int i = 1; i <= M; i++) {
        set<int>::iterator it = monsters_position_by_type[i].lower_bound(left);
        set<int>::iterator end = monsters_position_by_type[i].end();
        if (it != end and *it <= right)
            num_monsters++;
    }
    return num_monsters;
}

void change_query(vector<set<int>> &monsters_position_by_type, vector<int> &trail, int coord, int type) {
    monsters_position_by_type[trail[coord]].erase(coord);
    trail[coord] = type;
    monsters_position_by_type[trail[coord]].insert(coord);
}

int main() { _

    int N, Q, M;
    cin >> N >> Q >> M;
    vector<int> trail(N + 1);
    vector<set<int>> monsters_position_by_type(MAX_MONSTERS + 1);

    for (int i = 1; i <= N; i++) {
        cin >> trail[i];
        monsters_position_by_type[trail[i]].insert(i);
    }

    for (int q = 0; q < Q; q++) {
        int O, F, S;
        cin >> O >> F >> S;
        int num_monsters;
        switch (O) {
            case SEARCH:
                num_monsters = search_query(monsters_position_by_type, M, F, S);
                cout << num_monsters << endl;
                break;
            case CHANGE:
                change_query(monsters_position_by_type, trail, F, S);
                break;
        }
    }
    
    return 0;
}
