class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy = prices[0] ;
        int p = 0 ;

        for(int sell :prices){
            p = max(p , sell - buy);
            buy = min(buy , sell) ;
        }

        return p ;

    }
};
