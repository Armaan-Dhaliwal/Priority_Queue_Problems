#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> kthLargest(int k, int arr[], int n) {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> res;
        for(int i=0;i<n;i++){
            if(i<k-1){
                pq.push(arr[i]);
                res.push_back(-1);
            }
            else if(i==k-1){
                pq.push(arr[i]);
                res.push_back(pq.top());   
            }
            else{
                if(pq.top()<arr[i]){
                    pq.pop();
                    pq.push(arr[i]);
                    res.push_back(pq.top());
                }
                else{
                    res.push_back(pq.top());
                }
            }
        }
        return res;
    }