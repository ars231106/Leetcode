class Trie {
public:
    vector<string> words;

    Trie() {
    }

    void insert(string word) {
        words.push_back(word);
    }

    bool search(string word) {
        for(string s : words){
            if(s == word)
                return true;
        }
        return false;
    }

    bool startsWith(string prefix) {
        for(string s : words){
            if(s.size() < prefix.size())
                continue;

            bool ok = true;
            for(int i = 0; i < prefix.size(); i++){
                if(s[i] != prefix[i]){
                    ok = false;
                    break;
                }
            }

            if(ok)
                return true;
        }
        return false;
    }
};