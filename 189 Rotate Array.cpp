#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



// 空间复杂度 O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        if(nums.size() == 0 || nums.size()==1) return ;

        k = k % nums.size();

        vector<int> tmp = nums;

        for(int i=0;i<nums.size();i++)
        {
            tmp[(i+k) % nums.size()] = nums[i];
        }

        nums =  tmp;
        return ;
    }
};

// 空间复杂度为 O(1).
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0 || nums.size()==1) return ;
        k = k % nums.size();

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        return ;
    }
};

// 循环交换，空间复杂度为 O(N).

class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0 || nums.size()==1) return ;
        k = k % nums.size();

        int cnt = 0;

        for(int i=0;cnt<nums.size();i++)
        {
            int curr = i;
            int prev = nums[i];

            do{
                int next = (curr+k) % nums.size();
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                curr = next;
                cnt++;

            }while(i != curr);
        }


    }
};




int main() {
    vector<int> nums{1,2,3,4,5,6,7};
    Solution2().rotate(nums,3);
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;


    vector<int> nums1{-1,-100,3,99};
    Solution2().rotate(nums1,2);
    for(int i=0;i<nums1.size();i++)
    {
        cout<<nums1[i]<<" ";
    }
    cout<<endl;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}