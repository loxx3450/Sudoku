#pragma once
class Change
{
public:
    int** strToCol(int** tmp)
    {
        int temp;

        for (int i{}; i < 9; ++i)
        {
            for (int j{i}; j < 9; ++j)
            {
                if (i != j)
                {
                    temp = tmp[i][j];
                    tmp[i][j] = tmp[j][i];
                    tmp[j][i] = temp;
                }
            }
        }

        return tmp;
    }

    int** Mirror(int** tmp)
    {
        int temp;

        for (int i{}; i < 9; ++i)
        {
            for (int j{}; j < 4; ++j)
            {
                temp = tmp[i][j];
                tmp[i][j] = tmp[i][8 - j];
                tmp[i][8 - j] = temp;
            }
        }

        return tmp;
    }

    int** upsideDown(int** tmp)
    {
        int temp;

        for (int i{}; i < 4; ++i)
        {
            for (int j{}; j < 9; ++j)
            {
                temp = tmp[i][j];
                tmp[i][j] = tmp[8 - i][j];
                tmp[8 - i][j] = temp;
            }
        }

        return tmp;
    }

    int** fieldsByStr(int** tmp, int tmp_i, int multiply = 1)
    {
        int temp;

        for (int i{tmp_i}; i < tmp_i + 3; ++i)
        {
            for (int j{}; j < 9; ++j)
            {
                temp = tmp[i][j];
                tmp[i][j] = tmp[i + 3 * multiply][j];
                tmp[i + 3 * multiply][j] = temp;
            }
        }

        return tmp;
    }

    int** fieldsByCol(int** tmp, int tmp_i, int multiply = 1)
    {
        int temp;

        for (int i{}; i < 9; ++i)
        {
            for (int j{tmp_i}; j < tmp_i + 3; ++j)
            {
                temp = tmp[i][j];
                tmp[i][j] = tmp[i][j + 3 * multiply];
                tmp[i][j + 3 * multiply] = temp;
            }
        }

        return tmp;
    }

    int** swapStrs(int** tmp, int tmp1_i, int tmp2_i)
    {
        int temp;

        for (int j{}; j < 9; ++j)
        {
            temp = tmp[tmp1_i][j];
            tmp[tmp1_i][j] = tmp[tmp2_i][j];
            tmp[tmp2_i][j] = temp;
        }

        return tmp;
    }

    int** swapColumns(int** tmp, int tmp1_j, int tmp2_j)
    {
        int temp;

        for (int i{}; i < 9; ++i)
        {
            temp = tmp[i][tmp1_j];
            tmp[i][tmp1_j] = tmp[i][tmp2_j];
            tmp[i][tmp2_j] = temp;
        }

        return tmp;
    }
};