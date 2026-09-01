class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        for(int i=0; i<heights.size(); i++) {
            // We check if the new member is blocking the last bar from stretching, if yes, we calculate the max area the bar can get and pop it
            while(!st.empty() && heights[i] < heights[st.top()]) {
                // Get the top element and calculate the max area it could get
                int h = st.top();
                st.pop();
                int w = 0;
                // If the stack becomes empty after the pop, the width is i else it's i - st.top() - 1;
                if(!st.empty()) {w = i - st.top() - 1;}
                else {w = i;}

                max_area = max(max_area, heights[h]*w);
            }
            st.push(i);
        }

        while(!st.empty()) {
            int h = st.top();
            st.pop();
            int w = 0;
            
            if(!st.empty()) {
                w = heights.size() - st.top() - 1;
            } else {
                w = heights.size();
            }
            max_area = max(max_area, heights[h] * w);
        }
        return max_area;
    }
};
