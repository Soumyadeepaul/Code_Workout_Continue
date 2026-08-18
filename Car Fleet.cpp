//https://leetcode.com/problems/car-fleet/



class Solution {
public:
    // bool check(vector<int> &a, vector<int> &b,int & target){

    // }

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<float>> joins;

        for(int i=0;i<position.size();i++){
            joins.push_back({(float)position[i],(float)(target-position[i])/((float)speed[i])});
        }

        sort(joins.begin(),joins.end());
        int count=position.size();
        stack<float> st;
        for(int i=0;i<joins.size();i++){
            if(st.empty()){
                st.push(joins[i][1]);
            }
            else{
                while(!st.empty()){
                    auto top=st.top();
                    if(top<=joins[i][1]){
                        count--;
                        st.pop();
                    }
                    else break;
                }
                st.push(joins[i][1]);
            }
        }
        return count;
    }
};
