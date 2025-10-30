#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;;

typedef vector<vector<int>> vvi;


class RatInMaze{
public:
    bool ratItr(vvi maze,int m,int n,vvi dir,vvi v,stack<vector<int>> s){
        int x = 0,y = 0;
        s.push({0,0,0});
        vvi path;
        while (!s.empty()) {
            vector<int> currPos = s.top();
            s.pop();
            path.push_back(currPos);
            int x_c=currPos[0],y_c=currPos[1],d_c=currPos[2];
            if (x_c == m-1||y_c ==n-1)
            {
                printf("Found An Path");
                // TODO: print the path;
                return true;
            }
            for(int i = 0 ; i < 8 ; i++){
                int x = x_c + dir[i][0];
                int y = y_c + dir[i][1];
                vector<int> pos = {x,y};
                if(isWall(maze, pos, m, n)||v[x][y]==1)
                    continue;
                else{

                printf("x : %d,y:%d\n",x,y);
                    v[x][y] = 1;
                    s.push({x,y,i});
                    path.push_back({x,y});
                }

            }
        }
        return false;
    }
    vvi readMaze(int m , int n){
        vvi maze;
        for(int i = 0;i<m;i++){
            vector<int> row;
            for(int j = 0;j<n;j++){
                char in;
                scanf("%[\n]",&in);
                switch (in) {
                   case '0':
                        row.push_back(0);
                        break;
                    case '#':
                        row.push_back(1);
                        break;
                    deafult:
                        break;
                }
            }
            fflush(stdin);
            maze.push_back(row);
        }
        return maze;
    }
    bool isWall(vvi maze,vector<int> pos,int m,int n){
        // check if out of bounds
        if (pos[0] == -1 || pos[0] == n-1)
            return true;
        if (pos[1] == -1 || pos[1] == m-1)
            return true;
        // wall
        if (maze[pos[0]][pos[1]])
            return true;
        return false;
    }
};


int main(void){

    RatInMaze ratInMaze;
    int m,n;
    scanf("%d %d",&m,&n);
    vvi maze = ratInMaze.readMaze(m,n);
    vvi visited=maze;
    vvi dir = {
        {-1,0},
        {-1,1},
        {-1,-1},
        {0,1},
        {0,-1},
        {1,0},
        {1,-1},
        {1,1},
    };
    stack<vector<int>>s;
    ratInMaze.ratItr(maze, m, n, dir, visited, s);

}



