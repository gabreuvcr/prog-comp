#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

typedef struct Node {
    Node* children[26];
    bool is_end_of_word;
} Node;

int char_to_index(char c) {
    return c - 'a';
}

Node* new_node() {
    Node* node = new Node;

    for (int i = 0; i < 26; i++) node->children[i] = NULL;
    node->is_end_of_word = false;

    return node;
}

bool insert(Node* root, string text) {
    Node* tmp = root;
    bool suffix = false;
    bool passed_end_of_word = false;
    
    for (int i = 0; i < text.length(); i++) {
        int index = char_to_index(text[i]);

        if (!tmp->children[index]) {
            if(tmp->is_end_of_word) {
                suffix = true;
                passed_end_of_word = true;
            }
            if (!passed_end_of_word) {
                suffix = false;
            }
            
            tmp->children[index] = new_node();            
        } else {
            suffix = true;
        }

        tmp = tmp->children[index];
    }

    tmp->is_end_of_word = true;
    return suffix;
}

int main() { _

    vector<string> words;
    int N;

    while (cin >> N) {
        if (N == 0) break;

        Node* root = new_node();
        bool is_good = true;
        
        for (int i = 0; i < N; i++) {
            string text; cin >> text;

            if (is_good && insert(root, text)) {
                is_good = false;
            }
        }

        is_good ? cout << "Conjunto Bom" << endl : cout << "Conjunto Ruim" << endl;
    }
    
    return 0;
}
