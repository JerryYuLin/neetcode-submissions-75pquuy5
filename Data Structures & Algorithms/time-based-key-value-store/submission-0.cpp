class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> data;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        data[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if(data.find(key) == data.end()) return "";
        
        vector<pair<int, string>>& timestamp_data = data.at(key);

        int left = 0, right = timestamp_data.size(), mid;

        while(left < right) {
            mid = left + (right - left)/2;

            if (timestamp_data[mid].first <= timestamp) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        if(left==0) return "";


        return timestamp_data[left-1].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */