class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int>even(26,0);
        vector<int>odd(26,0);
        int n=s1.size();
        int m=s2.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++)
        {
            if(i%2==0) even[s1[i]-'a']++;
            else odd[s1[i]-'a']++;
        }

        for(int i=0;i<n;i++)
        {
            if(i%2==0) {
                if(even[s2[i]-'a']==0) return false;
                even[s2[i]-'a']--;
            }
            else {
                if(odd[s2[i]-'a']==0) return false;
                odd[s2[i]-'a']--;
            }
        }

        return true;

    }
};
