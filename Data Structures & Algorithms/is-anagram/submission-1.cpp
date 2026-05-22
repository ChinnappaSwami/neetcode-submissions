class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map<char, int> mp1;
        map<char, int> mp2;

        for(char i : s){
            if (mp1.count(i)) mp1[i]++;
            else mp1[i] = 1 ;
        }

        for(char i : t){
            if (mp2.count(i)) mp2[i]++;
            else mp2[i] = 1 ;
        }

       if (mp1 == mp2) return true ;
       return false ;

    }
};
