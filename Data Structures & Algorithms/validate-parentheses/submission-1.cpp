class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> matching_bracket = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> st;
        for(char ch: s){
            // if ch is a closing bracket
            if(matching_bracket.count(ch) != 0) {
                if(!st.empty() && st.top() == matching_bracket[ch]) {st.pop();}
                else {return false;}
            }else{st.push(ch);}
        }
        return st.empty();
        
    }
};
