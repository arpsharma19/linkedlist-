// // //insertion of linked list at first position:
// #include <iostream>
// using namespace std;

// struct node {
//     int info;         
//     struct node *next; 
// };
// // Typecasting:
// typedef struct node node;

// node *head = NULL; // Initialize head to NULL

// void insertATfirst(int value) {
//     node *temp = new node; // Create a new node

//     // Initialize the new node
//     temp->info = value;
//     temp->next = NULL;

//     if (head == NULL) {  
//         head = temp;     
//     } else {             
//         temp->next = head; 
//         head = temp;       
//     }
// }

// void display() {
//     node *temp = head; 
//     while (temp != NULL) { 
//         cout << temp->info << " "; 
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main() {
//     insertATfirst(10); 
//     display();         

//     insertATfirst(5);  
//     display();         

//     insertATfirst(0);  
//     display();         

//     insertATfirst(-10); 
//     display();          

//     return 0;
// }
// // insertion of node at last position:
// #include <iostream>
// using namespace std;
// struct node{
//     int info;
//     struct node *next;
// };
// typedef struct node node;
// node *head=NULL;
// void insertATlast(int value){
//     node *temp;
//     temp=(node*)malloc(sizeof(node));
//     temp->info=value;
//     temp->next=NULL;
//     if(head==NULL){
//         head=temp;
//     }
//     else{
//         node *temp2=head;
//         while(temp2->next!=NULL){
//             temp2=temp2->next;
//         }
//     temp=temp2->next;
//     }

// }
// void display(){
//     node *temp=head;
//     while(temp=NULL){
//         cout<<temp->info<<" ";
//         temp=temp->next;
//     }
//     cout<<endl;

// }
// int main(){
//     insertATlast(12);
//     //display();
//     insertATlast(13);
//     //display();
//     insertATlast(15);
//     display();
//     return 0;
// }
#include <iostream>
using namespace std;
struct node{
    int info;
    struct node *next;
};
typedef struct node node;
node *head=NULL;
void insertATfirst(int value){
    node *temp=new node;
    temp->info=value;
    temp->next=NULL;
    if(head==NULL){
        head=temp;

    }
    else{
        temp->info=value;
        temp->next=head;
        head=temp;
    }
}
void insertATbetween(int key,int value){
    node *temp1=new node;
    temp1->info=value;
    node *temp2=head;
    while(temp2->info!=key){
        temp2=temp2->next;
    }
    temp1->next=temp2;
    temp2->next=temp1;

}
void display(){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->info<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    insertATfirst(10);
    display();
    insertATfirst(20);
    display();
    insertATbetween(20,15);
    display();
    return 0;
}