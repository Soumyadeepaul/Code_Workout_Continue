//https://leetcode.com/problems/daily-temperatures/description/?envType=problem-list-v2&envId=dsa-linear-shoal-monotonic-stack


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
        stack<pair<int,int>> store;
        for(int i=temperatures.size()-1;i>-1;i--){
            int get=0;
            while(!store.empty()){
                auto top=store.top();
                if(top.first>temperatures[i]){
                    get=top.second;
                    break;
                }
                else store.pop();
            }
            if(get!=0) result[i]=get-i;
            store.push({temperatures[i],i});
        }
        return result;
    }
};
