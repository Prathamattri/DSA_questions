//Queue using arrays
#include <iostream>
using namespace std;

const int SIZE=5;

class Queue{
    int arr[SIZE],head,tail;
    public:
        Queue(){head=tail=0;}
        bool isEmpty(){return head==tail;}
        bool isFull(){return tail==SIZE;}
        void peek(){
            if(isEmpty()) cout<<"\nEmpty Queue";
            else cout<<arr[head];
        }
        void enqueue(int data){
            if(isFull()){
                cout<<"\nQueue Overflow";
                return;
            }
            arr[tail++]=data;
        }
        void dequeue(){
            if(isEmpty()){cout<<"\nQueue is empty";}
            cout<<"\nDequeued element is "<<arr[head];
            for(int i=head;i<tail-1;i++){
                arr[i]=arr[i+1];
            }
            tail--;
        }
        void display(){
            cout<<"\nElements are : [ ";
            for(int i=head;i<tail;i++){
                cout<<arr[i]<<" ";
            }cout<<"]";
        }
};

int main(){
    Queue q;
    int ch,num;
    do{
        cout<<"\n1.Enqueue\n2.Dequeue\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n7.Exit\nEnter Choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cin>>num;
            q.enqueue(num);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            if(q.isEmpty()) cout<<"\nQueue is empty";
            else cout<<"\nQueue is not empty";
            break;
        case 4:
            if(q.isFull()) cout<<"\nQueue is full";
            else cout<<"\nQueue is not full";
            break;
        case 5:
            q.display();
            break;
        case 6:
            q.peek();
            break;
        case 7:
            cout<<"\nExiting...";
            break;
        default:
            cout<<"\nEnter correct input";
            break;
        }
    }while(ch!=7);
    return 0;
}