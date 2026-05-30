class Solution {
public:
    unordered_set<int> visited ;

    void dfs(int val  , vector<vector<int>>& adj){
        visited.insert(val);

        for(int i : adj[val]){

            if(!visited.count(i)) dfs(i , adj);
        }        
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n) ;
        for(vector<int> p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        int num = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(!visited.count(i)){
                num++;
                dfs(i , adj);
            }
        }

        return num ;
        
    }
};
