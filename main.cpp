#include <iostream>
#include <vector>
#include <hash_map>
#include <algorithm>

using namespace std;
using namespace __gnu_cxx;

/* 暴力搜索,时间复杂n2*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

/*VECTOR 向量find(),时间复杂度n*log(n)*/
class Solution1{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            if(find(nums.begin()+i+1,nums.end(),target-nums[i]) != nums.end())
            {
                auto iter = find(nums.begin()+i+1,nums.end(),target-nums[i]);
                result.push_back(i);
                result.push_back(iter-nums.begin());
                return result;
            }
        }
        return result;
    }
};

/*哈希表 */
class Solution2{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        hash_map<int,int> hs;

        for(int i=0;i<nums.size();i++)
        {
            if(hs.find(target-nums[i]) == hs.end())
            {
                hs[nums[i]] = i;
            }
            else {
                result.push_back(i);
                result.push_back(hs[target - nums[i]]);
                return result;
            }
        }
        return result;
    }
};







int main() {

    vector<int> nums{2,7,9,11};
    Solution1 s;

    vector<int> result=s.twoSum(nums,9);

    std::cout<<result[0]<<endl;
    cout<<result[1]<<endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}