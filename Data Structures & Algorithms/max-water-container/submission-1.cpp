class Solution {
    public:
    int maxArea(vector<int>& heights) {
        
        int area = 0 ;
        int c = 0 ;
        int l = 0 ;
        int r = heights.size()-1 ;
        int b = heights.size()-1 ;

        while(l <r){

            int t = (heights[l]<heights[r])?heights[l] : heights[r];
            t = t*b ;

            area = (area > t) ? area : t ;

            if (heights[l] < heights[r]) l++ ;
            else r-- ;
            b-- ;
            c++ ;
        }

        return area ;
    }
};