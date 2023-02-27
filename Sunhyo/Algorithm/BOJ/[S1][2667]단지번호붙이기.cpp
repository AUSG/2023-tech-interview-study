#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int map[25][25];
int visited[25][25];
int N;
int number = 0;

void dfs(int y, int x)
{
    number++;

    int dy[4] = { 0, 0, 1, -1 };
    int dx[4] = { 1, -1, 0, 0 };

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

        if (!visited[ny][nx] && map[ny][nx])
        {
            visited[ny][nx] = 1;
            dfs(ny, nx);
        }
    }
}

int main()
{
    vector<int> count;
    int answer = 0;
    string s;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            map[i][j] = s[j] - '0';
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && map[i][j])
            {
                answer++;
                visited[i][j] = 1;
                dfs(i, j);
                count.push_back(number);
                number = 0;
            }
        }
    }

    cout << answer << '\n';
    sort(count.begin(), count.end());
    for (int i = 0; i < count.size() - 1; i++)
        cout << count[i] << '\n';
    cout << count[count.size() - 1];
}