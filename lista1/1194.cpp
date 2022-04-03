#include <iostream>

using namespace std;

typedef struct node {
    char value;
    node* left;
    node* right;

    node(char value) : value(value), left(nullptr), right(nullptr) {}
} node;

void free_tree(node* root) {
    if (root == nullptr) {
        return;
    }

    free_tree(root->left);
    free_tree(root->right);

    delete root;
}

char next_parent(string prefix, string infix) {
    int smallest_pos_prefix = prefix.length() - 1;
    char infix_parent = infix.at(infix.length() - 1);

    for (int i = 0; i < infix.length(); i++) {
        int position = prefix.find(infix.at(i));
        if (smallest_pos_prefix > position) {
            smallest_pos_prefix = position;
            infix_parent = infix.at(i);
        }
    }

    return infix_parent;
}

void rebuild_tree(node* root, string prefix, string infix) {
    int pos_root = infix.find(root->value);
    if (infix.length() <= 1) {
        return;
    }

    if (pos_root > 0) {
        string left_infix = infix.substr(0, pos_root);
        root->left = new node(next_parent(prefix, left_infix));
        rebuild_tree(root->left, prefix, left_infix);
    }
    if (pos_root < infix.length() - 1) {
        string right_infix = infix.substr(pos_root + 1);
        root->right = new node(next_parent(prefix, right_infix));
        rebuild_tree(root->right, prefix, right_infix);
    }
}

void postfix_traversal(node* root) {
    if (root->left != nullptr) {
        postfix_traversal(root->left);
    }
    if (root->right != nullptr) {
        postfix_traversal(root->right);
    }
    cout << root->value;
}

void handle_case() {
    int number_of_nodes;
    string prefix, infix;

    cin >> number_of_nodes >> prefix >> infix;

    node* root = new node(prefix.at(0));

    rebuild_tree(root, prefix, infix);

    postfix_traversal(root);
    cout << endl;

    free_tree(root);
}

int main() {
    int number_of_cases;

    cin >> number_of_cases;

    for (int i = 0; i < number_of_cases; i++) {
        handle_case();
    }

    return 0;
}
