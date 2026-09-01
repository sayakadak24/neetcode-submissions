class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(), 0);

        for(int i=0; i<temperatures.size(); i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int s = st.top();
                st.pop();
                ans[s] = i - s;
            }
            st.push(i);
        }

        return ans;
    }
};
