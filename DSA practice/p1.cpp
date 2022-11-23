//Sorting Algos

#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp= a;
    a=b;
    b=temp;
}
void printAr(int arr[],int n){
    cout<<"\nElements are:\t[ ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<"]";
}

void bubbleSort(int*,int);
void selectionSort(int*,int);
void insertionSort(int*,int);
void mergeSort(int*,int,int);
void merge(int*,int,int,int);
void quickSort(int*,int,int);
int partition(int*,int,int);

int main(){
    int testArr[5] = {9,8,7,6,5};
    
    cout<<"\nBefore Sort:";
    printAr(testArr,5);
    
    // bubbleSort(testArr,5);
    // selectionSort(testArr,5);
    // insertionSort(testArr,5);
    // mergeSort(testArr,0,4);
    quickSort(testArr,0,4);
    
    cout<<"\nAfter Sort:";
    printAr(testArr,5);
    char ch;
    cin>>ch;
    return 0;
}


// BUBBLE SORT FUNCTION
void bubbleSort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        if(flag==0) break;
    }
}
// ------------------------------


// SELECTION SORT FUNCTION
void selectionSort(int* arr,int n){
    for(int i=0;i<n-1;i++){
        int min_ind=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min_ind]){
                min_ind=j;
            }
        }
        swap(arr[min_ind],arr[i]);
    }
}
// ------------------------------

// INSERTION SORT FUNCTION
void insertionSort(int* arr,int n){
    for(int i=1;i<n;i++){
        int atCurrInd=arr[i];
        int j=i;
        while(j>0 && atCurrInd<=arr[j]){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=atCurrInd;
    }
}
// ------------------------------

// MERGE SORT FUNCTIONS 


void mergeSort(int* arr,int s,int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,mid,e);
}
void merge(int* arr,int s,int mid,int e){
    int len1=mid-s+1;
    int len2=e-mid;

    int first[len1],second[len2];
    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }
    k=mid+1;
    for(int i=0;i<len1;i++){
        second[i]=arr[k++];
    }

    int index1=0;
    int index2=0;
    k=s;
    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[k++]=first[index1++];
        }else{
            arr[k++]=second[index2++];
        }
    }

    while(index1<len1){
        arr[k++]=first[index1++];
    }
    while(index2<len2){
        arr[k++]=first[index2++];
    }
}
// ------------------------------

// QUICK SORT FUNCTIONS
int partition(int* arr, int s,int e){
    int pivot = arr[e];
    int i=s-1;

    for(int j=s;j<e;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}
void quickSort(int* arr,int s,int e){
    if(s<e){
        int pi=partition(arr,s,e);

        quickSort(arr,s,pi-1);
        quickSort(arr,pi+1,e);
    }
}

// ------------------------------