class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_map(26, 0);
        vector<int> window_map(26, 0);
        if(s1.length()>s2.length()) {return false;}
        for(char s: s1){
            s1_map[s - 'a']++;
        }
        int l = 0;
        for(int i=0; i<s1.length(); i++){
            window_map[s2[i] - 'a']++;
        }
        if(s1_map == window_map) {return true;}
        for(int r=s1.length(); r<s2.length(); r++) {
            //Bring the new element and remove the old
            window_map[s2[r] - 'a']++;
            window_map[s2[l] - 'a']--;
            if(s1_map == window_map) {return true;}
            l++;
        }
        return false;
    }
};
