class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            // If we are on a descending slope, the peak is at mid or to the left.
            if (nums[mid] > nums[mid + 1]) {
                high = mid; 
            } 
            // If we are on an ascending slope, the peak is strictly to the right.
            else {
                low = mid + 1; 
            }
        }
        
        // When low == high, we have narrowed our search down to one element, which is the peak.
        return low; 
    }
};