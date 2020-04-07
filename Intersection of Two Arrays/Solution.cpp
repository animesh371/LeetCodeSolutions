class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Time Complexity -> O(m+n) + O(max(m, n))
        // Space Complexity -> O(m+n)
        vector<int> result; 
        unordered_set<int> setOfNums1, setOfNums2;
        for(auto element: nums1) {
            setOfNums1.insert(element);
        }
        for(auto element: nums2) {
            setOfNums2.insert(element);
        }
        
        for(auto it = setOfNums1.begin(); it != setOfNums1.end(); ++it) {
            if(setOfNums2.find(*it) != setOfNums2.end()) {
                result.push_back(*it);
            }
        }
        return result;
    }
};