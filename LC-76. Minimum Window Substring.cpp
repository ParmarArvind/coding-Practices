class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char,int> mp;
        unordered_map<char,int> visited;

        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]++;
        }

        int n = s.size();
        int i = 0;
        int j = 0;
        string result = "";

        while(j < n)
        {
            if(mp.find(s[j]) != mp.end())
            {
                visited[s[j]]++;
            }

            while(i <= j && mp.find(s[i]) == mp.end())
                i++;

            while(i <= j && mp.find(s[i]) != mp.end() && visited[s[i]] > mp[s[i]])
            {
                visited[s[i]]--;
                i++;

                while(i <= j && mp.find(s[i]) == mp.end())
                    i++;
            }

            if(visited.size() == mp.size())
            {
                bool flag = true;
                for(auto &it : mp)
                {
                    if(visited[it.first] < it.second)
                    {
                        flag = false;
                        break;
                    }
                }

                if(flag && (result == "" || result.size() > j - i + 1))
                {
                    result = s.substr(i, j - i + 1);
                }
            }

            j++;
        }

        return result;
    }
};
