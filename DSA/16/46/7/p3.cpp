//leetcode 198 house robber
//T.C. O(n) S.C. O(1)
//tabulation + space optimized
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev =nums[0],curr=0,prev1=0;
        for(int i = 1; i<n ;i++){
            int take = nums[i] + prev1 ;
            int not_take= 0 + prev ;
            curr = max(take,not_take);
            prev1=prev;
            prev=curr;
        }
        return prev;
    }
};