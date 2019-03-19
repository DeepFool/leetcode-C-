#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return -1;

        int left = 0, right = nums.size()-1;

        while(left <= right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < nums[right])
            {
                if(nums[mid]< target && nums[right] >= target)
                    left = mid+1;
                else
                    right = mid-1;
            }

            else
            {
                if(nums[mid] > target && nums[left]<= target)
                    right = mid-1;
                else
                    left = mid+1;
            }

        }

        return -1;

    }
};


int main() {

    vector<int> nums{4,5,6,7,0,1,2};
    vector<int> nums1{4,5,6,7,0,1,2};


    Solution s;
    cout<<s.search(nums,4)<<endl;
    cout<<s.search(nums,3)<<endl;
    cout<<s.search(nums,2)<<endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}