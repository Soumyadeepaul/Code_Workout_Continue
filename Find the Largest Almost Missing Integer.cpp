//https://leetcode.com/problems/find-the-largest-almost-missing-integer/description/?envType=daily-question&envId=2026-08-18



class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        set<int,greater<int>> unique(nums.begin(),nums.end());
        int result=-1;
        for(auto it=unique.begin();it!=unique.end();it++){
            int found=0;
            for(int i=0;i<=nums.size()-k;i++){
                for(int j=i;j<i+k;j++){
                    if(*it==nums[j]){
                        found++;
                        break;
                    }
                }
                if(found>=2) break;
            }
            if(found==1){
                result=*it;
                break;
            }
        }
        return result;
    }
};
