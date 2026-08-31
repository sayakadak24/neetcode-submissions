class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); i++){
            // We check if the current element is greater than top, if yes, we pop the top
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int s = st.top();
                ans[s] = i - s;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};