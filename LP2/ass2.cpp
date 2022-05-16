#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> pPair;

struct cell
{
    int parent_i, parent_j;
    double f, g, h;
};

class Game
{
private:
    int ROW = 9;
    int COL = 10;
    int grid[9][10] = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                       {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
                       {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
                       {0, 1, 1, 0, 1, 0, 0, 0, 0, 1},
                       {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
                       {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
                       {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                       {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                       {1, 1, 1, 0, 0, 0, 1, 0, 0, 1}};
    cell cellDetails[9][10];
    Pair src = make_pair(8, 0);
    Pair dest = make_pair(0, 0);
    bool isValid(int row, int col)
    {
        return row >= 0 && col >= 0 && row < ROW && col < COL;
    }
    bool isUnblocked(int row, int col)
    {
        return grid[row][col] == 1;
    }
    bool isDestination(int row, int col)
    {
        return row == dest.first && col == dest.second;
    }
    double calculateHValue(int row, int col)
    {
        return ((double)sqrt((row - dest.first) * (row - dest.first) + (col - dest.second) * (col - dest.second)));
    }
    void tracePath()
    {
        cout <<"The Path is ";
        int row = dest.first;
        int col = dest.second;

        stack<Pair> Path;

        while (cellDetails[row][col].parent_i == row || cellDetails[row][col].parent_j == col)
        {
            Path.push(make_pair(row, col));
            int temp_row = cellDetails[row][col].parent_i;
            int temp_col = cellDetails[row][col].parent_j;
            row = temp_row;
            col = temp_col;
        }

        Path.push(make_pair(row, col));
        while (!Path.empty())
        {
            pair<int, int> p = Path.top();
            Path.pop();
            printf("-> (%d,%d) ", p.first, p.second);
        }

        cout << endl;
    }

public:
    Game() {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                cellDetails[i][j].f = FLT_MAX;
                cellDetails[i][j].g = FLT_MAX;
                cellDetails[i][j].h = FLT_MAX;
                cellDetails[i][j].parent_i = -1;
                cellDetails[i][j].parent_j = -1;
            }
        }
    }
    void aStar()
    {
        if (isValid(src.first, src.second) == false)
        {
            cout << "Invalid Source";
            return;
        }
        if (isValid(dest.first, dest.second) == false)
        {
            cout << "Invalid Destination";
            return;
        }
        if (isUnblocked(src.first, src.second) == false)
        {
            cout << "Source is blocked";
            return;
        }
        if (isUnblocked(dest.first, dest.second) == false)
        {
            cout << "Destination is blocked";
            return;
        }
        bool closedList[ROW][COL];
        memset(closedList, false, sizeof(closedList));
        int i = src.first, j = src.second;
        cellDetails[i][j].f = 0.0;
        cellDetails[i][j].g = 0.0;
        cellDetails[i][j].h = 0.0;
        cellDetails[i][j].parent_i = i;
        cellDetails[i][j].parent_i = j;
        set<pPair> openList;
        openList.insert(make_pair(0.0, make_pair(i, j)));
        bool foundDest = false;
        while (!openList.empty())
        {
            pPair p = *openList.begin();
            openList.erase(openList.begin());
            i = p.second.first;
            j = p.second.second;
            closedList[i][j] = true;
            double gNew, hNew, fNew;

            // North Successor
            if (isValid(i - 1, j))
            {
                if (isDestination(i - 1, j))
                {
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                    cout << "Destination is found\n";
                    // tracePath();
                    foundDest = true;
                    break;
                }
                else if (closedList[i - 1][j] == false && isUnblocked(i - 1, j))
                {
                    gNew = cellDetails[i][j].g + 1.0;
                    hNew = calculateHValue(i - 1, j);
                    fNew = gNew + hNew;
                    if (cellDetails[i - 1][j].f > fNew)
                    {
                        openList.insert(make_pair(
                            fNew, make_pair(i - 1, j)));
                        cellDetails[i - 1][j].f = fNew;
                        cellDetails[i - 1][j].g = gNew;
                        cellDetails[i - 1][j].h = hNew;
                        cellDetails[i - 1][j].parent_i = i;
                        cellDetails[i - 1][j].parent_j = j;
                    }
                }
            }

            // South Successor
            if (isValid(i + 1, j))
            {
                if (isDestination(i + 1, j))
                {
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                    cout << "Destination is found\n";
                    // tracePath();
                    foundDest = true;
                    break;
                }
                else if (closedList[i + 1][j] == false && isUnblocked(i + 1, j))
                {
                    gNew = cellDetails[i][j].g + 1.0;
                    hNew = calculateHValue(i + 1, j);
                    fNew = gNew + hNew;
                    if (cellDetails[i + 1][j].f > fNew)
                    {
                        openList.insert(make_pair(
                            fNew, make_pair(i + 1, j)));
                        cellDetails[i + 1][j].f = fNew;
                        cellDetails[i + 1][j].g = gNew;
                        cellDetails[i + 1][j].h = hNew;
                        cellDetails[i + 1][j].parent_i = i;
                        cellDetails[i + 1][j].parent_j = j;
                    }
                }
            }
            // East Successor
            if (isValid(i, j - 1))
            {
                if (isDestination(i, j - 1))
                {
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                    cout << "Destination is found\n";
                    // tracePath();
                    foundDest = true;
                    break;
                }
                else if (closedList[i][j - 1] == false && isUnblocked(i, j - 1))
                {
                    gNew = cellDetails[i][j].g + 1.0;
                    hNew = calculateHValue(i, j - 1);
                    fNew = gNew + hNew;
                    if (cellDetails[i][j - 1].f > fNew)
                    {
                        openList.insert(make_pair(
                            fNew, make_pair(i, j - 1)));
                        cellDetails[i][j - 1].f = fNew;
                        cellDetails[i][j - 1].g = gNew;
                        cellDetails[i][j - 1].h = hNew;
                        cellDetails[i][j - 1].parent_i = i;
                        cellDetails[i][j - 1].parent_j = j;
                    }
                }
            }
            // West Successor
            if (isValid(i, j + 1))
            {
                if (isDestination(i, j + 1))
                {
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                    cout << "Destination is found\n";
                    // tracePath();
                    foundDest = true;
                    break;
                }
                else if (closedList[i][j + 1] == false && isUnblocked(i, j + 1))
                {
                    gNew = cellDetails[i][j].g + 1.0;
                    hNew = calculateHValue(i, j + 1);
                    fNew = gNew + hNew;
                    if (cellDetails[i][j + 1].f > fNew)
                    {
                        openList.insert(make_pair(
                            fNew, make_pair(i, j + 1)));
                        cellDetails[i][j + 1].f = fNew;
                        cellDetails[i][j + 1].g = gNew;
                        cellDetails[i][j + 1].h = hNew;
                        cellDetails[i][j + 1].parent_i = i;
                        cellDetails[i][j + 1].parent_j = j;
                    }
                }
            }
        }
        if (foundDest == false) {
            cout << "Failed to find the Destination Cell\n";
        } else {
            tracePath();
        }
        return;
    }
};

int main()
{
    Game g;
    g.aStar();
    return 0;
}
