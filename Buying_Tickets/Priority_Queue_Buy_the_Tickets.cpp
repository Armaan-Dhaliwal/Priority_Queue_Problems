#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    vector<int> priorities;
    queue<int> arr;
    priority_queue<int> pq;

    cout<<"Enter your array: "<<endl;
    int ele;
    cin>>ele;
    while(ele!=-1){
        priorities.push_back(ele);
        cin>>ele;
    }

    cout<<"Enter your element's index: "<<endl;
    int my_ele_index, my_ele;
    cin>>my_ele_index;
    my_ele=priorities[my_ele_index];

    int n=priorities.size();
    for(int i=0;i<n;i++){
        arr.push(i);
    }

    for(int i=0;i<n;i++){
        pq.push(priorities[i]);
    }

    int time=0;
    while(!arr.empty()){
        if(priorities[arr.front()]==my_ele && pq.top()==my_ele){
            time++;
            if(arr.front()==my_ele_index){
                break;
            }
            else{
                arr.pop();
                pq.pop();
                continue;
            }   
        }

        if(priorities[arr.front()]==pq.top()){
            pq.pop();
            arr.pop();
            time++;
        }
        else{
            int temp=arr.front();
            arr.pop();
            arr.push(temp);
        }
    }
    cout<<"Time taken will be: "<<time<<endl;
}