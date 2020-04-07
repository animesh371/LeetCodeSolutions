class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 5,7,8,8,8,8,10, target = 8
        //  Firstindex 
        // position = -1; 
        // if target is found , update the postion & search in left subarray
        
        //  LastIndex
        vector<int> result;
        int firstIndex = fistPosition(nums, target);
        int lastIndex = lastPosition(nums, target);
        result.push_back(firstIndex);
        result.push_back(lastIndex);
        return result;
    }
    
    int fistPosition(vector<int>& nums, int target) {
        int mid;
        int left = 0;
        int right = nums.size()-1;
        int position = -1; 
        
        while(left <= right) {
            mid = (left+right)/2;
            if(nums[mid] == target) {
                position = mid; 
                right = mid - 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return position;
        
    }
    
    int lastPosition(vector<int>& nums, int target) {
        int mid;
        int left = 0;
        int right = nums.size()-1;
        int position = -1; 
        
        while(left <= right) {
            mid = (left+right)/2;
            if(nums[mid] == target) {
                position = mid; 
                left = mid + 1;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return position;
    }
};
