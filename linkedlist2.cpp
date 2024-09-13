#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;
};

Node* createNode(int coeff, int pow) {
    Node* newNode = new Node;
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(Node*& head, int coeff, int pow) {
    Node* newNode = createNode(coeff, pow);
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayPolynomial(Node* poly) {
    Node* temp = poly;
    while (temp != NULL) {
        if (temp->coeff != 0) {
            cout << temp->coeff << "x^" << temp->pow;
            if (temp->next != NULL && temp->next->coeff > 0) {
                cout << " + ";
            }
        }
        temp = temp->next;
    }
    cout << endl;
}

Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp1 = poly1;
    Node* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->pow > temp2->pow) {
            insertTerm(result, temp1->coeff, temp1->pow);
            temp1 = temp1->next;
        } else if (temp1->pow < temp2->pow) {
            insertTerm(result, temp2->coeff, temp2->pow);
            temp2 = temp2->next;
        } else {
            int sumCoeff = temp1->coeff + temp2->coeff;
            if (sumCoeff != 0) {
                insertTerm(result, sumCoeff, temp1->pow);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        insertTerm(result, temp1->coeff, temp1->pow);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        insertTerm(result, temp2->coeff, temp2->pow);
        temp2 = temp2->next;
    }

    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    insertTerm(poly1, 3, 3);
    insertTerm(poly1, 2, 2);
    insertTerm(poly1, 1, 1);

    insertTerm(poly2, 2, 2);
    insertTerm(poly2, 3, 1);
    insertTerm(poly2, 1, 0);

    cout << "Polynomial 1: ";
    displayPolynomial(poly1);

    cout << "Polynomial 2: ";
    displayPolynomial(poly2);

    Node* result = addPolynomials(poly1, poly2);
    cout << "Resultant Polynomial after addition: ";
    displayPolynomial(result);

    return 0;
}




// inserting sorted linked list:
// #include <iostream>
// using namespace std;
// struct node{
//     int info;
//     struct node *next;

// };
// typedef struct node node;
// //node *head=NULL;
// void insertATsort(node **head,int value){
//     node *temp=(node*)malloc(sizeof(node));
//     *temp2=head;
//     temp->info=value;
//     if(*head==NULL){
//         *head=temp //|| *head->info > value
//     }
//     else if((*head)->next==NULL){
//         if(*head->info >value){
//                 temp->next=*head;
//                 *head=temp;
//         }
//         else{
//             (*head)->next=temp;
//         }
//     }
//     else if((*head)->info>value){
//         temp->next=*head;
//         *head=temp;
//     }
//     else{
//         while(temp2->next!=NULL && temp2->next->info<value){
//             temp2=temp2->next;
//         }
//         temp->next=temp2->next;
//         temp2->next=temp;
//     }
//     }

// int main(){
//     node *head=NULL;
//     insertATsort(&head,10);
//     return 0;
// }
