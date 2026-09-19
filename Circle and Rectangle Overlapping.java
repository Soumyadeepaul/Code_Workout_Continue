//https://leetcode.com/problems/circle-and-rectangle-overlapping/?envType=daily-question&envId=2026-09-19


class M{
    public int square(int x){
        return x*x;
    }
}

class Solution {
    public int helper(int c, int x1, int x2){
        int x;
        if(x1>c) x=x1;
        else if(x2<c) x=x2;
        else x=c;
        return x;
    }
    public double distance(int x1,int y1, int x2, int y2){
        M m = new M();
        return Math.sqrt(m.square(x1-x2)+m.square(y1-y2));
    }
    public boolean checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x;
        int y;
        x=helper(xCenter,x1,x2);
        y=helper(yCenter,y1,y2);

        if(distance(xCenter, yCenter, x, y)<=radius) return true;

        return false;
        
    }
}
