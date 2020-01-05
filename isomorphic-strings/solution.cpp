// https://leetcode.com/problems/isomorphic-strings/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s_mappings;
        unordered_map<char, char> t_mappings;
        
        for (int i = 0; i < s.size(); ++i)  {
            auto it = s_mappings.find(s[i]);
            if (it != s_mappings.end() and it->second != t[i]) return false;
            it = t_mappings.find(t[i]);
            if (it != t_mappings.end() and it->second != s[i]) return false;
            s_mappings[s[i]] = t[i];
            t_mappings[t[i]] = s[i];
        }
        return true;
    }
};