#include <stdio.h>
using namespace std;

int arr[1'000'001] = {0, };

int main()
{
	int N;
	scanf_s("%d", &N);

	arr[1] = 0;

	for (int i = 2; i <= N; i++)
	{
		if (i % 3 == 0)
		{
			arr[i] = arr[i / 3] + 1;
		}
		
		if (i % 2 == 0)
		{
			if (arr[i])
			{
				arr[i] = (arr[i] > arr[i / 2] + 1 ? arr[i / 2] : arr[i]);
			}

			else
			{
				arr[i] = arr[i / 2] + 1;
			}
		}

		if (arr[i])
		{
			if (arr[i])
			{
				arr[i] = (arr[i] > arr[i-1] + 1 ? arr[i-1] : arr[i]);
			}

			else
			{
				arr[i] = arr[i-1] + 1;
			}
		}
	}

	printf("%d", arr[N]);

	return 0;
}