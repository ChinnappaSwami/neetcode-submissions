class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> um ;
        vector<vector<int>> m(nums.size() +1) ;
        vector<int> sol ;
        for(int i : nums) {
            um[i]++ ;
        }

        for (auto &p : um){
            m[p.second].push_back(p.first);
        }

        for(int i = nums.size() ; i >0 ; i--){
            for (int a : m[i]){
                sol.push_back(a) ;
                if (sol.size() == k) return sol ;
            }
        }

        return sol ;

    }
};
