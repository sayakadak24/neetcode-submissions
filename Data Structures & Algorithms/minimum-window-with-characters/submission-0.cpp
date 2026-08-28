class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) {return "";}

        unordered_map <char,int> t_map;
        unordered_map <char,int> window_map;

        for(char t1: t){
            t_map[t1]++;
        }
        int left = 0; int right = 0;
        int have = 0; int need = t_map.size();
        int string_length = 0; int min_string_length = INT_MAX;
        pair<int, int> min_pair; //Index,length

        // We increase the right pointer till we have all the characters we need, then we move the left pointer till we have the minimum required frequencies and record the length, than we again move the right pointer

        for (int right = 0; right < s.length(); right++) {
            // 1. Expand phase (add s[right] to window)
            window_map[s[right]]++;
            if(t_map.count(s[right]) && window_map[s[right]] == t_map[s[right]]){have++;}
            // 2. Shrink phase (while have == need)
            while(have == need) {
                string_length = right - left + 1;
                min_string_length = min(min_string_length, string_length);
                if(string_length == min_string_length){
                    min_string_length = string_length;
                    min_pair = {left, min_string_length};
                }
                window_map[s[left]]--;
                if(t_map.count(s[left]) && window_map[s[left]] < t_map[s[left]]){have--;}
                left++;

            }
        }


        if(min_string_length == INT_MAX) {
            return "";
        }else{
            return s.substr(min_pair.first, min_pair.second);
        }
    }
};
