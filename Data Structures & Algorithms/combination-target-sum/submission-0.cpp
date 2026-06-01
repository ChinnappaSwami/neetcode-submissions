class Solution {
public:

    vector<vector<int>> ans ;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        
        sort(nums.begin() , nums.end());
        dfs(0 , {} , 0 , nums , target);
        return ans ;
    }

    void dfs(int i , vector<int> cur , int total , vector<int>& nums , int target){
        if (target == total){
            ans.push_back(cur);
        }
        for(int j = i ; j < nums.size() ; j++){
            if (total + nums[j] > target){
                return ;
            }
            cur.push_back(nums[j]);
            dfs(j , cur , total +nums[j] , nums , target);
            cur.pop_back();
        }
    }
};
