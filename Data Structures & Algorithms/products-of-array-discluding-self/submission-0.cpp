class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = n = nums.size();
        vector<int> sol(n , 1);
        for (int i = 1 ; i < n ; i++){
            sol[i] = sol[i-1] * nums[i-1];
        }

        int postfix = 1 ;
        for(int i = n - 1 ; i >= 0 ; i--){
            sol[i]*= postfix ;
            postfix *= nums[i];
        }

        return sol ;
    }
};
