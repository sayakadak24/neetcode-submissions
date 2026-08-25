class Solution {
public:
    int trap(vector<int>& height) {
        // at ith index, the water contained is
        int total_water = 0;
        vector<int> left_wall (height.size(), 0);
        vector<int> right_wall (height.size(), 0);
        left_wall[0] = height[0];
        for(int i=1; i<height.size(); i++) {
            left_wall[i] = max(height[i],left_wall[i-1]);
        }

        right_wall[height.size() - 1] = height[height.size() - 1];
        for(int i=height.size() - 2; i>=0; i--) {
            right_wall[i] = max(height[i],right_wall[i+1]);
        }

        for(int i=0; i<height.size(); i++){
            int water = (min(left_wall[i],right_wall[i])-height[i]);
            if(water > 0){
                total_water += water;
            }
        }
        return total_water;
    }
};