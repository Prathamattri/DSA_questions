//Circular Queue using Array
#include <iostream>
using namespace std;

const int SIZE=5;
class Queue{
    int arr[SIZE],head,tail;
    public:
        Queue(){head=tail=-1;}
        void enqueue(int x){
            if(isFull()){
                cout<<"\n\tQueue is Full"<<endl;
            }else{
                if(head == -1) head=0;
                tail=(tail+1)%SIZE;
                arr[tail]=x;
            }
        }
        void dequeue(){
            if(isEmpty()) cout<<"\n\tQueue is empty -- Underflow";
            else{
                if(head==tail) head=tail=-1;
                else head = (head + 1) % SIZE;
            }
        }
        void peek(){
            if(isEmpty()) cout<<"\n\tQueue is empty";
            else cout<<"\nElement at head : "<<arr[head];
        }
        bool isFull(){
            if(head == 0 && tail == SIZE-1) return true;
            if(head == tail+1) return true;
            return false;
        }
        bool isEmpty(){
            return head==-1;
        }
        void display(){
            if(isEmpty()) cout<<"\nQueue is empty";
            else{
                cout<<"\n\tElements in the queue : Head -> ";
                for(int i=head;i!=tail;i=(i+1)%SIZE){
                    cout<<arr[i]<<" -> ";
                }cout<<arr[tail]<<" -> tail";
            }
        }
};

int main(){
    Queue q;
    int ch,num;
    do{
        cout<<"\n1.Enqueue\t2.Dequeue\t3.isEmpty\t4.isFull\t5.Display\t6.Peek\t7.Exit\n\tEnter Choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"\n\tEnter element to be enqueued: ";
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