class Solution {
public:
    int maxArea(vector<int>& heights) {
        int start = 0; int end = heights.size() - 1;
        int max_area = 0;
        int area = 0;
        while(start < end) {
            area = (end - start) * min(heights[end],heights[start]);
            if(heights[end] <= heights[start]) {
                end--;
            }else if(heights[end] > heights[start]) {
                start++;
            }
            max_area = max(area, max_area);
        }
        return max_area;
    }
};
