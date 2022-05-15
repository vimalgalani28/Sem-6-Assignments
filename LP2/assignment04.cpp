#include <bits/stdc++.h>
using namespace std;

class Solution {
    void solve(
        vector<vector <string>> &ans, 
        vector <string> &board, 
        vector<int>&row, 
        vector<int>&upperDiag, 
        vector<int>&lowerDiag, 
        int col, 
        int n
    ) {
        if(col>=n) {
            ans.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(row[i] == 0 && upperDiag[n-1+col-i] == 0 && lowerDiag[col+i] == 0) {
                board[i][col] = 'Q';
                row[i] = 1;
                lowerDiag[i+col] = 1; 
                upperDiag[n-1+col-i] = 1;
                solve(ans, board, row, upperDiag, lowerDiag, col + 1, n);
                board[i][col] = '.';
                row[i] = 0;
                lowerDiag[i+col] = 0; 
                upperDiag[n-1+col-i] = 0;   
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector <string>> ans;
        vector <string> board;
        vector<int>row(n, 0);
        vector<int>upperDiag(2*n-1, 0);
        vector<int>lowerDiag(2*n-1, 0);
        string s(n, '.');
        for(int i = 0; i < n; i++) {
            board.push_back(s);
        }
        solve(ans, board, row, upperDiag, lowerDiag, 0, n);
        return ans;
    }
};

int main() {
    Solution s;
    int n;
    vector <vector<string>> boards;
    cin>>n;
    boards = s.solveNQueens(n);
    for(int i = 0; i < boards.size(); i++) {
        cout<<"Board "<<i+1<<":\n";
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cout<<boards[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<"\n\n\n";
    }
    return 0;
}