int Solution::numRookCaptures(vector<vector<char>>& board)
{
    //R只有四个方向四个方向去找
    int x = -1, y = -1;
    int result = 0;

    //find R
    for (int i = 0; i<8; i++)
    {
        for (int j = 0; j<8; j++)
            if (board[i][j] == 'R')
            {
                x = i;
                y = j;
            }

    }

    if (x == -1 || y == -1)
        return 0;

    //左
    for (int i = y - 1; i >= 0; i--)
    {
        if (board[x][i] == 'B')
        {
            break;
        }

        if (board[x][i] == 'p')
        {
            result++;
            break;
        }
    }

    //右
    for (int i = y + 1; i < 8; i++)
    {
        if (board[x][i] == 'B')
        {
            break;
        }

        if (board[x][i] == 'p')
        {
            result++;
            break;
        }
    }

    //上
    for (int i = x - 1; i >= 0; i--)
    {
        if (board[i][y] == 'B')
        {
            break;
        }

        if (board[i][y] == 'p')
        {
            result++;
            break;
        }
    }

    //右
    for (int i = x + 1; i < 8; i++)
    {
        if (board[i][y] == 'B')
        {
            break;
        }

        if (board[i][y] == 'p')
        {
            result++;
            break;
        }
    }

    return result;
}