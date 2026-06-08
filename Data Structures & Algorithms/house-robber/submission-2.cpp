class Solution {
public:
    int rob(vector<int>& nums) {
        int c=0;int p1 =0 ;int p2 = 0 ;

        for(int n : nums){
            c = max(p1 , p2 + n);
            p2 = p1 ;
            p1 = c ;
        }

        return c ;
    }

};
