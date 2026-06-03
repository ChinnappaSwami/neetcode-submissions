class WordDictionary {
public:

    char val ;
    bool last ;
    vector<WordDictionary*> children ;

    WordDictionary() {
        val = '\0';
        last = false ;
    }
    
    void addWord(string word) {
        WordDictionary* p = this ;
        int size = word.length();
        int i = 0 ;
        while(i < size){
            int flag = 0 ;
            for(WordDictionary* cp : p->children){
                if (cp->val == word[i]){
                    flag = 1 ;
                    p = cp ;
                    break ;
                }
            }
            if(flag == 0){
                break;
            }
            i++ ;
        }
        while(i < size){
            WordDictionary* cpp = new WordDictionary();
            cpp->val = word[i];
            p->children.push_back(cpp);
            p=cpp ;
            i++;
        }
        p->last = true ;
    }
    
    bool search(string word) {
        WordDictionary* p = this ;
        return dfs(p , word , 0) ;
    }

    bool dfs(WordDictionary* p , string word , int pos){

        if (pos == word.size()) return p->last ;

        if (word[pos] == '.'){
            for(WordDictionary* cp : p->children){
                if(dfs(cp, word , pos+1)) return true ;
            }
            return false ;
        }

        for(WordDictionary* cp : p->children){
            if(cp->val == word[pos]) return dfs(cp , word , pos+1) ;
        }
        
        return false ;
    }
};
