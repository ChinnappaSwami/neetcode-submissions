class Solution {
public:

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans ;

        int row =  heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pacific(row , vector<bool>(col , false));
        vector<vector<bool>> atlantic(row , vector<bool>(col , false));
        
        for(int c = 0  ; c < col ; c++){
            dfs(heights , 0 , c , pacific);
            dfs(heights , row-1 , c , atlantic);
        }

        for(int r = 0 ; r < row ; r++){
            dfs(heights , r , 0 , pacific);
            dfs(heights , r , col-1 , atlantic);
        }

        for(int i =0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if (pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans ;
    }

    void dfs(vector<vector<int>>& heights , int r , int c , vector<vector<bool>>& ocean){
        
        ocean[r][c] = true ;

        if( (r-1 >= 0) && !ocean[r-1][c] && heights[r-1][c] >= heights[r][c]){
            dfs(heights , r-1 , c , ocean);
        }
        if( (r+1 < heights.size()) && !ocean[r+1][c] && heights[r+1][c] >= heights[r][c]){
            dfs(heights , r+1 , c , ocean);
        }
        if( (c-1 >= 0) && !ocean[r][c-1] && heights[r][c-1] >= heights[r][c]){
            dfs(heights , r , c-1 , ocean);
        }
        if( (c+1 < heights[0].size()) && !ocean[r][c+1] && heights[r][c+1] >= heights[r][c]){
            dfs(heights , r , c+1 , ocean);
        }

        
    }
};
