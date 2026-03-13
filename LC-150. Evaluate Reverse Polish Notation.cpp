class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<string> st;
        for(int i=0;i<n;i++)
        {
            if(tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-")
            {
                int result=0;
                int op2=stoi(st.top());st.pop();
                int op1=stoi(st.top());st.pop();
                if(tokens[i] == "/") result=op1/op2;
                else  if(tokens[i] == "+") result=op1+op2;
                 else  if(tokens[i] == "-") result=op1-op2;
                  else  if(tokens[i] == "*") result=op1*op2;
                  st.push(to_string(result));
            }
            else st.push(tokens[i]);
        }
        return stoi(st.top());
        
    }
};
