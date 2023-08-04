#include<iostream>
#include<algorithm>
using namespace std;

    // Up-Heapify: at insertion
    void heapify(int arr[], int n, int i)  
    {   
        int childIndex=i;
      while(childIndex>0){
          int parentIndex=(childIndex-1)/2;
          if(arr[parentIndex]<arr[childIndex]){
              swap(arr[parentIndex],arr[childIndex]);
          }
          else{
              break;
          }
          childIndex=parentIndex;
      }
    }

    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=1;i<n;i++){
            heapify(arr,n,i);
        }
        
    }

    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        
        // Down-Heapify: at removal
        int size=n;
        while(size>1){
            int temp=arr[0];
            arr[0]=arr[size-1];
            arr[size-1]=temp;
            size--; 
            int parentIndex=0;
            int lChild = 2*parentIndex+1;
            int rChild = 2*parentIndex+2;
            while(lChild<size){
                int maxIndex=parentIndex;
                if(arr[maxIndex]<arr[lChild]){
                    maxIndex=lChild;
                }
                if(rChild<size && arr[rChild]>arr[maxIndex]){
                    maxIndex=rChild;
                }
                if(maxIndex==parentIndex){
                    break;
                }
                swap(arr[parentIndex],arr[maxIndex]);
                
                parentIndex=maxIndex;
                lChild = 2*parentIndex+1;
                rChild = 2*parentIndex+2;
            }
        }         
    }

