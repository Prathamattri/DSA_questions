//BINARY SEARCH IN AN ARRAY
#include <iostream>
using namespace std;

int binarySearch(int* arr,int s,int e,int key ){
    if(s<=e){
        int mid = s+(e-s)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) return binarySearch(arr,0,mid-1,key);
        
        return binarySearch(arr,mid+1,e,key);
    }
    return -1;
}

int main(){
    
    int testArr[5] = {4,5,6,8,10};
    cout<<binarySearch(testArr,0,4,12);
    return 0;
}