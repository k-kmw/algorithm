#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

constexpr size_t MAX_SIZE = 2001;
int node_count = 0;
Node node_pool[MAX_SIZE];

Node* new_node(int data) {
    node_pool[node_count].data = data;
    node_pool[node_count].next = nullptr;
    return &node_pool[node_count++];
}


class LinkedList {
public:

    Node head;

    LinkedList() = default;

    void init(int n) {
        head.next = nullptr;
        Node* ptr = nullptr;
        node_count = 0;
        while (n--) {
            int data;
            cin >> data;
            Node* newNode = new_node(data);
            if (head.next == nullptr) { // 리스트가 비어 있으면
                head.next = newNode;
            }
            else { // 리스트가 비어있지 않으면
                ptr->next = newNode;
            }
            ptr = newNode;
        }
    }

    void print() const {

        Node* ptr = head.next;
        while (ptr != nullptr) {
            cout << ptr->data << ' ';
            ptr = ptr->next;
        }
    }

    void insert(int idx, int data) {
        Node* ptr = &head;
        while (idx--) {
            ptr = ptr->next;
        }
        Node* newNode = new_node(data);
        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    void remove(int idx) {
        Node* prev_ptr = &head;
        while (idx--) {
            prev_ptr = prev_ptr->next;
        }
        prev_ptr->next = prev_ptr->next->next;
    }

    void update(int idx, int data) {
        Node* ptr = head.next;
        while (idx--) {
            ptr = ptr->next;
        }
        ptr->data = data;
    }

    void printPos(int idx) const {
        Node* ptr = head.next;
        while (idx > 0 && ptr->next != nullptr) {
            ptr = ptr->next;
            idx--;
        }
        if (idx != 0) {
            cout << -1 << '\n';
        }
        else {
            cout << ptr->data << '\n';
        }
    }
};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        cout << "#" << test_case << " ";
        int n, m, l;
        cin >> n >> m >> l;
        LinkedList ll = LinkedList();
        ll.init(n);

        while (m--) {
            char op;
            cin >> op;
            switch (op) {
                case 'I':
                    int idx, data;
                    cin >> idx >> data;
                    ll.insert(idx, data);
                    break;
                case 'D':
                    cin >> idx;
                    ll.remove(idx);
                    break;
                case 'C':
                    cin >> idx >> data;
                    ll.update(idx, data);
                    break;
            }
        }
        ll.printPos(l);
        // ll.print();
    }
}