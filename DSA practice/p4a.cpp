//Stacks using Arrays
#include <iostream>
using namespace std;

class Stack{
    int arr[100],n=100,top=-1;
    public:
        void push(int data){
            if(top>=n-1){
                cout<<"\nStack Overflow, Cannot push";
            }else{
                arr[++top]=data;
            }
        }
        void pop(){
            if(top <= -1){
                cout<<"\nStack Underflow, Cannot pop";
            }else{
                cout<<"\nPopped element is "<<arr[top--];
            }
        }
        void peek(){
            if(top <= -1){
                cout<<"\nEmpty Stack";
            }else{
                cout<<"\nElement at top is "<<arr[top];
            }
        }
        void display(){
            if(top == -1){cout<<"\nEmpty Stack"; return;}

            cout<<"\nElement in the stack are: top->"; 
            for(int i=top;i>=0;i--){
                cout<<arr[i]<<" ";
            }
        }
        bool isEmpty(){
            if(top == -1){
                cout<<"\nStack is empty";
                return true;
            }else{
                cout<<"\nStack is not empty";
                return false;
            }
        }
        bool isFull(){
            if(top>=n-1){
                cout<<"\nStack is full";
                return true;
            }else{
                cout<<"\nStack is not full";
                return false;
            }
        }
};

int main(){
    Stack s;
    s.isEmpty();
    int size;
    cout<<"\nHow many elements do you want to insert: ";
    cin>>size;

    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        s.push(data);
    }
    s.display();
    s.isEmpty();
    s.peek();
    s.pop();
    s.display();
    s.isFull();
    return 0;
}