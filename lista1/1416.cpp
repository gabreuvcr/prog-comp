#include <bits/stdc++.h>
#include <iostream>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int lower_limit, upper_limit;

typedef struct team {
    int solved;
    int score;
    int attempts;
    int total_time;

    team() : solved(0), score(0), attempts(0), total_time(0) {}
} team;

void find_limits(vector<team> teams) {
    for (int i = 0; i < teams.size() - 1; i++) {
        if (teams[i].solved == 0) continue;
        for (int j = i + 1; j < teams.size(); j++) {
            if (teams[j].solved == 0) continue;

            if ((teams[i].solved == teams[j].solved)) {
                int N, D;

                if (teams[i].score == teams[j].score) {
                    lower_limit = 20;
                    upper_limit = 20;
                    return;
                }

                if (teams[i].score < teams[j].score) {
                    N = teams[i].total_time - teams[j].total_time;
                    D = teams[j].attempts - teams[i].attempts;
                } else if (teams[i].score >= teams[j].score) {
                    N = teams[j].total_time - teams[i].total_time;
                    D = teams[i].attempts - teams[j].attempts;
                }

                if (D == 0) continue;

                int u_limit = ceil((float)N / D);
                int l_limit = floor((float)N / D);
                if (D < 0 && upper_limit > u_limit - 1) {
                    upper_limit = u_limit - 1;
                } else if (D > 0 && lower_limit < l_limit + 1) {
                    lower_limit = l_limit + 1;
                }
            }
        }
    }
}

int main() { _
    int T, P;

    while (cin >> T >> P) {
        if (T == 0 && P == 0) break;

        lower_limit = 1;
        upper_limit = INF;
        vector<team> teams;

        for (int t = 0; t < T; t++) {
            team team;
            for (int p = 0; p < P; p++) {
                string description;
                cin >> description;
                int div = description.find("/");
                if (description.at(0) == '0' || description.at(div + 1) == '-') continue;
                int A = stoi(description.substr(0, div));
                int S = stoi(description.substr(div + 1));
                team.solved++;
                team.attempts += A;
                team.score += S + 20 * (A - 1);
                team.total_time += S;
            }
            teams.push_back(team);
        }

        find_limits(teams);
        cout << lower_limit << " ";
        if (upper_limit == INF){
            cout << "*" << endl;
        } else {
            cout << upper_limit << endl;
        }
    }

    return 0;
}
