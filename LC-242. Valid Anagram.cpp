// ethod-1 comparing  freq of characters O(26) i.e. constant extra space and O(n) time 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return 0;
        vector<int>check(26,0);
        for(int i=0;i<s.size();i++)
        {
            check[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++)
        {
            if(check[t[i]-'a'])
            {
               check[t[i]-'a']--; 
            } 
            else return 0;
        }   
        return 1;     
    }
};

// using sorting  O(1) extra space and O(n*logn) time 
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() !=t.size()) return false;

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        
        for(int i=0;i<s.size() ;i++)
        {
            if(s[i] !=t[i]) return false;
        }
        return true;
    }
};
