//https://leetcode.com/problems/time-needed-to-buy-tickets/description/?envType=problem-list-v2&envId=dsa-sequence-valley-queue

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count=0;
        int pivot=tickets[k];
        for(int i=0;i<tickets.size();i++){
            if(tickets[i]<tickets[k]){
                count+=tickets[i];
            }
            else if(i<=k && tickets[i]>=tickets[k]){
                count+=pivot;
            }
            else if(i>k && tickets[i]>=tickets[k]){
                count+=pivot-1;
            }
        }
        return count;
    }
};
