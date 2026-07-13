//https://leetcode.com/problems/maximum-balanced-shipments/description/


class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int count=0;

        int j=0;
        int maxi=-1;
        while(j<weight.size()){
            if(weight[j]>=maxi){
                maxi=weight[j];
            }
            else{
                count++;
                maxi=-1;
            }
            j++;
        }
        return count;
    }
};
