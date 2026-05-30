class Solution {
public:
    unordered_set<int> visited ;

    bool dfs(int val , int papa , vector<vector<int>>& adj){
        if(visited.count(val)) return false ;

        visited.insert(val);

        for(int i : adj[val]){
            if (i == papa) continue ;

            if(!dfs(i , val , adj)){
                return false ;
            }
        }

        return true ;

        
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n) ;
        for(vector<int> p : edges){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        if(!dfs(0 , -1 , adj)) return false ;
        

        return visited.size() == n;
    }
};
