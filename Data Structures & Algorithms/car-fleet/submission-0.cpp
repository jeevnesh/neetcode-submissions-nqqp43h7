class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(), arr.end(), greater<>());
        int fleets = 0;
        double lastFleetTime = 0;
        for(auto &car : arr){
            double time = (double)(target - car.first)/car.second;
            if(time > lastFleetTime){
                fleets++;
                lastFleetTime = time;
            }
        } 
        return fleets;
    }
};
