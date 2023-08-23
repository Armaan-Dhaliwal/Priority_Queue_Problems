#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

long long connectRopes(int* arr, int n)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    int cost=0;
    while(pq.size()!=1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        cost+=a+b;
        pq.push(a+b);
    }
    return cost;
}
