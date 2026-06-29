class Solution {
public:
    bool canJump(vector<int>& nums) {
        int id = 0 ;

        for(int i = 0 ; i < nums.size() ; i++){
            if (i > id) return false  ;
            id = max(id , nums[i] + i) ; 
        }

        return true ;
    }
};
