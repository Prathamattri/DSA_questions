//Linear Search in Linked List
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(){data=0;next=NULL;}
    Node(int x){ data=x;next=NULL;}
};

class List{
    Node* head;
    public:
        List(){head=NULL;}
        void insert(int);
        void LSearch(int);
        void display();
};

int main(){
    int size;
    cout<<"\nHow many elements do you want to insert: ";
    cin>>size;
    if(size>0){
        List l;
        cout<<"\nEnter the elements with spaces: ";
        for(int i=0;i<size;i++){
            int data;
            cin>>data;
            l.insert(data);
        }
        l.display();
        cout<<"\nEnter the element to be searched for : ";
        int key;
        cin>>key;
        l.LSearch(key);
    }
    return 0;
}

void List :: insert(int data){
    Node* newNode = new Node(data);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void List :: LSearch(int key){
    if(head == NULL){
        cout<<"\nEmpty List";
        return;
    }
    Node* temp = head;
    int ind=0;
    while(temp!=NULL){
        if(temp->data == key){
            cout<<"\nElement was found at index "<<ind;
            return;
        }
        ind++;
        temp=temp->next;
    }cout<<"\nElement was not found in the list"<<endl;
}

void List :: display(){
    if (head== NULL){
        cout<<"\nEmpty List";
        return;
    }
    Node* temp = head;
    cout<<"\nHead->";
    while(temp->next!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<temp->data;
}