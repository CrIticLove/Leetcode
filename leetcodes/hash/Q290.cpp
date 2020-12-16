#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        unordered_map<char, string>::iterator map1it;
        unordered_map<string, char>::iterator map2it;
        string substr;
        int index = 0;
        for (char c : pattern)
        {
            substr = getNextStr(index, s);
            if (substr == "")
                return false;
            map1it = map1.find(c);
            map2it = map2.find(substr);
            if (map1it != map1.end() && map2it != map2.end())
            {
                if (map1it->second != substr || map2it->second != c)
                {
                    return false;
                }
            }
            else if (map1it == map1.end() && map2it == map2.end())
            {
                map1.insert(make_pair(c, substr));
                map2.insert(make_pair(substr, c));
            }
            else
            {
                return false;
            }
        }
        if (index < s.length())
            return false;
        return true;
    }

    string getNextStr(int &index, string &s)
    {
        string ret = "";
        while (s[index] != ' ' && index < s.length())
        {
            ret += s[index];
            ++index;
        }
        ++index;
        return ret;
    }
};
