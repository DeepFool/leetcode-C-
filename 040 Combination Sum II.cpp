#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
private:
    vector<vector<int>> result;

    void backtracking(vector<int>& candidates, vector<int>& tmp,int start,int target)
    {
        if(target<0) return;
        if(target == 0)
        {
            result.push_back(tmp);
            return ;
        }

        for(int i=start;i<candidates.size();i++)
        {
            if(i>start && candidates[i] == candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            backtracking(candidates,tmp,i+1,target-candidates[i]);
            tmp.pop_back();
        }


    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());

        vector<int> tmp;
        backtracking(candidates,tmp,0,target);

        return result;

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}