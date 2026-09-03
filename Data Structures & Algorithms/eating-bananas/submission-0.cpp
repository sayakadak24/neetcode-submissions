class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mid = 0;
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int ans = right;
        while(left <= right) {
            mid = left + (right - left)/2;
            long long time = 0;
            for(auto pile: piles){
                time += ((pile + mid - 1)/mid);
            }
            if(time <= h) {
                // check again if a smaller answer is possible else return the answer
                ans = min(ans,mid);
                right = mid - 1;
            }
            else if(time > h) {
                left = mid + 1;
            }
        }
        return ans;
    }
};
