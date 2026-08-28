class Solution {
public:
    int characterReplacement(string s, int k) {
        int table[26] = {0};
        int left = 0;
        int window_size = 0;
        int freq_max = 0;
        int max_window_size = 0;
        for(int i=0; i<s.length(); i++){
            // Right pointer moves
            table[s[i] - 'A']++;
            freq_max = max(freq_max, table[s[i] - 'A']);
            window_size = i - left + 1;
            // Left pointer moves
            if(window_size - freq_max > k){
                table[s[left] - 'A']--;
                left++;
                window_size--;
            }
            
            max_window_size = max(window_size, max_window_size);
            
        }
        return max_window_size;
    }
};
