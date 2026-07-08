//https://www.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        int v=1, h=1;
        priority_queue<int> vertical(x.begin(),x.end());
        priority_queue<int> horizontal(y.begin(),y.end());
        int cost=0;
        while(!vertical.empty() &&  !horizontal.empty()){
            int v1=vertical.top();
            int h1=horizontal.top();
            if(h1>v1){
                horizontal.pop();
                cost+=h1*v;
                h++;
            }
            else{
                vertical.pop();
                cost+=v1*h;
                v++;
            }
        }
        while(!vertical.empty()){
            int v1=vertical.top();
            vertical.pop();
            cost+=v1*h;
            v++;
        }
        while(!horizontal.empty()){
            int h1=horizontal.top();
            horizontal.pop();
            cost+=h1*v;
            h++;
        }
        return cost;
    }
};
