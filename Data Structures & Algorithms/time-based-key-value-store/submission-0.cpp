class TimeMap {
private:
    unordered_map<string, vector<pair<string, int>>> time_dict;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time_dict[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        if(time_dict.find(key) == time_dict.end()){
            return "";
        }
        const auto& values = time_dict[key];
        int l = 0, r = values.size() - 1;
        string result = "";
        while (l <= r) {
        int mid = l + (r - l) / 2;
        if (values[mid].second <= timestamp) {
                result = values[mid].first;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
        
    }
};
