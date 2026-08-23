//https://leetcode.com/problems/sum-game/description/?envType=daily-question&envId=2026-08-23


class Solution {
public:
    bool helper(int left, int right, int chancesAliceInLeft, int chancesAliceInRight, int chancesBobInLeft,int chancesBobInRight){
        
        int addonLeft=0;
        int addonright=chancesAliceInRight*9;
        int diff2=(right+addonright)-(left+addonLeft);
        if(diff2<0){
            //bob should increase right and decrease left
            int maximumBobCanDo=chancesBobInRight*9;
            if(abs(diff2)>maximumBobCanDo) return true;
        }
        else if(diff2>0){
            //bob should increase left and decrease right
            int maximumBobCanDo=chancesBobInLeft*9;
            if(abs(diff2)>maximumBobCanDo) return true;
        }
        addonLeft=chancesAliceInLeft*9;
        addonright=0;
        diff2=(right+addonright)-(left+addonLeft);
        if(diff2<0){
            //bob should increase right and decrease left
            int maximumBobCanDo=chancesBobInRight*9;
            if(abs(diff2)>maximumBobCanDo) return true;

        }
        else if(diff2>0){
            //bob should increase left and decrease right
            int maximumBobCanDo=chancesBobInLeft*9;
            if(abs(diff2)>maximumBobCanDo) return true;
        }
        return false;
    }
    bool sumGame(string num) {
        int left=0, right=0;
        int lVacent=0, rVacent=0;
        int l=num.size();
        for(int i=0;i<l;i++){
            if(num[i]=='?'){
                if(i>=(l/2)){
                    rVacent++;
                }
                else{
                    lVacent++;
                }
            }
            else{
                if(i<(l/2)){
                    left=left+num[i]-'0';
                }
                else{
                    right=right+num[i]-'0';
                }
            }
        }


        int diff=right-left;
        int chancesAliceInLeft=0;
        int chancesAliceInRight=0;

        if((lVacent+rVacent)&1){
            //alice will get more chance
            //odd+even  or even+odd
            if(lVacent&1) {
                chancesAliceInLeft=(lVacent+1)/2;
                chancesAliceInRight=rVacent/2;
            }
            if(right&1){
                chancesAliceInRight=(rVacent+1)/2;
                chancesAliceInLeft=lVacent/2;
            }
        }
        else{
            //both same chance
            //even+even 
            chancesAliceInRight=rVacent/2;
            chancesAliceInLeft=lVacent/2;
        }
        int chancesBobInLeft=lVacent-chancesAliceInLeft;
        int chancesBobInRight=rVacent-chancesAliceInRight;
        //if unfair
        if(abs((chancesAliceInLeft+chancesAliceInRight)-(chancesBobInLeft+chancesBobInRight))>1){
            //someone has to transfer some chances to opponent
            if((chancesBobInLeft+chancesBobInRight)>(chancesAliceInLeft+chancesAliceInRight)){
                if(chancesBobInLeft>chancesBobInRight){
                    chancesAliceInLeft++;
                    chancesBobInLeft--;
                }
                if(chancesBobInLeft<chancesBobInRight){
                    chancesAliceInRight++;
                    chancesBobInRight--;
                }
            }
            else{
                if(chancesAliceInLeft<=chancesAliceInRight){
                    chancesAliceInLeft--;
                    chancesBobInLeft++;
                }
                if(chancesAliceInLeft>chancesAliceInRight){
                    chancesAliceInRight--;
                    chancesBobInRight++;
                }
            }
        }
        cout<<lVacent<<" "<<rVacent<<endl;
        cout<<"ALICE: "<<chancesAliceInLeft<<" "<<chancesAliceInRight<<endl;
        cout<<"Bob: "<<chancesBobInLeft<<" "<<chancesBobInRight<<endl;

        if(helper(left,right,chancesAliceInLeft,chancesAliceInRight,chancesBobInLeft,chancesBobInRight)==true) return true;
        

        

        if((lVacent+rVacent)&1){}
        else{
            //both same chance
            //odd+odd
            chancesAliceInRight=(rVacent+1)/2;
            chancesAliceInLeft=(lVacent+1)/2;
        }
        chancesBobInLeft=lVacent-chancesAliceInLeft;
        chancesBobInRight=rVacent-chancesAliceInRight;
        //if unfair
        if(abs((chancesAliceInLeft+chancesAliceInRight)-(chancesBobInLeft+chancesBobInRight))>1){
            //someone has to transfer some chances to opponent
            if((chancesBobInLeft+chancesBobInRight)>(chancesAliceInLeft+chancesAliceInRight)){
                
                if(chancesBobInLeft>=chancesBobInRight){
                    chancesAliceInLeft++;
                    chancesBobInLeft--;
                }
                if(chancesBobInLeft<chancesBobInRight){
                    chancesAliceInRight++;
                    chancesBobInRight--;
                }
            }
            else{
                if(chancesAliceInLeft<=chancesAliceInRight){
                    chancesAliceInLeft--;
                    chancesBobInLeft++;
                }
                if(chancesAliceInLeft>chancesAliceInRight){
                    chancesAliceInRight--;
                    chancesBobInRight++;
                }
            }
        }
        cout<<lVacent<<" "<<rVacent<<endl;
        cout<<"ALICE: "<<chancesAliceInLeft<<" "<<chancesAliceInRight<<endl;
        cout<<"Bob: "<<chancesBobInLeft<<" "<<chancesBobInRight<<endl;

        if(helper(left,right,chancesAliceInLeft,chancesAliceInRight,chancesBobInLeft,chancesBobInRight)==true) return true;

        if((lVacent+rVacent)&1) return true; //alice will get extra chance

        return false;
    }
};
