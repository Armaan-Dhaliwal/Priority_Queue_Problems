#include<iostream>
#include<queue>
using namespace std;

struct triad{
        int val;
        int arr_no;
        int index;
        
        triad(int val,int arr_no, int index){
            this->val=val;
            this->arr_no=arr_no;
            this->index=index;
        }
    };
    
    struct comp{
        bool operator()(triad &d1,triad &d2){
            return (d1.val>d2.val);
        }
    };
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {   vector<int> res;
        int k=K;
        priority_queue<triad, vector<triad>, comp> pq;
        for(int i=0;i<k;i++){
            triad d(arr[i][0],i,0);
            pq.push(d);
        }
        
        while(!pq.empty()){
        triad top = pq.top();
        pq.pop();
        res.push_back(top.val);
        if(top.index+1<arr[top.arr_no].size()){
            triad d(arr[top.arr_no][top.index+1],top.arr_no,top.index+1);
            pq.push(d);
        }
        
    }
        return res;
    }