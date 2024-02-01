#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

constexpr size_t MAX_SIZE = 4001*100;
int node_count = 0;
Node node_pool[MAX_SIZE];

Node* new_node(int data) {
    node_pool[node_count].data = data;
    node_pool[node_count].next = nullptr;

    return &node_pool[node_count++];
}

class LinkedList {

    Node head;

public:
    LinkedList() = default;

    void init(int n) {
        head.next = nullptr;
        node_count = 0;

        while(n--) {
            int data;
            cin >> data;
            Node* ptr = &head;
            while(ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = new_node(data);
        }
    }

    void insert(int x, int y) {
        Node* ptr = &head;
        while(x-- && ptr != nullptr) {
            ptr = ptr->next;
        }
        while(y--) {
            int data;
            cin >> data;
            Node *node = new_node(data);
            node->next = ptr->next;
            ptr->next = node;
            ptr = node;
        }
    }

    void remove(int x, int y) {
        Node* prev_ptr = &head;
        while(x-- && prev_ptr != nullptr) {
            prev_ptr = prev_ptr->next;
        }
        Node* next_ptr = prev_ptr;
        while(y-- && next_ptr != nullptr) {
            next_ptr = next_ptr->next;
        }
        prev_ptr->next = next_ptr;
    }

    void append(int y) {
        Node* node = &head;
        while(node->next != nullptr) {
            node = node->next;
        }
        while(y--) {
            int data;
            cin >> data;
            node -> next = new_node(data);
        }
    }


    void print() const {
        Node* node = head.next;
        int cnt = 0;
        while(node != nullptr && cnt < 10) {
            cout << node->data << ' ';
            node = node->next;
            cnt++;
        }
        cout << '\n';
    }
};

int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        LinkedList ll;

        int n;
        cin >> n;
        ll.init(n);

        int m;
        cin >> m;
        while(m--) {
            char op;
            cin >> op;
            int x, y;
            switch(op) {
                case 'I':
                    cin >> x >> y;
                    ll.insert(x, y);
                    break;

                case 'D':
                    cin >> x >> y;
                    ll.remove(x, y);
                    break;

                case 'A':
                    cin >> y;
                    ll.append(y);
                    break;
            }
        }

        cout << "#" << test_case << ' ';
        ll.print();
    }
    return 0;
}