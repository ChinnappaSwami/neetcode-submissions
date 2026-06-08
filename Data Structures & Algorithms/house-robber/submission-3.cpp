class Solution {
public:
    vector<int> memo ;
    int rob(vector<int>& nums) {
        memo.resize(nums.size() , -1);
        return maxie(0 , nums);
    }

    int maxie(int pos , vector<int>& nums){
        if(pos >=  nums.size()) return 0 ;
        if (memo[pos] != -1) return memo[pos];
        memo[pos] = max(maxie(pos+1 , nums) ,nums[pos] + maxie(pos+2 , nums));
        return memo[pos];
    }
};
