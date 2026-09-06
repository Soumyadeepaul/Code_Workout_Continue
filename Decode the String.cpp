//https://www.geeksforgeeks.org/problems/decode-the-string2444/1


class Solution {
  public:
    string decodedString(string &s) {
        // code here
        stack<string> st;
        for(char ch:s){
            if(ch==']'){
                string store="";
                while(true){
                    string get=st.top();
                    st.pop();
                    if(get==string(1,'[')) {
                        string k="";
                        while(!st.empty()){
                            auto helper=st.top();
                            if(helper.size()==1 && helper>=string(1,'0') && helper<=string(1,'9')){
                                k=helper[0]+k;
                                st.pop();
                            }
                            else break;
                        }
                        
                        int l=stoi(k);
                        string temp = store; 
                        store = ""; 
                        for(int i = 0; i < l; i++) {
                            store += temp; 
                        }

                        break;
                    }
                    else {
                        store=get+store;
                    }
                }
                st.push(store);
            }
            else{
                st.push(string(1,ch));
            }
        }
        string result="";
        while(!st.empty()){
            result=st.top()+result;
            st.pop();
        }
        return result;
    }
};
