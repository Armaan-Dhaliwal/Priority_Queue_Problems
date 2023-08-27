#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> uMap;
        int max = INT_MIN;
        for(int i=0;i<nums.size();i++){
            uMap[nums[i]]+=1;
            if(nums[i]>max){
                max=nums[i];
            }
        }

        int res=-1;
        for(int i=1;i<max;i++){
            if(uMap[i]==0){
                res=i;
                break;
            }
        }
        if(res==-1){
            res=max+1;
        }
        if(res<=0){
            res=1;
        }
        return res;

        