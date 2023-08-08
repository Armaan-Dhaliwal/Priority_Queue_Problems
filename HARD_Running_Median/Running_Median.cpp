#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

 class Solution{
    public:
    priority_queue<double> heap1;
    priority_queue<double ,vector<double>, greater<double>> heap2;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {   
        if(heap1.empty()){
            heap2.push(x);
        }
        else{
            if(x>heap2.top()){
                heap2.push(x);
            }
            else{
                heap1.push(x);
            }
        }
        
        return balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {       
            if(heap2.size()-heap1.size()<=1){
                return;
            }
            
            if(heap2.size()>heap1.size()){
               heap1.push(heap2.top());
                heap2.pop(); 
            }
            else{
                heap2.push(heap1.top());
                heap1.pop();
            }

    }
    
    //Function to return Median.
    double getMedian()
    {
        if(heap2.size()-heap1.size()==1){
                return heap2.top();
            }
        else{
            return ((heap2.top()+heap1.top())/2);
        }
    }
 };
   
