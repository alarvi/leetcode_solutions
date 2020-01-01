// https://leetcode.com/problems/top-k-frequent-words/
class WordCompare
{
public:
    bool operator() (const pair<int, string>& lhs, const pair<int, string>&rhs) const
    {
        if (lhs.first != rhs.first) return lhs.first < rhs.first;
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordFrequency;
        
        for (const string& word : words) {
            ++wordFrequency[word];
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, WordCompare> sortedFrequency;
        for (const auto& [key, value]: wordFrequency) {
            sortedFrequency.push(make_pair(value, key));
        }
        
        vector<string> kMostFrequent;
        kMostFrequent.reserve(k);
        while (k-- > 0) {
            kMostFrequent.push_back(sortedFrequency.top().second);
            sortedFrequency.pop();
        }
        return kMostFrequent;
    }
};