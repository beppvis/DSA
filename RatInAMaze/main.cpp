#include <cstdio>
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
            if (x_c == m||y_c ==n)
            {
                printf("Found An Path");
                // TODO: print the path;
                return true;
            }
            for(int i = 0 ; i < 8 ; i++){
                int x = x_c + dir[i][0];
                int y = y_c + dir[i][1];
                if(isWall(maze, currPos, m, n)||v[x][y]==1)
                    continue;
                else{
                    v[x][y] = 1;
                    s.push({x,y,i});
                    path.push_back({x,y});
                }
            }
        }
        return false;
    }
    vvi readMaze(){
        int m,n;
        scanf("%d %d",&m,&n);
        vvi maze;
        for(int i = 0;i<m;i++){
            vector<int> row;
            for(int j = 0;i<n;i++){
                char in;
                scanf("%c ",&in);
                printf("character recieved  is : %c\n",in);
                switch (in) {
                   case ' ':
                        row.push_back(0);
                        break;
                    case '#':
                        row.push_back(1);
                        break;
                    deafult:
                        break;
                }
            }
            maze.push_back(row);
        }
        return maze;
    }
    bool isWall(vvi maze,vector<int> pos,int m,int n){
        // check if out of bounds
        if (pos[0] == -1 | pos[0] == n)
            return true;
        if (pos[1] == -1 | pos[1] == m)
            return true;
        // wall
        if (maze[pos[0]][pos[1]])
            return true;
        return false;
    }
};


int main(void){

    RatInMaze ratInMaze;
    vvi maze = ratInMaze.readMaze();

}



