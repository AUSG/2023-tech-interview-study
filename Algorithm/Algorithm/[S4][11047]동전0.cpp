#include <iostream>

using namespace std;

int main()
{
    int N, K, result = 0;
    cin >> N >> K;

    int coin[N];

    for (int i = 0; i < N; i++)
        cin >> coin[i];

    for (int i = N - 1; i >= 0; i--)
    {
        while (coin[i] <= K)
        {
            K -= coin[i];
            result++;
        }

    }

    cout << result;

    return 0;
}