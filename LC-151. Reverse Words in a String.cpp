//method -1 
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i = s.size() - 1;

        while (i >= 0) {
           //skip space in front off string
            while (i >= 0 && s[i] == ' ') i--;
            
            if (i < 0) break; 

            string sub;
            while (i >= 0 && s[i] != ' ') {
                sub.push_back(s[i]);
                i--;
            }

            reverse(sub.begin(), sub.end());
            if (!ans.empty()) ans.push_back(' '); // Avoid adding leading space
            ans.append(sub);
        }

        return ans;
    }
};

//method -2 use of stringstream
class Solution {
public:
    string reverseWords(string s) {
        stringstream  ss(s);

        string result="";
        string token="";

        while(ss >> token){
            result = token+ ' '+ result;
        }

        return result.substr(0,result.size()-1);// remove the last sapce
    }
};

//method -3 (two pointer)
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int i = 0;
        int n = s.size();
        
        // skip leading spaces
        while(i < n && s[i] == ' ') i++;
        
        int l = 0, r = 0;
        
        while(i < n) {
            if(s[i] != ' ') {
                s[r] = s[i];
                r++;
            }
            else {
                if(l != r) {
                    reverse(s.begin() + l, s.begin() + r);
                    s[r] = ' ';
                    r++;
                    l = r;
                }
            }
            i++;
        }

        // reverse the last word
        if(l != r)
            reverse(s.begin() + l, s.begin() + r);

        // remove trailing space
        if(r > 0 && s[r-1] == ' ') r--;

        return s.substr(0, r);
    }
};

//mwthod -4 (Two Pointer clean)
class Solution {
public:
    string reverseWords(string s) {
        //1. reverse whole string
        
        reverse(s.begin(), s.end());
        
        int i = 0;
        //hero honge hamare l and r jo revrese karenge words ko
        int l = 0, r = 0;
        
        int n = s.length();
        
        while(i < n) {
            while(i < n && s[i] != ' ') { //i ko agar char dikha to r ko dega and i++ and r++
                s[r++] = s[i++];
            }
            
            if(l < r) { //l     r
                reverse(s.begin()+l, s.begin()+r);
                
                s[r] = ' ';
                r++;
                
                l = r;
            }
            
            i++; //ye to badhta rahega
        }
        
        s = s.substr(0 , r-1);
        return s;
    }
};
