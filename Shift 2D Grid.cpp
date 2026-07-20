//https://leetcode.com/problems/shift-2d-grid/description/?envType=daily-question&envId=2026-07-20


class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size(), c=grid[0].size();
        int elements=r*c;
        int nK=k%elements;
       
        vector<vector<int>> ngrid(r,vector<int>(c,0));
        int sr=nK/c , sc=nK%c;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ngrid[sr][sc]=grid[i][j];
                sc++;
                if(sc==c){
                    sc=0;
                    sr++;
                    if(sr==r) sr=0;
                }
            }
            
        }
        return ngrid;
    }
};
