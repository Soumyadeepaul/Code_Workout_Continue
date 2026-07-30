//https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=problem-list-v2&envId=sliding-window


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int alreadyS=0;
        int l=customers.size();
        for(int i=0;i<l;i++){
            if(grumpy[i]==0) alreadyS+=customers[i];
        }
        int maxi=0;
        int i=0,j=0;
        int store=0;
        while(j<l){ 
            if(grumpy[j]==1){
                store+=customers[j];
            }
            if(j-i<minutes){
                maxi=max(maxi,store);
            }
            if(j-i==minutes){
                if(grumpy[i]==1) store-=customers[i];
                i++;
                maxi=max(maxi,store);
            }
            j++;
        }
        return alreadyS+maxi;
    }
};
