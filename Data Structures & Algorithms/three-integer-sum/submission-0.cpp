class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        set<vector<int>> ans ;

        for (int i = 0 ; i < nums.size() ; i++){
            for (int j = i + 1 ; j < nums.size() ; j++){
                int t = -(nums[i] + nums[j]) ;
                if (find(nums.begin() + j + 1 , nums.end() , t) != nums.end()){
                    ans.insert({nums[i] , nums[j] , t}) ;
                }
            }
        }

        vector<vector<int>> sol(ans.begin() , ans.end());

        return sol ;
    }
};
