#include <iostream>
#include <vector>

using namespace std;

/* 回溯法，有点类似全排列的问题 */
class Solution {
private:
    vector<vector<int>> result;

    void backtracking(int n,int k,int curr,vector<int> &tmp)
    {
        if(tmp.size() == k)
        {
            result.push_back(tmp);
            return ;
        }

        for(int i = curr; i <= n-k+1;i++)
        {
            tmp.push_back(i);
            backtracking(n+1,k,i+1,tmp);
            tmp.pop_back();
        }
    }



public:
    vector<vector<int>> combine(int n, int k) {
        result.clear();

        vector<int> tmp;

        backtracking(n,k,1,tmp);

        return result;



    }
};

int main() {
    vector<vector<int>> result = Solution().combine(4,2);

    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}