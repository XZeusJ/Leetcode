class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26);
        
        for (char &c: magazine) {
            freq[c-'a']++;
        }
        for (char &c: ransomNote) {
            freq[c-'a']--;
            if (freq[c-'a'] == -1) return false;
        }
        return true;
    }
};