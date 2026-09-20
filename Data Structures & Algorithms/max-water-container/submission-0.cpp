class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l = 0;
        int r = n - 1;

        int maxWater = 0;

        while(l < r) {

            // Width between both lines
            int width = r - l;

            // Smaller line decides water height
            int h = min(height[l], height[r]);

            // Current container area
            int area = width * h;

            // Store maximum area
            maxWater = max(maxWater, area);

            if(height[l] < height[r]) {
                l++;
            }
            else {
                r--;
            }
        }

        return maxWater;
    }
};