#include<iostream>
#include<vector>
using namespace std;

// Check if Max-Heap:
int main(){
    vector<int> arr;
    cout<<"Enter elements of array: "<<endl;
    int ele;
    cin>>ele;
    while(ele!=-1){
        arr.push_back(ele);
        cin>>ele;
    }

    bool res=true;
    int parentIndex=0;
    while(parentIndex<arr.size()){
        int lChild = parentIndex*2+1;
        int rChild = parentIndex*2+2;
        if(lChild<arr.size() && arr[lChild]>arr[parentIndex]){
            res=false;
            break;
        }
        if(rChild<arr.size() && arr[rChild]>arr[parentIndex]){
            res=false;
            break;
        }
        parentIndex++;
    }
    cout<<res<<endl;
}
