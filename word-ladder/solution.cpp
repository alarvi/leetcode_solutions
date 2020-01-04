// https://leetcode.com/problems/word-ladder/
class Solution {
private:
    bool canTransform(const string& lhs, const string& rhs) {
        int diff = 0;
        for (int i = 0; i < lhs.size(); ++i) {
            if (lhs[i] != rhs[i]) ++diff;
            if (diff > 1) return false;
        }
        return true;
    }
    
    struct TransformationStep {
        string word;
        int wordIndex;
        int depth;
    };

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //build graph O(n^2)
        bool deps[wordList.size()][wordList.size()];
        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                deps[i][j] = canTransform(wordList[i], wordList[j]);
                deps[j][i] = deps[i][j];
            }
        }
        
        //BFS
        unordered_set<int> visited;
        queue<TransformationStep> pendingTransformations;
        
        //initial word O(n)
        for (int i = 0; i < wordList.size(); ++i) {
            if (canTransform(beginWord, wordList[i])) {
                pendingTransformations.push(TransformationStep{wordList[i], i, 2});
            }
        }
        
        //BFS O(n)
        while (not pendingTransformations.empty()) {
            TransformationStep tx = pendingTransformations.front();
            pendingTransformations.pop();
            if (visited.count(tx.wordIndex)) continue;
            visited.insert(tx.wordIndex);
            
            if (tx.word == endWord) return tx.depth;
            
            for (int i = 0; i < wordList.size(); ++i) {
                if (i == tx.wordIndex) continue;
                if (deps[tx.wordIndex][i] and not visited.count(i)) {
                    pendingTransformations.push(TransformationStep{wordList[i], i, tx.depth + 1});
                }
            }
        }
        return 0;
    }
};