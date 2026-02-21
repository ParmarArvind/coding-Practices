class Solution {
public:
    string reverseVowels(string s) {
     
    int end=s.size()-1;
    int start=0;
    while(start<=end)
    {
           if(s[start]=='A' || s[start]=='E' || s[start]=='I' || s[start]=='O' || s[start]=='U'|| s[start]=='a' || s[start]=='e' || s[start]=='i' || s[start]=='o'|| s[start]=='u' )

        {
            if(s[end]=='a' || s[end]=='e' || s[end]=='i' || s[end]=='o'|| s[end]=='u'||s[end]=='A' || s[end]=='E' || s[end]=='I' || s[end]=='O'|| s[end]=='U') {
                char temp=s[start];
                s[start]=s[end];
                s[end]=temp;
                end--; start++;
            }
            else end--;
        }

        else 
        {
            if (s[end]=='a' || s[end]=='e' || s[end]=='i' || s[end]=='o'|| s[end]=='u'|s[end]=='A' || s[end]=='E' || s[end]=='I' || s[end]=='O'|| s[end]=='U')
            {
                start++;
            }
            else end--,start++;
        }
    }
    return s;
    }
};
