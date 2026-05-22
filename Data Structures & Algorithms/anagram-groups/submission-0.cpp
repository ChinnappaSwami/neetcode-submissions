class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> um ;
        for (string s : strs){
            vector<int> alpha(26,0) ;
            for(char c : s){
                alpha[c - 'a']++ ;
            }
            if (um.find(alpha) != um.end()) um[alpha].push_back(s) ;
            else um[alpha] = {s};
        }

        vector<vector<string>> sol ;
        for(auto &p : um){
            sol.push_back(p.second);
        }

        return sol ;
    }
};
