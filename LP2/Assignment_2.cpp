#include<bits/stdc++.h>
using namespace std;

void Board(char board[][7]){
    cout << endl << "----------------------------------"<< endl << endl;
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++) cout << board[i][j] << "\t";
        cout << endl << endl;
    }
}

string sort(map<string, int>& M){
    multimap<int, string> MM;
    for (auto& it : M)  MM.insert(pair<int, string>(it.second, it.first));
    for (auto& it : MM) return it.second;
    return "";
}

int helper(int maze[][7]){
    int xtemp=1, ytemp=1;
    int h[7][7] = {{-1, -1, -1, -1, -1, -1, -1}, 
                   {-1, 0, -1, 0, 0, 0, -1}, 
                   {-1, 0, 0, 0, -1, 0, -1}, 
                   {-1, -1, -1, -1, -1, 0, -1}, 
                   {-1, 0, 0, 0, 0, 0, -1}, 
                   {-1, 0, 0, 0, 0, 0, -1}, 
                   {-1, -1, -1, -1, -1, -1, -1}};
    char board[7][7] = {{'1', '1', '1', '1', '1', '1', '1'}, 
                        {'1', 'S', '1', '0', '0', '0', '1'}, 
                        {'1', '0', '0', '0', '1', '0', '1'}, 
                        {'1', '1', '1', '1', '1', '0', '1'}, 
                        {'1', '0', '0', '0', '0', '0', '1'}, 
                        {'1', '0', '0', '0', '0', 'E', '1'}, 
                        {'1', '1', '1', '1', '1', '1', '1'}};
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            if(h[i][j] != -1) h[i][j] = 10-i-j;
        }
    }
    Board(board);
    int Count = 0;
    while(true){
        if(xtemp == 5 && ytemp == 5)    break;
        int above, below, left, right;
        bool aboveFlag = false, belowFlag = false, leftFlag = false, rightFlag = false;
        if(h[xtemp][ytemp-1] != -1){ 
            above = Count + h[xtemp][ytemp]; 
            aboveFlag = true; 
        }
        if(h[xtemp][ytemp+1] != -1){ below = Count + h[xtemp][ytemp+1]; belowFlag = true; }
        if(h[xtemp-1][ytemp] != -1){ left = Count + h[xtemp-1][ytemp]; leftFlag = true; }
        if(h[xtemp+1][ytemp] != -1){ right = Count + h[xtemp+1][ytemp]; rightFlag = true; }
        map<string, int> dict;
        if(aboveFlag)   dict["above"] = above;
        if(belowFlag)   dict["below"] = below;
        if(leftFlag)    dict["left"] = left;
        if(rightFlag)   dict["right"] = right;
        if(dict.empty()){ Board(board); cout << "No way found..."; return Count;}
        string where = sort(dict);
        if(where == "above"){ Count++; h[xtemp][ytemp] = -1; board[xtemp][ytemp] = '<'; ytemp--; }
        else if(where == "below"){ Count++; h[xtemp][ytemp] = -1; board[xtemp][ytemp] = '>'; ytemp++; }
        else if(where == "left"){ Count++; h[xtemp][ytemp] = -1; board[xtemp][ytemp] = '^'; xtemp--; }
        else if(where == "right"){ Count++; h[xtemp][ytemp] = -1; board[xtemp][ytemp] = 'v'; xtemp++; }
    }
    Board(board);
    return Count;
}

int main(){
    int maze[7][7];
    int Steps = helper(maze);
    cout << "Number of steps taken = " << Steps;
    return 0;
}
