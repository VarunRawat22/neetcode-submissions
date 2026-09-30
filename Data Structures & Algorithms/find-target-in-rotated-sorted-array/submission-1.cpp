class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            // target found
            if(nums[mid] == target)
                return mid;


            // duplicates case
            // can't determine which half is sorted
            if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                low++;
                high--;
                continue;
            }


            // LEFT HALF is sorted
            if(nums[low] <= nums[mid]){

                // target lies inside left sorted half
                if(nums[low] <= target && target < nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }

            // RIGHT HALF is sorted
            else{

                // target lies inside right sorted half
                if(nums[mid] < target && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};