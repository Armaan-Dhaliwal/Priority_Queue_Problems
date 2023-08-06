#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    vector<int> arr;
    cout<<"Enter elements: "<<endl;
    int ele;
    cin>>ele;
    while(ele!=-1){
        arr.push_back(ele);
        cin>>ele;
    }
    cout<<"Enter value of k: "<<endl;
    int k;
    cin>>k;

    //Max-Heap Priority Queue: 
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<arr.size();i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }

    }

    cout<<"Your Elements are: "<<endl;
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}