#include <iostream>
using namespace std;

struct node {
    int info;
    struct node* next;
};

typedef struct node node;

node* head = NULL;

void insertATfirst(int value) {
    node* temp = new node;
    temp->info = value;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void insertATbetween(int key, int value) {
    node* temp1 = new node;
    temp1->info = value;
    node* temp2 = head;

    while (temp2 != NULL && temp2->info != key) {
        temp2 = temp2->next;
    }

    if (temp2 == NULL) {
        cout << "Key " << key << " not found in the list." << endl;
        delete temp1;
        return;
    }

    temp1->next = temp2->next;
    temp2->next = temp1;
}

void display() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insertATfirst(10);
    display();
    insertATfirst(20);
    display();
    insertATbetween(20, 15);
    display();
    return 0;
}
