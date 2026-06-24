class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = nums[0] ;
        int currMin = 1 , currMax = 1 ;

        for(int i = 0 ; i < nums.size() ; i++){
            int tmp1 = currMax*nums[i] ;
            int tmp2 = currMin*nums[i] ;
            currMax = max(max(tmp1 , tmp2) , nums[i]);
            currMin = min(min(tmp1 , tmp2) , nums[i]);
            ans = max(ans , currMax);
         }

         return ans ;
    }
};
