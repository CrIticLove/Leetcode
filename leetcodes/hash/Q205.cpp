#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> stot;
        unordered_map<char, char> ttos;
        unordered_map<char, char>::iterator stotIt;
        unordered_map<char, char>::iterator ttosIt;
        const int len = s.length();
        for (int i = 0; i < len; ++i)
        {
            stotIt = stot.find(s[i]), ttosIt = ttos.find(t[i]);
            if (stotIt == stot.end() && ttosIt == ttos.end())
            {
                stot.insert(make_pair(s[i], t[i]));
                ttos.insert(make_pair(t[i], s[i]));
            }
            else if (stotIt == stot.end() || ttosIt == ttos.end() ||
                     stotIt->second != t[i] || ttosIt->second != s[i])
            {
                return false;
            }
        }
        return true;
    }
};
