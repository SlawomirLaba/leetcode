class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t overall_size = nums1.size() + nums2.size();
        int index_to_find = overall_size / 2 + 1;
        bool even = !(overall_size % 2);
        auto it1end = std::end(nums1);
        auto it2end = std::end(nums2);
        int old = 0;
        int cur = 0;

        for(auto it1 = std::begin(nums1), it2 = std::begin(nums2) ;;) {
            if(it1 != it1end && it2 != it2end) {
                if (*it1 <= *it2) {
                    if (even)
                        old = cur;
                    cur = *it1;
                    it1++;
                } else {
                    if (even)
                        old = cur;
                    cur = *it2;
                    it2++;
                }
            } else if (it1 != it1end) {
                if(even)
                    old = cur;
                cur = *it1;
                it1++;
            } else {
                if (even)
                    old = cur;
                cur = *it2;
                it2++;
            }

            if (--index_to_find == 0) {
                if(even)
                    return static_cast<double>(cur + old) / 2;
                else
                    return cur;
            }
        }
    }
};