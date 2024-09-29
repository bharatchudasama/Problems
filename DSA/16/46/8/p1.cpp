//leetcode 213 house robber
//T.C. O(n) S.C. O(1)
//tabulation + space optimized
// same as previous question it is just that
//  i have made to solution with and without first and last element 
class Solution {
public:
    int rob(vector<int>& nums) {
        // with first elemnet and without last element
        int n = nums.size();
        int prev =nums[0],curr=0,prev1=0;
        for(int i = 1; i<n-1 ;i++){
            int take = nums[i] + prev1 ;
            int not_take= 0 + prev ;
            curr = max(take,not_take);
            prev1=prev;
            prev=curr;
        }
        int without_initial = prev;
        if(n==1){return prev;}//edge case
        // without first elemnet but with last element
        prev =nums[1],curr=0,prev1=0;
        for(int i = 2; i<n ;i++){
            int take = nums[i] + prev1 ;
            int not_take= 0 + prev ;
            curr = max(take,not_take);
            prev1=prev;
            prev=curr;
        }

        return max(prev,without_initial);
    }
};