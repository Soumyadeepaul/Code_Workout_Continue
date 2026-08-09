//https://leetcode.com/problems/insert-delete-getrandom-o1/description/


class RandomizedSet {
private:
    unordered_map<int,int> mpp;
    vector<int> track;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.count(val)) return false;
        mpp[val]=track.size();
        track.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mpp.count(val)){
            int idx=mpp[val];
            track[idx]=track.back();
            mpp[track.back()]=idx;
            track.pop_back();
            mpp.erase(val);
            return true;
        } 
        return false;
    }
    
    int getRandom() {
        int r=rand();
        r=r%track.size();
        return track[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
