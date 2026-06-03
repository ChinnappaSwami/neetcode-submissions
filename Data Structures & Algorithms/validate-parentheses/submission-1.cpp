class Solution {
public:
    bool isValid(string st) {
        stack<int> s;

        for(char c : st){
            if(c == '(' || c == '{' || c == '[') s.push(c);
            if(s.empty()) return false ;
            if(c == ')' ){
                if (s.top() == '(') s.pop();
                else return false ;
            }
            if(c == ']' ){
                if (s.top() == '[') s.pop();
                else return false ;
            }
            if(c == '}' ){
                if (s.top() == '{') s.pop();
                else return false ;
            }
        }
        if (!s.empty()) return false ;
        return true ;
    }
};
