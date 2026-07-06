//https://leetcode.com/problems/remove-covered-intervals/description/?envType=daily-question&envId=2026-07-06


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto&a ,const auto &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });

        int index=0;
        int end=intervals[0][1];
        int start=intervals[0][0];
        for(int i=1;i<intervals.size();i++){
            if(end<=intervals[i][0]){
                start=intervals[i][0];
                end=intervals[i][1];
            }
            else{
                if(start<=intervals[i][0] && end>=intervals[i][1]){
                    index++;
                    
                }
                else{
                    
                    start=min(start,intervals[i][0]);
                    end=max(end,intervals[i][1]);
                }
            }
        }
        return intervals.size()-index;
    }
};
