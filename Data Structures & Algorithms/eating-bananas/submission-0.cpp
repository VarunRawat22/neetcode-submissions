
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalHours = 0;

            // Calculate hours at speed mid
            for (int bananas : piles) {
                totalHours += (bananas + (long long)mid - 1) / mid;
            }

            if (totalHours <= h) {
                // Possible speed, try smaller
                high = mid - 1;
            } else {
                // Too slow, increase speed
                low = mid + 1;
            }
        }

        return low;
    }
};
