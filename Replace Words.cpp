//https://leetcode.com/problems/replace-words/description/?envType=problem-list-v2&envId=trie


class Solution {
public:
    struct Trie{
        unordered_map<char,Trie*> store;
        bool end=false;
    };
    Trie* root=new Trie();
    void insert(string &s){
        Trie* temp=root;
        for(char c:s){
            if(temp->store.count(c)){
                temp=temp->store[c];
            }
            else{
                Trie* node=new Trie();
                temp->store[c]=node;
                temp=temp->store[c];
            }
        }
        // temp->end=true;
    }

    string helper(string &s){
        string shortest="";
        Trie* temp=root;
        for(char c:s){
            if(temp->store.count(c)){
                temp=temp->store[c];
                shortest+=c;
            }
            if(temp->end==true) return shortest;
        }
        return s;
    }

    void dicEndings(string &s){
        Trie* temp=root;
        
        for(char c:s){
            if(temp->store.count(c)){
                temp=temp->store[c];
            }
            else{
                return;
            }
        }
        temp->end=true;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        sentence+=' ';
        string store="";
        for(char c:sentence){
            if(c==' '){
                insert(store);
                store="";
            }
            else store+=c;
        }
        for(auto d:dictionary){
            dicEndings(d);
        }
        string result="";
        for(char c:sentence){
            if(c==' '){
                result+=helper(store)+" ";
                store="";
            }
            else store+=c;
        }
        result.pop_back();
        return result;

        
    }
};
