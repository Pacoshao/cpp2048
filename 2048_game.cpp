#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>
using namespace std;
int n;
int grid[4][4], grid2[4][4];
string o;
void Clear() { cout << "\x1B[2J\x1B[H"; }
bool is_same_g(int g1[4][4], int g2[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (g1[i][j] != g2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
bool is_over(int g1[4][4])
{
    int g2[4][4];
    int flag = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            g2[i][j] = 0;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int k = 0;
        int b = -1;
        for (int j = 0; j < 4; j++)
        {
            int a = g1[i][j];
            if (a == 0)
            {
                continue;
            }
            if (a == b)
            {
                g2[i][k] = b + a;
                k++;
                b = -1;
            }
            else
            {
                if (b != -1)
                {
                    g2[i][k] = b;
                    k++;
                }
                b = a;
            }
        }
        if (b != -1)
        {
            g2[i][k] = b;
        }
    }
    if (is_same_g(g1, g2))
    {
        flag++;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            g2[i][j] = 0;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int k = 3;
        int b = -1;
        for (int j = 3; j >= 0; j--)
        {
            int a = g1[i][j];
            if (a == 0)
            {
                continue;
            }
            if (a == b)
            {
                g2[i][k] = b + a;
                k--;
                b = -1;
            }
            else
            {
                if (b != -1)
                {
                    g2[i][k] = b;
                    k--;
                }
                b = a;
            }
        }
        if (b != -1)
        {
            g2[i][k] = b;
        }
    }
    if (is_same_g(g1, g2))
    {
        flag++;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            g2[i][j] = 0;
        }
    }
    for (int j = 0; j < 4; j++)
    {
        int k = 0;
        int b = -1;
        for (int i = 0; i < 4; i++)
        {
            int a = g1[i][j];
            if (a == 0)
            {
                continue;
            }
            if (a == b)
            {
                g2[k][j] = b + a;
                k++;
                b = -1;
            }
            else
            {
                if (b != -1)
                {
                    g2[k][j] = b;
                    k++;
                }
                b = a;
            }
        }
        if (b != -1)
        {
            g2[k][j] = b;
        }
    }
    if (is_same_g(g1, g2))
    {
        flag++;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            g2[i][j] = 0;
        }
    }
    for (int j = 0; j < 4; j++)
    {
        int k = 3;
        int b = -1;
        for (int i = 3; i >= 0; i--)
        {
            int a = g1[i][j];
            if (a == 0)
            {
                continue;
            }
            if (a == b)
            {
                g2[k][j] = b + a;
                k--;
                b = -1;
            }
            else
            {
                if (b != -1)
                {
                    g2[k][j] = b;
                    k--;
                }
                b = a;
            }
        }
        if (b != -1)
        {
            g2[k][j] = b;
        }
    }
    if (is_same_g(g1, g2))
    {
        flag++;
    }
    return flag == 4;
}
int main()
{
    srand(static_cast<unsigned>(time(0)));
    int r0 = 1 + rand() % 16;
    int r1 = 1 + rand() % r0;
    int r2 = r0 + 1 + (rand() % (16 - r0));
    cout << "Lucky number:" << r0 << "->" << r1 << "," << r2 << endl;
    int flag0 = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            flag0++;
            if (flag0 == r1 || flag0 == r2)
            {
                grid[i][j] = 2;
                cout << "2     ";
            }
            else
            {
                cout << ".     ";
            }
        }
        cout << endl;
    }
    // cout << "- - - - - - - - - -" << endl;
    while (1)
    {
        int ch;
        while (1)
        {
            if (_kbhit())
            {
                ch = _getch();
                // cout << ch;
                if (ch == 97)
                {
                    o = "L";
                    break;
                }
                else if (ch == 100)
                {
                    o = "R";
                    break;
                }
                else if (ch == 119)
                {
                    o = "U";
                    break;
                }
                else if (ch == 115)
                {
                    o = "D";
                    break;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                grid2[i][j] = 0;
            }
        }
        if (o == "L")
        {
            for (int i = 0; i < 4; i++)
            {
                int k = 0;
                int b = -1;
                for (int j = 0; j < 4; j++)
                {
                    int a = grid[i][j];
                    if (a == 0)
                    {
                        continue;
                    }
                    if (a == b)
                    {
                        grid2[i][k] = b + a;
                        k++;
                        b = -1;
                    }
                    else
                    {
                        if (b != -1)
                        {
                            grid2[i][k] = b;
                            k++;
                        }
                        b = a;
                    }
                }
                if (b != -1)
                {
                    grid2[i][k] = b;
                }
            }
        }
        else if (o == "R")
        {
            for (int i = 0; i < 4; i++)
            {
                int k = 3;
                int b = -1;
                for (int j = 3; j >= 0; j--)
                {
                    int a = grid[i][j];
                    if (a == 0)
                    {
                        continue;
                    }
                    if (a == b)
                    {
                        grid2[i][k] = b + a;
                        k--;
                        b = -1;
                    }
                    else
                    {
                        if (b != -1)
                        {
                            grid2[i][k] = b;
                            k--;
                        }
                        b = a;
                    }
                }
                if (b != -1)
                {
                    grid2[i][k] = b;
                }
            }
        }
        else if (o == "U")
        {
            for (int j = 0; j < 4; j++)
            {
                int k = 0;
                int b = -1;
                for (int i = 0; i < 4; i++)
                {
                    int a = grid[i][j];
                    if (a == 0)
                    {
                        continue;
                    }
                    if (a == b)
                    {
                        grid2[k][j] = b + a;
                        k++;
                        b = -1;
                    }
                    else
                    {
                        if (b != -1)
                        {
                            grid2[k][j] = b;
                            k++;
                        }
                        b = a;
                    }
                }
                if (b != -1)
                {
                    grid2[k][j] = b;
                }
            }
        }
        else if (o == "D")
        {
            for (int j = 0; j < 4; j++)
            {
                int k = 3;
                int b = -1;
                for (int i = 3; i >= 0; i--)
                {
                    int a = grid[i][j];
                    if (a == 0)
                    {
                        continue;
                    }
                    if (a == b)
                    {
                        grid2[k][j] = b + a;
                        k--;
                        b = -1;
                    }
                    else
                    {
                        if (b != -1)
                        {
                            grid2[k][j] = b;
                            k--;
                        }
                        b = a;
                    }
                }
                if (b != -1)
                {
                    grid2[k][j] = b;
                }
            }
        }
        // while (1)
        // {
        //     if (!_kbhit())
        //     {
        //         break;
        //     }
        // }
        if (is_same_g(grid, grid2))
        {
            continue;
        }
        int z = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid2[i][j] == 0)
                {
                    z++;
                }
            }
        }
        Clear();
        int r3 = -1;
        if (z == 0)
        {
            if (is_over(grid2))
            {
                cout << "Game Over..." << endl;
                break;
            }
        }
        else
        {
            r3 = 1 + rand() % z;
        }
        int flag = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (grid2[i][j] == 0)
                {
                    flag++;
                    if (flag == r3)
                    {
                        grid2[i][j] = 2;
                        cout << "2";
                    }
                    else
                    {
                        cout << ".";
                    }
                }
                else
                {
                    cout << grid2[i][j];
                }
                int l = to_string(grid2[i][j]).size();
                for (int space = 1; space <= 6 - l; space++)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        // cout << "- - - - - - - - - -" << endl;
        copy(&grid2[0][0], &grid2[0][0] + 16, &grid[0][0]);
    }
    cout << "Press any key to exit..." << endl;
    while (1)
    {
        if (_kbhit())
        {
            break;
        }
    }
    return 0;
}