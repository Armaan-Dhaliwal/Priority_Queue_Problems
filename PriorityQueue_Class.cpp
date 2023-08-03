#include<iostream>
#include<vector>
using namespace std;

// Min Heap
class PriorityQueue{
    vector<int> pq;

    public:
    int getSize(){
        return pq.size();
    }

    bool isEmpty(){
        return pq.size()==0;
    }

    int getMin(){
        if(isEmpty()){
            return -1;
        }
        return pq[0];
    }
    
    void insert(int x){
        pq.push_back(x);
        int childIndex = pq.size()-1;
        while(childIndex  > 0){
            int parentIndex=(childIndex-1)/2;
            if(pq[childIndex]<pq[parentIndex] ){
                int temp=pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    }

    int removeMin(){
        if(isEmpty()){
            return -1;
        }
        
        int ans = pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        // Down Heapify:
        int parentIndex = 0;
        int lChild = parentIndex*2 + 1;
        int rChild = parentIndex*2 + 2;
        while(lChild<pq.size()){
            int minIndex = parentIndex;
            if(pq[minIndex]>pq[lChild]){
                minIndex = lChild;
            }
            if(rChild<pq.size() && pq[minIndex]>pq[rChild]){
                minIndex = rChild;
            }
            if(minIndex==parentIndex){
                break;
            }
            int temp=pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex=minIndex;
            lChild = parentIndex*2+1;
            rChild = parentIndex*2+2;
        }
        return ans;
    }

    // int removeMin(){
    //     if(isEmpty()){
    //         return -1;
    //     }
    //     int ans = pq[0];
    //     pq[0]=pq[pq.size()-1];
    //     pq.pop_back();
    //     int parentIndex = 0;
    //     while(parentIndex<pq.size()){
    //         int lChild= parentIndex*2 + 1;
    //         int rChild = parentIndex*2 + 2;
    //         if(lChild<pq.size() && rChild<pq.size()){
    //             if(pq[lChild]<pq[rChild]){
    //                 if(pq[0]>pq[lChild]){
    //                     int temp = pq[0];
    //                     pq[0] = pq[lChild];
    //                     pq[lChild] = temp;
    //                     parentIndex=lChild;
    //                 }
    //                 else{
    //                     break;
    //                 }
    //             }
    //             else{
    //                 if(pq[0]>pq[rChild]){
    //                     int temp = pq[0];
    //                     pq[0] = pq[rChild];
    //                     pq[rChild] = temp;
    //                     parentIndex=rChild;
    //                 }
    //                 else{
    //                     break;
    //                 }
    //             }
    //         }
    //         else if(lChild<pq.size() && rChild>=pq.size()){
    //             if(pq[0]>pq[lChild]){
    //                     int temp = pq[0];
    //                     pq[0] = pq[lChild];
    //                     pq[lChild] = temp;
    //                     parentIndex=lChild;
    //                 }
    //                 else{
    //                     break;
    //                 }
    //         }
    //         else if(lChild>=pq.size() && rChild<pq.size()){
    //             if(pq[0]>pq[rChild]){
    //                     int temp = pq[0];
    //                     pq[0] = pq[rChild];
    //                     pq[rChild] = temp;
    //                     parentIndex=rChild;
    //                 }
    //                 else{
    //                     break;
    //                 }
    //         }
    //         else{
    //             break;
    //         }
    //     }
    // return ans;
    // }

};