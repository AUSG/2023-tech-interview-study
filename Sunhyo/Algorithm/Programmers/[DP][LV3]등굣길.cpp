#include <string>
#include <vector>
#include <queue>

using namespace std;

int table[102][102] = {0, };
int visitied[102][102] = {0, };

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<int> answers;
    queue<pair<pair<int, int>, int>> q; // 노드(y, x), 깊이
    int depth, curX, curY, newX, newY;
    
    for(int i=0; i<puddles.size(); i++)
        table[puddles[i][1]][puddles[i][0]] = 1;
    
    q.push({{1, 1}, 0});
    
    while(!q.empty())
    {
        curY = q.front().first.first;
        curX = q.front().first.second;
        depth = q.front().second; q.pop();

        for(int i=0; i<4; i++)
        {
            newY = curY + dy[i];
            newX = curX + dx[i];

            if(newY < 1 || newY > n || newX < 1 || newX > m)
                continue;

            if(visitied[newY][newX] || table[newY][newX])
                continue;

            if(newY == n && newX == m)
            {
                answers.push_back(depth+1);
                continue;
            }
            
            visitied[curY][curX] = 1;
            
            q.push({{newY, newX}, depth+1});
        }
    }
    
    answer = 1;
    int minDistance = answers[0];
    for(int i=1; i<answers.size(); i++)
    {
        if(minDistance < answers[i])
        {
            minDistance = answers[i];
            answer = 1;
        }
        else if(minDistance == answers[i])
            answer++;
    }
    
    return answer % 1000000007;
}
              