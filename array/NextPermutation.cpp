#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void nextPermutation(vector<int>& nums){
        int n=nums.size();
        int i= n-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--; // find the pivot
        }
        if(i>=0){
            int j=n-1;// from right to leftfind next greater element than nums[i]
            while(nums[j]<=nums[i]){// <= so duplicates are skipped {1,2,1,1}is example
                j--;
            }
            swap(nums[i],nums[j]);

        }
        reverse(nums.begin()+i+1, nums.end());

    }
};

int main(){
    vector<int>nums={1,2,3};
    Solution s;
    s.nextPermutation(nums);
    for(auto x: nums){
        cout<<x<<",";
    }
    return 0;
}