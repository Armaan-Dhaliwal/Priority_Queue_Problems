#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

class comp{
    public:
    bool operator()(pair<int,int> &p1, pair<int,int> &p2){
        if(p1.first>p2.first){
            return false;
        }
        else if(p1.first<p2.first){
            return true;
        }
        else{
            if(p1.second<p2.second){
                return false;
            }
            else{
                return true;
            }
        }
    }
  };
  
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        vector<int> res;
        for(int i=0;i<k;i++){
            pq.push({arr[i],i});
        }
        
        res.push_back(pq.top().first);
        
        for(int i=k;i<n;i++){
            // pq.push({arr[i],i});
            while(pq.top().second<=i-k){
                pq.pop();
            }
            pq.push({arr[i],i});
            res.push_back(pq.top().first);
        }
        return res;
    }