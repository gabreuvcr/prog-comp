#include <iostream>
#include <queue>
#include <stack>

#define PUSH 1
#define POP 2

using namespace std;

bool not_sure(bool is_queue, bool is_priority_queue, bool is_stack) {
    return (is_queue && is_priority_queue) || 
           (is_stack && is_queue) || 
           (is_stack && is_priority_queue);
}

bool impossible(bool is_queue, bool is_priority_queue, bool is_stack) {
    return (!is_queue) && (!is_priority_queue) && (!is_stack);
}

void handle_case(int lines) {
    int op, element;
    queue<int> queue;
    priority_queue<int> priority_queue;
    stack<int> stack;
    bool is_queue = true, is_priority_queue = true, is_stack = true;

    for (int i = 0; i < lines; i++) {
        cin >> op >> element;

        if (op == PUSH) {
            queue.push(element);
            priority_queue.push(element);
            stack.push(element);
        }
        else if (op == POP) {
            if (!queue.empty() && queue.front() == element) {
                queue.pop();
            }
            else {
                is_queue = false;
            }

            if (!priority_queue.empty() && priority_queue.top() == element) {
                priority_queue.pop();
            }
            else {
                is_priority_queue = false;
            }

            if (!stack.empty() && stack.top() == element) {
                stack.pop();
            }
            else {
                is_stack = false;
            }
        }   
    }

    if (not_sure(is_queue, is_priority_queue, is_stack)) {
        cout <<  "not sure" << endl;
    }
    else if (impossible(is_queue, is_priority_queue, is_stack)) {
        cout << "impossible" << endl;
    }
    else if (is_queue) {
        cout << "queue" << endl;
    }
    else if (is_priority_queue) {
        cout << "priority queue" << endl;
    }
    else if (is_stack) {
        cout << "stack" << endl;
    }
}

int main() {
    int lines;

    while (cin >> lines) {
        handle_case(lines);
    }

    return 0;
}
