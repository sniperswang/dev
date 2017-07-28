
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
  
class Solution {
public:
    string minWindow(string s, string t) {

        string res = "";
        if(t.size() > s.size())
            return res;

        unordered_map<char, int> tMap;
        int counter = 0;
        for (int i = 0; i < t.size(); i++)
        {
            tMap[t[i]] ++;
        }

        int begin = 0;
        int end = 0;
        int len = INT_MAX;

        while(end < s.size())
        {
            if (tMap.find(s[end]) != tMap.end())
            {
                if ( (--tMap[s[end]]) >= 0 ) 
                    counter++;
            }

            while (counter == t.size())
            {
                if ( (end - begin + 1)  < len )
                {
                    res = s.substr(begin, end-begin+1);
                    len = end - begin + 1;
                }

                if (len == t.size())
                    return res;

                if (tMap.find(s[begin]) != tMap.end())
                {
                    if ( ++tMap[s[begin]] > 0 ) 
                        counter --;
                }
                begin++;
            }
            end++;
        }

        return res;
    }
};

int main() 
{
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution ss;
    cout << ss.minWindow(s,t) << endl;
    return 0;
}
