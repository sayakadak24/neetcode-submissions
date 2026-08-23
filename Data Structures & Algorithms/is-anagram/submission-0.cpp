class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> string1;
        unordered_map <char, int> string2;
        for(auto &ch: s){
            string1[ch]++;
        }
        for(auto &ch: t){
            string2[ch]++;
        }
        
        return string1 == string2;
    }
};
