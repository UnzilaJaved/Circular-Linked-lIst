#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class circular {
public:
    node* tail;

    circular() {
        this->tail = NULL;
    }

    circular(node* &tail) {
        this->tail = NULL;
    }

    void insertData(int value, int data) {
        if (tail == NULL) {
            node* temp = new node(data);
            temp->next = temp;
            tail = temp;
        } else {
            int cnt = 1;
            node* current = tail;
            while (current->data != value) {
                current = current->next;
                cnt++;
            }
            node* temp = new node(data);
            node* forward = current->next;
            temp->next = forward;
            current->next = temp;
        }
    }

    void deleteNode(int value) {
        node* prev = tail;
        node* current = tail->next;
        while (current->data != value) {
            prev = current;
            current = current->next;
        }
        if (tail == current) {
            tail = prev;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }

    void printing() {
        cout << tail->data << endl;
        node* temp = tail->next;
        while (temp != tail) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};

int main() {
    node* tail = NULL;
    circular cc(tail);
    cc.insertData(6, 5);
    cc.insertData(5, 6);
    cc.insertData(6, 7);
    cc.insertData(7, 9);
    cc.printing();
    cc.deleteNode(6);
    cc.printing();
    return 0;
}

