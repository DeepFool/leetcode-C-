#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<unordered_map<char,int>> rows(9);
        vector<unordered_map<char,int>> columns(9);
        vector<unordered_map<char,int>> boxs(9);


        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                char num = board[i][j];

                if(num != '.')
                {

                    if (rows[i].find(num) == rows[i].end()) {
                        rows[i][num] = 1;
                    } else
                        rows[i][num]++;


                    if(columns[j].find(num) == columns[j].end())
                        columns[j][num] = 1;
                    else
                        columns[j][num] ++;

                    int idx = (i/3) * 3 + j / 3;

                    if(boxs[idx].find(num) == boxs[idx].end())
                        boxs[(i/3)*3 + j/3][num] = 1;
                    else
                        boxs[(i/3)*3+j/3][num] ++;


                    if (rows[i][num] > 1 || columns[j][num]>1 || boxs[idx][num] > 1)
                        return false;

                }


            }
        }

    return true;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}