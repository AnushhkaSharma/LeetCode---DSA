class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        vector<int>unmatched;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    unmatched.push_back(i);
                }
                else {
                    st.pop();
            }
        }
    }


    while (!st.empty()) {
        unmatched.push_back(st.top());
        st.pop();
    }

    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (find(unmatched.begin(), unmatched.end(), i) == unmatched.end()) {
            result += s[i];
        }
    }
    return result;
    }
};