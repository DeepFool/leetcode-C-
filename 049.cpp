#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;
        map<string,int> mp;
        int idx=0;

        for(int i=0;i<strs.size();i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());

            if(mp.find(tmp) == mp.end())
            {
                mp[tmp] = idx;
                ++idx;
                vector<string> V1;
                V1.push_back(strs[i]);
                result.push_back(V1);
            }

            else
            {
                result[mp[tmp]].push_back(strs[i]);
            }
        }

        return result;

    }
};



class Solution1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> result;

        unordered_map<string,vector<string>> m;


        for(string &str:strs)
        {
            string tmp = str;
            sort(tmp.begin(),tmp.end());

            m[tmp].push_back(str);
        }


        for(auto a:m)
        {
            result.push_back(a.second);
        }

        return result;
    }

};




int main() {

    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = Solution().groupAnagrams(strs);

    for(int i=0;i<result.size();i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}