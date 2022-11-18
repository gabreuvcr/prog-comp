#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

map<string, int> dist = {
    {"A", 1},
    {"Bb", 2}, {"A#", 2},
    {"B", 3}, {"Cb", 3},
    {"C", 4}, {"B#", 4},
    {"Db", 5}, {"C#", 5},
    {"D", 6},
    {"Eb", 7}, {"D#", 7},
    {"E", 8}, {"Fb", 8},
    {"F", 9}, {"E#", 9},
    {"Gb", 10}, {"F#", 10},
    {"G", 11},
    {"Ab", 12}, {"G#", 12}
};

const int num_notes = 12;

bool is_plagiarism(string m, string s) {
    if (m.find(s) != string::npos)
        return true;
    return false;
}

int main() { _

    int M, T;

    while (cin >> M >> T and M != 0 and T != 0) {
        vector<string> notes(M);
        vector<string> snippet_notes(T);
        string space = " ";

        for (int i = 0; i < M; i++) {
            cin >> notes[i];
        }
        for (int i = 0; i < T; i++) {
            cin >> snippet_notes[i];
        }

        int i;
        string notes_dist = "";
        string snippet_notes_dist = "";

        i = 1;
        while (i < M) {
            int note_distance = dist[notes[i]] - dist[notes[i - 1]];
            if (note_distance < 0) note_distance += num_notes;

            notes_dist += (space + to_string(note_distance));
            i++;
        }
        
        
        i = 1;
        while (i < T) {
            int snippet_note_distance = dist[snippet_notes[i]] - dist[snippet_notes[i - 1]];
            if (snippet_note_distance < 0) snippet_note_distance += num_notes;
            
            snippet_notes_dist += (space + to_string(snippet_note_distance));
            i++;
        }

        cout << (is_plagiarism(notes_dist, snippet_notes_dist) ? "S" :  "N") << endl;
    }
    
    
    return 0;
}
