//Fibonnaci Using Recursion
#include <iostream>
using namespace std;

int fibonnaci(int n){
    if(n==1 || n==2) return 1;
    return fibonnaci(n-1)+fibonnaci(n-2);
}

int main(){
    cout<<"\nFibonnaci Series: "<<endl;
    int n;
    cout<<"\nEnter the number of terms to print: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<fibonnaci(i)<<" ";
    }
    return 0;
}