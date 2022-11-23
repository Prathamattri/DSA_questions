//Linear Search in an array
#include <iostream>
using namespace std;

int LSearch(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key) return i;
    }return -1;
}

int main(){
    
    int testArr[5] = {9,8,7,6,5};
    cout<<LSearch(testArr,5,6)<<endl;
    cout<<LSearch(testArr,5,4);
    return 0;
}