//Stacks using Linked Lists
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){data=x;next=NULL;}
};
class Stack{
    Node* top;
    public:
        Stack(){top=NULL;}
        void push(int data){
            Node* newNode = new Node(data);
            if(top==NULL){ top = newNode;return;}
            newNode->next=top;
            top=newNode;
        }
        void pop(){
            if(top==NULL){cout<<"\nStack Underflow, cannot pop";return;}
            cout<<"\nPopped element is "<<top->data<<endl;
            Node* temp=top;
            top=top->next;
            delete(temp);
        }
        bool isEmpty(){
            return top==NULL;
        }
        void peek(){
            if(isEmpty()){cout<<"\nEmpty Stack";}
            else{cout<<"\nElement at top is "<<top->data<<endl;}
        }
        void display(){
            if(isEmpty()){cout<<"\nEmpty Stack";return;}
            Node* temp=top;cout<<"\nElements in stack\ntop -> ";
            while(temp->next != NULL){
                cout<<temp->data<<" -> ";
                temp=temp->next;
            }cout<<temp->data;
        }
};

int main(){
    Stack s;
    int size;
    if(s.isEmpty())
        cout<<"\nEmpty Stack";
    else
        cout<<"\nStack is not empty";

    cout<<"\nHow many elements do you want to insert: ";
    cin>>size;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        s.push(data);
    }
    
    s.display();
    if(s.isEmpty())
        cout<<"\nEmpty Stack";
    else
        cout<<"\nStack is not empty";

    s.peek();
    s.pop();
    s.display();
    return 0;
}