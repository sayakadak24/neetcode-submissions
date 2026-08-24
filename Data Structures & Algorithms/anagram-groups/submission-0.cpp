class Solution {
public:
    bool isAnagram (string s1, string s2) {
        int count[26] = {0};
        int res = 0;
        if(s1.length() == s2.length()) {
            for(int i = 0; i<s1.length(); i++) {
                count[s1[i] - 'a']++;
                count[s2[i] - 'a']--;
            }

            for(auto c: count){
                if(c != 0) {return false;}
            }
            return true;
        }
        return false;
    }

    string signature(string s) {
        string key = "";
        int count[26] = {0};
        for(char ch: s){
            count[ch - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            // Append the count and a delimiter
            key += to_string(count[i]) + "#"; 
        }
        return key;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> table;
        // assign a key to each string
        for(string s: strs){
            table[signature(s)].push_back(s);
        }

        vector<vector<string>> result;

        for(auto &t: table) {
            result.push_back(t.second);
        }
        return result;

    }
};
