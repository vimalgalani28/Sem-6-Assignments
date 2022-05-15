#include <bits/stdc++.h>
using namespace std;

class Astar
{
private:
    int h[7][7] = {{-1, -1, -1, -1, -1, -1, -1},
                   {-1, 0, -1, 0, 0, 0, -1},
                   {-1, 0, 0, 0, -1, 0, -1},
                   {-1, -1, 0, -1, -1, 0, -1},
                   {-1, 0, 0, 0, 0, 0, -1},
                   {-1, 0, 0, 0, 0, 0, -1},
                   {-1, -1, -1, -1, -1, -1, -1}};
    char board[7][7] = {{'1', '1', '1', '1', '1', '1', '1'},
                        {'1', 'S', '1', '0', '0', '0', '1'},
                        {'1', '0', '0', '0', '1', '0', '1'},
                        {'1', '1', '0', '1', '1', '0', '1'},
                        {'1', '0', '0', '0', '0', '0', '1'},
                        {'1', '0', '0', '0', '0', 'E', '1'},
                        {'1', '1', '1', '1', '1', '1', '1'}};
    int x = 1;
    int y = 1;
    string sort(map<string, int> &M)
    {
        multimap<int, string> MM;
        for (auto &it : M)
            MM.insert(pair<int, string>(it.second, it.first));
        for (auto &it : MM)
            return it.second;
        return "";
    }

public:
    Astar()
    {
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                if (h[i][j] != -1)
                    h[i][j] = 10 - i - j;
            }
        }
    };
    void printBoard()
    {
        cout << endl
             << "----------------------------------" << endl
             << endl;
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                cout << board[i][j] << "\t";
            }
            cout << endl;
        }
    }

    int helper()
    {
        int count = 0;
        while (true)
        {
            if (x == 5 && y == 5)
            {
                break; // reached the destination
            }
            int above, below, left, right;
            bool aboveFlag = false, belowFlag = false, leftFlag = false, rightFlag = false;
            map<string, int> dict;
            if (h[x][y - 1] != -1)
            { // No obstacle towards left
                dict["left"] = count + h[x][y - 1];
            }
            if (h[x][y + 1] != -1)
            { // No obstacle towards right
                dict["right"] = count + h[x][y + 1];
            }
            if (h[x - 1][y] != -1)
            { // No obstacle above
                dict["above"] = count + h[x - 1][y];
            }
            if (h[x + 1][y] != -1)
            { // No obstacle below
                dict["below"] = count + h[x + 1][y];
            }
            if (dict.empty())
            {
                printBoard();
                cout << "No way found...";
                return count;
            }
            string where = sort(dict); // find node with minimun f(n)
            if (where == "above")
            {
                h[x][y] = -1;
                board[x][y] = '^';
                x--;
            }
            else if (where == "below")
            {
                h[x][y] = -1;
                board[x][y] = 'v';
                x++;
            }
            else if (where == "left")
            {
                h[x][y] = -1;
                board[x][y] = '<';
                y--;
            }
            else if (where == "right")
            {
                h[x][y] = -1;
                board[x][y] = '>';
                y++;
            }
            count++;
        }
        return count;
    }
};

int main()
{
    Astar a;
    a.printBoard();
    int steps = a.helper();
    a.printBoard();
    cout<<"Number of steps: "<<steps<<endl;
    return 0;
}