//https://leetcode.com/problems/cinema-seat-allocation/description/


class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        int count=0;
        map<int,set<int>> booked;
        for(vector<int> b:reservedSeats){
            booked[b[0]].insert(b[1]);
        }
        for(auto &p:booked){
            vector<int> check(3,0);
            for(int i=2;i<=9;i++){
                if(p.second.count(i)){
                    if(i==2 || i==3) check[0]=1;
                    if(i==4 || i==5){
                        check[0]=1;
                        check[1]=1;
                    }
                    if(i==6 || i==7){
                        check[1]=1;
                        check[2]=1;
                    }
                    if(i==8 || i==9)check[2]=1;
                }
            }
            if(check[0]==0 && check[1]==0 && check[2]==0) count+=2;
            else if(check[0]==1 && check[1]==1 && check[2]==1) {}
            else count+=1;
        }
        count+=2*(n-booked.size());
        return count;
    }
};
