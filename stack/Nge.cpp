// popall elements smaller than or equal to current element.
// stack is empty, NGE = -1.
// else st.top() is nge
// st.push(nums2[i]) beacuse it can be nge for current

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> nge(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int,int> mp;
        stack<int>st;
        for(int i= nums2.size()-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                mp[nums2[i]]=-1;
            }
            else{
                mp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);

        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
                ans.push_back(mp[nums1[i]]);  
        }
            return ans;
    }
};

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    Solution s;

    vector<int> ans = s.nge(nums1, nums2);

    for (auto x : ans) {
        cout << x << " ";
    }

    return 0;
}