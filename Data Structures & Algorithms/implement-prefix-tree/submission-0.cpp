class PrefixTree {
public:
    char val ;
    bool last ;
    vector<PrefixTree*> children ;

    PrefixTree() {
        val = '\0';
        last = false ;

    }
    
    void insert(string word) {
        PrefixTree* p = this ;
        int size = word.length();
        int i = 0 ;
        while(i < size){
            int flag = 0 ;
            for(PrefixTree* cp : p->children){
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
            PrefixTree* cpp = new PrefixTree();
            cpp->val = word[i];
            p->children.push_back(cpp);
            p=cpp ;
            i++;
        }
        p->last = true ;
    }
    
    bool search(string word) {
        PrefixTree* p = this ;
        int size = word.length();
        int i = 0 ;
        while(i < size){
            int flag = 0 ;
            for(PrefixTree* cp : p->children){
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
        if(i == size && p->last == true){
            return true ;
        }
        return false ;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* p = this ;
        int size = prefix.length();
        int i = 0 ;
        while(i < size){
            int flag = 0 ;
            for(PrefixTree* cp : p->children){
                if (cp->val == prefix[i]){
                    flag = 1 ;
                    p = cp ;
                    break ;
                }
            }
            if(flag == 0){
                break ;
            }
            i++ ;
        }
        if(i == size ){
            return true ;
        }
        return false ;
    }
};
