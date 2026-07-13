//https://leetcode.com/problems/high-access-employees/description/


class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>> map;
        for(auto p:access_times){
            string h=string(1,p[1][0])+string(1,p[1][1]);
            string m=string(1,p[1][2])+string(1,p[1][3]);
            int hr=stoi(h)*60;
            int mn=stoi(m);
            map[p[0]].push_back(hr+mn);
        }
        vector<string> result;
        for(auto p:map){
            sort(p.second.begin(),p.second.end());
            int prev=-1;
            int prePrev=-1;
            for(int i:p.second){
                if(prePrev!=-1 && i-prePrev<60) {
                    result.push_back(p.first);
                    break;
                }
                prePrev=prev;
                prev=i;
                
            }
        }

        return result;
    }
};
