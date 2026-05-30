class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses , 0);
        vector<vector<int>> adj(numCourses) ;

        for(vector<int> p : prerequisites){
            indegree[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }

        queue<int> q ;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        int finish = 0 ; 
        while(!q.empty()){
            int n = q.front();
            q.pop();
            finish++;
            for(int nei : adj[n]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }

        return finish == numCourses ;

    }
};
