#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
private:
    vector<int> dx{0,0,1,-1};
    vector<int> dy{1,-1,0,0};


    bool backtracking(vector<vector<char>>& board,string word,int k, int x, int y,vector<vector<bool>> &isvisited)
    {
        if(x<0 || x >= board.size() || y<0 || y>= board[0].size() || isvisited[x][y] == true || board[x][y] != word[k])
            return false;

        if(word.size()==k+1)
            return true;

        isvisited[x][y] = true;

        for(int i=0;i<4;i++)
        {
            if(backtracking(board, word, k+1,x+dx[i],y+dy[i],isvisited))
                return true;
        }

        isvisited[x][y] = 0;
        return false;
    }


public:
    bool exist(vector<vector<char>>& board, string word)
    {
        if(word.size() == 0) return true;
        int m = board.size(), n = board[0].size();

        vector<vector<bool>> isvisited(m,vector<bool>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                isvisited[i][j] = false;
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(backtracking(board, word, 0, i, j, isvisited))
                {
                    return true;
                }
            }
        }

    return false;


    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}