class Solution {
public:
    bool checkValidString(string s) {
        stack<int>open;
        stack<int>star;
        int n=s.size();

        for(int i=0;i<n;i++)
        {
            if(s[i]=='*') star.push(i);
            else if(s[i]=='(') open.push(i);
            else {
                 if(!open.empty()) 
                {
                    open.pop();
                }else if(!star.empty())
                {
                    star.pop();
                }

                else return false;
            }
        }

        if(open.size() > star.size()) return false;

        while(!star.empty() && !open.empty())
        {
            if(star.top() > open.top()) {
                star.pop();
                open.pop();
            }
            else return false;
        }

    return true;
    }
};
