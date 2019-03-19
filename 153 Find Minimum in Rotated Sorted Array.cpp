#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int left = 0,right = nums.size()-1;

        if(nums[0] < nums[right]) return nums[0];

        while(right >= left)
        {
            int mid = (left+right)/2;
            if(nums[mid] > nums[mid+1])
                return nums[mid+1];
            if(nums[mid] < nums[mid-1])
                return nums[mid];

            if(nums[mid] < nums[right])
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }

        return -1;
    }
};



class Solution1 {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];

        int left = 0,right = nums.size()-1;

        if(nums[0] < nums[right]) return nums[0];

        while(right > left)
        {
            int mid = (left+right)/2;

            if(nums[mid] < nums[right])
            {
                right = mid;
            }
            else
            {
                left = mid+1;
            }
        }

        return nums[left];
    }
};


int main() {
    vector<int> nums{3,4,5,1,2};
    cout<<Solution().findMin(nums)<<endl;

    vector<int> nums1{4,5,6,7,0,1,2};
    cout<<Solution().findMin(nums1)<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}