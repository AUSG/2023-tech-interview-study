#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

using namespace std;

int A[51][51];
int B[51][51];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	// Matrix A
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			scanf("%1d", &A[n][m]);
		}
	}

	// Matrix B
	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			scanf("%1d", &B[n][m]);
		}
	}

	int ans = 0;
	for (int n = 0; n < N - 2; n++)
	{
		for (int m = 0; m < M - 2; m++)
		{
			if (A[n][m] != B[n][m])
			{
				for (int k = n; k <= n + 2; k++)
				{
					for (int l = m; l <= m + 2; l++)
					{
						A[k][l] = 1 - A[k][l];
					}
				}

				ans += 1;
			}

			else continue;
		}
	}

	for (int n = 0; n < N; n++)
	{
		for (int m = 0; m < M; m++)
		{
			if (A[n][m] != B[n][m])
			{
				printf("-1\n");

				return 0;
			}
		}
	}

	printf("%d\n", ans);
	
	return 0;
}