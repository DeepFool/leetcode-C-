#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int left = 0, right = nums.size()-1;

        if(nums[0] < nums[right])
            return nums[0];

        while(left < right)
        {
            int mid = (left+right) / 2;

            /*
            if(nums[mid] > nums[mid+1])
                return nums[mid+1];
            if(nums[mid] < nums[mid-1])
                return nums[mid];
            */

            if(nums[mid] < nums[right])
            {
                right = mid;
            }
            else if(nums[mid] > nums[right])
            {
                left = mid+1;
            }
            else //nums[mid] == nums[right]
            {
                right --;
            }


        }
        return nums[left];

    }
};


int main() {
    vector<int> nums{1,3,5};
    cout<<Solution().findMin(nums)<<endl;

    vector<int> nums1{2,2,2,0,1};
    cout<<Solution().findMin(nums1)<<endl;

    vector<int> nums2{1,1};
    cout<<Solution().findMin(nums2)<<endl;

    vector<int> nums3{3,1,3};
    cout<<Solution().findMin(nums3)<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}