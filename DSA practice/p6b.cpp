//Queue using Linked List
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(){data=0;next=NULL;}
    Node(int x){data=x;next=NULL;}
};

class Queue{
    Node *head,*tail;
    public:
        Queue(){head=tail=NULL;}
        void enqueue(int x){
            Node* newNode = new Node(x);
            if(isEmpty()){
                head=tail=newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
        }
        void dequeue(){
            if(isEmpty()){ cout<<"\nUnderflow";    return;}
            Node *temp = head;
            head=head->next;
            if(head==NULL) tail=NULL;
            delete(temp);
            cout<<"\nElement deleted from head";
        }
        int peek(){
            if(isEmpty()) {cout<<"\nEmpty Queue"; return -1;}
            else cout<<"\nElement at head : "<<head->data;
            return head->data;
        }
        bool isEmpty(){
            return tail==NULL;
        }
        void display(){
            Node *temp = head;
            if(isEmpty()) {cout<<"\nEmpty Queue"; return;}
            cout<<"\nElements in the queue: Head -> ";
            while(temp->next != NULL){
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }cout<<temp->data<<" -> Tail"<<endl;
        }
};

int main(){
    Queue q;
    int ch,num;
    do{
        cout<<"\n1.Enqueue\t2.Dequeue\t3.Peek\t4.IsEmpty\t5.Display\t6.Exit\nEnter Choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\nEnter element to be inserted: ";
            cin>>num;   q.enqueue(num);    break;
        case 2:
            q.dequeue();    break;
        case 3:
            q.peek();    break;
        case 4:
            if(q.isEmpty()) cout<<"\nEmpty Queue";
            else cout<<"\nQueue isn't empty";
            break;
        case 5:
            q.display();    break;
        case 6:
            cout<<"\nExiting..";    break;
        default:
            break;
        }
    }while(ch!=6);
    return 0;
}