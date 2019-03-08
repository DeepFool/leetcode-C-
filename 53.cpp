#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;




/* 暴力查找,时间复杂度为 o(N2) */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxcount = INT_MIN;

        for(int i=0;i<nums.size();i++)
        {
            int tmp=0;

            for(int j=i;j<nums.size();j++)
            {

                tmp += nums[j];
                maxcount = max(tmp, maxcount);
            }

        }


    return maxcount;
    }
};


/* 动态规划，时间复杂度为o(N) */
class SolutionN {
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxcount = INT_MIN;
        int count = 0;

        for(int i=0;i<nums.size();i++)
        {

            count = max((count+nums[i]),nums[i]);
            maxcount = max(maxcount,count);
        }

        return maxcount;
    }
};



int main() {

    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};

    cout<<Solution().maxSubArray(nums)<<endl;
    cout<<SolutionN().maxSubArray(nums)<<endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}