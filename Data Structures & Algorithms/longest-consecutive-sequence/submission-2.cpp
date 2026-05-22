class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> nu(nums.begin() , nums.end()) ;
        map<int , int > m ;
        set<int> s ;
        s.insert(1);
        int v ;

        if (nums.size() == NULL) return 0 ;

        for(int i : nu){
            auto it = m.find(i - 1) ;
            if (it != m.end()){
                v = it->second + 1;
                m.erase(it) ;
                m[i] = v ;
                s.insert(v);
            }
            else {
                m[i] = 1 ;
                
            }
        }

        return *s.rbegin();


    }
};
