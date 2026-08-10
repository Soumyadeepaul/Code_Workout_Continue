//https://www.geeksforgeeks.org/problems/champagne-overflow2636/1



class Solution {
  public:
    vector<vector<double>> dp;
    int r;
    // void helper(int K){
    //     double k=K;
    //     queue<vector<double>>q;
    //     q.push({0,0,k});
        
    //     while(!q.empty()){
    //         auto p=q.front();
    //         q.pop();
    //         double x=p[0], y=p[1], comming=p[2];
    //         double capacityLeft=1-dp[x][y];
    //         double remaining=comming-capacityLeft;
    //         if(remaining<=0) dp[x][y]+=comming;
    //         else{
    //             dp[x][y]=1;
    //             remaining/=2.0;
    //             if(x==r) continue;
    //             q.push({x+1,y,remaining});
    //             q.push({x+1,y+1,remaining});
    //         }
    //     }
    // }
    
    
    
    double helper1(int k, int r, int c){
        
        vector<double>row(1,k); //1st row
        
        for(int i=1;i<r;i++){
            vector<double> nextRow(i+1,0.0);
            for(int j=0;j<row.size();j++){
                if(row[j]>1){
                    double split=(row[j]-1)/2.0;
                    nextRow[j]+=split;
                    nextRow[j+1]+=split;
                }
            }
            row=nextRow;
        }
        return min(row[c-1],1.0);
    }
    
    double waterOverflow(int K, int R, int C) {
        // code here
        // r=R;
        // int glass=1;
        // for(int i=0;i<R+1;i++){
            
        //     vector<double> g(glass,0);
        //     glass++;
        //     dp.push_back(g);
        // }
        
        // helper(K);
        
        // for(auto i:dp){
        //     for(int j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return helper1(K,R,C);
        // return dp[R-1][C-1];
    }
};
