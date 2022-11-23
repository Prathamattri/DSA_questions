//Tower of Hanoi
#include <iostream>
using namespace std;

void towerOfHanoi(int n,char a,char b,char c){
    if(n==1){cout<<a<<"->"<<c<<endl;}
    else{
        towerOfHanoi(n-1,a,c,b);
        towerOfHanoi(1,a,b,c);
        towerOfHanoi(n-1,b,a,c);
    }
}

int main(){
    int n;
    char a,b,c;
    cout<<"\nEnter number of disks: ";
    cin>>n;
    cout<<"\nEnter the characters for the peg with spaces: ";
    cin>>a>>b>>c;
    cout<<"\nSolution: "<<endl;
    towerOfHanoi(n,a,b,c);
    return 0;
}