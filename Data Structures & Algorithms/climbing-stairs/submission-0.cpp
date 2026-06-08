class Solution {
public:
    int climbStairs(int n) {
        int p1 = 0 ;
        int p2 = 1 ;
        int ans ;

        while(n--){
            ans = p1+p2 ;
            p1 = p2 ;
            p2 = ans ;
        }

        return ans ;
    }
};
