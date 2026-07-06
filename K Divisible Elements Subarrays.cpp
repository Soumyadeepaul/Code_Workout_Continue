//https://leetcode.com/problems/k-divisible-elements-subarrays/description/


class Solution {
public:
    struct Trie{
        unordered_map<int,Trie*> data;
        int end=-1;
    };
    void insertTrie(Trie* &store,vector<int> s){
        Trie* temp=store;
        for(int i:s){
            if(temp->data[i]!=NULL){
                temp=temp->data[i];
            }
            else{
                Trie* node=new Trie();
                temp->data[i]=node;
                temp=node;
            }
        }
        temp->end=1;
    }
    bool searchTrie(Trie* &store,vector<int> s){
        Trie* temp=store;
        for(int i:s){
            if(temp->data[i]!=NULL){
                temp=temp->data[i];
            }
            else return false;
        }
        if(temp->end==1) return true; //found;
        return false; //not found
    }
    int countDistinct(vector<int>& nums, int k, int p) {
        int count=0;
        Trie* store=new Trie();
        for(int i=0;i<nums.size();i++){
            int curr=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%p==0){
                    curr++;
                }

                if(curr<=k) {
                    vector<int> temp(nums.begin()+i,nums.begin()+j+1);
                    if(!searchTrie(store,temp)){
                        count++;
                        insertTrie(store,temp);
                    }
                }
            }
        }
        return count;
    }
};
