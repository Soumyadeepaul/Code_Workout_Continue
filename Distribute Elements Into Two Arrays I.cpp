//https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/?envType=daily-question&envId=2026-08-20


class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> A,B;
        int i=0;
        int l=nums.size();
        A.push_back(nums[0]);
        B.push_back(nums[1]);
        for(i=2;i<l;i++){
            if(A.back()>B.back()){
                A.push_back(nums[i]);
            }
            else B.push_back(nums[i]);
        }
        A.insert(A.end(),B.begin(),B.end());

        return A;
    }
};
