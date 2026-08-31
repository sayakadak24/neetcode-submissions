class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> lis;
        for(int i=0; i<position.size(); i++){
            lis.push_back({position[i],speed[i]});
        }
        sort(lis.begin(),lis.end(),greater<pair<int, int>>());
        // Time taken for closest car
        stack<double> st;
        int fleet = position.size();
        for(int i=0; i<position.size(); i++) {
            double time = (double)((target - lis[i].first))/lis[i].second;

            if(st.empty()){st.push(time);}
            else{
                if(time <= st.top()){
                    fleet--;
                }else{
                    st.push(time);
                }
            }
        }
        return fleet;
    }
};
