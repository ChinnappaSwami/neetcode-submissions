class Solution {
public:

    string encode(vector<string>& strs) {

        string sol = "";
        for (string s : strs){
            sol = sol + s + "TBG#hatesbaselessaccusations" ;
        }

        return sol ;
    }

    vector<string> decode(string s) {

        vector<string> sol ;
        string str = "" ;

        string sep = "TBG#hatesbaselessaccusations";

        for (int i = 0; i < s.size(); ) {
            if (i + sep.size() <= s.size() && s.substr(i, sep.size()) == sep) {
                sol.push_back(str);
                str.clear();
                i += sep.size();   
            } else {
                str.push_back(s[i]);
                i++;
            }
        }


        return sol ;
    }
};
