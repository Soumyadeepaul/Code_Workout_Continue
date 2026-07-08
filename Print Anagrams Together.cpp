//https://www.geeksforgeeks.org/problems/print-anagrams-together/1


class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>> result;
        unordered_map<string,vector<string>> store;
        for(string s:arr){
            string temp=s;
            sort(temp.begin(),temp.end());
            store[temp].push_back(s);
        }
        for(auto p:store){
            result.push_back(p.second);
        }
        return result;
    }
};
