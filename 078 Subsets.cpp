#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> result;

    void backtracking(vector<int>& nums, vector<int> &tmp, int start)
    {
        result.push_back(tmp);
        for(int i = start;i<nums.size();i++)
        {
            tmp.push_back(nums[i]);
            backtracking(nums,tmp,i+1);
            tmp.pop_back();
        }
    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        backtracking(nums,tmp,0);

        return result;
    }
};


class Solution1 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]);
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};

int main() {
    vector<int> nums{1,2,3};

    vector<vector<int>> result = Solution().subsets(nums);

    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    vector<vector<int>> result1 = Solution1().subsets(nums);

    for(int i=0;i<result1.size();i++)
    {
        for(int j=0;j<result1[i].size();j++)
        {
            cout<<result1[i][j]<<" ";
        }
        cout<<endl;
    }



    std::cout << "Hello, World!" << std::endl;
    return 0;
}