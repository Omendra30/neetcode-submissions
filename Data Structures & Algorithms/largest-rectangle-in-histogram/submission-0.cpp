class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i-st.top()-1;
                maxArea = max(maxArea, h*width);
            }
            st.push(i);
        }

        while(!st.empty()){
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? n : n-st.top()-1;
            maxArea = max(maxArea, h*width);
        }
        return maxArea;
    }
};
