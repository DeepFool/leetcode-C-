#include <iostream>
#include <vector>

using namespace std;


/*
 * 矩阵旋转 = 转置 + 对称
 * 矩阵论证明过。
 *
 */


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //转置
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i+1;j<matrix.size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //对称

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size()/2;j++)
            {
                swap(matrix[i][j],matrix[i][matrix.size()-j-1]);
            }
        }


    }
};

int main() {

    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix.size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    cout<<endl;

    Solution().rotate(matrix);

    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix.size();j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }




    std::cout << "Hello, World!" << std::endl;
    return 0;
}