#include <iostream>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    int dp[K + 1][N + 1];
    for (int i = 1; i <= K; i++)
        dp[i][0] = 1;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= N; j++)
            dp[i][j] = i;
    }

    for (int i = 2; i <= K; i++)
    {
        for (int j = 1; j <= N; j++)
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000000;
    }

    cout << dp[K][N];
    return 0;
}