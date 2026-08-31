class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> cars;

        for(int i=0;i<n;i++){
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }

        sort(cars.rbegin(),cars.rend());  // sort by position descending

        stack<double> st;
        for(auto &car:cars){
            double t = car.second;
            if(st.empty() || t > st.top()){
               st.push(t); 
            }  
            // else merges into existing fleet → do nothing
        }
    return st.size();
    }
};
