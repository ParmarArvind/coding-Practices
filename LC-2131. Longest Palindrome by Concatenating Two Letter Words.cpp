
// method - 1
//  TLE O(n^2)
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        int result=0;
        vector<bool>visited(n,false);
        bool isSameCount=false;
        for(int i=0;i<n;i++)
        {
            char ch11=words[i][0];
            char ch12=words[i][1];
            bool isSame=ch11 == ch12;

            if(visited[i]==false)
            {
                 bool flag=false;
               for(int j=i+1;j<n;j++)
               {
                    if(visited[j]==true) continue;
                    char ch21=words[j][0];
                    char ch22=words[j][1];
                    if(ch11 == ch22  && ch12 ==ch21)
                    {
                        visited[j]=true;
                        flag=true;
                        break;
                    }
               }
               if(flag) result+=4;
                else if(isSame && !isSameCount)
                {
                    result+=2;
                    isSameCount=true;
                }
                visited[i]=true;
            }
        }
        return result;
        
    }
};

// method - 2  using map
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string ,int>freq;
        int n=words.size();
        int result=0;
        for(int i=0;i<n;i++)
        {
            freq[words[i]]++;
        }
        bool centerUsed=false;
        for(auto it = freq.begin(); it != freq.end(); )
        {
            string word = it->first;
            int firstFreq = it->second;

            string rev = word;
            reverse(rev.begin(), rev.end());

            if(word == rev)
            {
                if(firstFreq % 2 == 1)
                {
                    if(!centerUsed)
                    {
                        centerUsed = true;
                        result += 2 * firstFreq;
                    }
                    else
                    {
                        result += 2 * (firstFreq - 1);
                    }
                }
                else
                {
                    result += 2 * firstFreq;
                }

                it = freq.erase(it);   
            }
            else if(freq.count(rev))
            {
                int secondFreq = freq[rev];
                result += 4*min(secondFreq ,firstFreq);

                freq.erase(rev);       // erase reverse
                it = freq.erase(it);  
            }
            else
            {
                ++it;
            }
        }
        return result;
        
    }
};
// method 3 
class Solution {
public: 

// easy calculation in last approac
    int longestPalindrome(vector<string>& words) {
        unordered_map<string ,int>freq;
        int n=words.size();
        
        for(int i=0;i<n;i++) freq[words[i]]++;
        
        bool centerUsed=false;
        int result=0;
        for(string &word : words)
        {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if(word == rev)
            {
                if(freq[word]>=2)
                {
                    freq[word] -=2;
                    result += 4;
                }  
                else if(freq[word]==1 && !centerUsed)
                {
                    freq[word]--;
                    result += 2;
                    centerUsed=true;
                }
            }
            else if(freq[word]>0 && freq[rev]>0)
            {
                freq[word]--;
                freq[rev]--;
                result += 4;
            }
        }
        return result;
        
    }
};
