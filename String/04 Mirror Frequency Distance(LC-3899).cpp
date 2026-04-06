class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int>letters(26,0);
        vector<int>digit(10,0);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i])) digit[s[i]-'0']++;
            else letters[s[i]-'a']++;
        }       

        int result=0;
        int i=0 ,j=25;
        while(i<j){
            result += abs(letters[i]-letters[j]);
            i++;
            j--;
        }
        i=0;
        j=9;
        while(i<j){
            result += abs(digit[i]-digit[j]);
            i++;
            j--;
        }

        return result;
    }
};
