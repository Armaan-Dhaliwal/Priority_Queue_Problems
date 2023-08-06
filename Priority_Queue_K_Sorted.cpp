#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


vector <int> nearlySorted(int arr[], int num, int K){
        vector<int> res;
        int k=K;
        int n=num;
        

        //Declaration of a Min-Heap Priority Queue using STL in C++:

        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<k+1;i++){
            pq.push(arr[i]);
        }
        
        for(int i=k+1;i<n;i++){
            res.push_back(pq.top());
            pq.pop();
            pq.push(arr[i]);            
        }
        
        while(!pq.empty()){
             res.push_back(pq.top());
             pq.pop();
        }
    
        return res;
    }