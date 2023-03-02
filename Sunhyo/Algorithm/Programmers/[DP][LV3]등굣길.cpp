#include <string>
#include <vector>
#include <queue>

using namespace std;

int puddle[102][102] = {0, };
int visitied[102][102] = {0, };
int dp[102][102] = {0, }; // 길 개수

int dy[2] = {0, 1};
int dx[2] = {1, 0};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    queue<pair<int, int>> q;
    
    for(int i=0; i<puddles.size(); i++)
        puddle[puddles[i][1]][puddles[i][0]] = 1;
    
    dp[1][1] = 1;
    q.push({1, 1});
    
    int curY, curX, newY, newX;
    
    while(!q.empty())
    {
        curY = q.front().first;
        curX = q.front().second; q.pop();
        
        if(curX == m && curY == n)
            break;
        
        for(int i=0; i<2; i++)
        {
            newY = curY + dy[i];
            newX = curX + dx[i];
            
            if(puddle[newY][newX])
                continue;
            
            if(newX < 1 || newX > m || newY < 1 || newY > n)
                continue;
            
            dp[newY][newX] += (dp[curY][curX] % 1000000007);
            
            if(!visitied[newY][newX])
            {
                visitied[newY][newX] = 1;
                q.push({newY, newX});
            }
        }
    }
    
    return dp[n][m] % 1000000007;
}