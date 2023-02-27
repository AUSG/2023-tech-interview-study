#include <vector> 
#include <unordered_set> 
using namespace std;

int get_Ns(int N, int idx) {
    // NN(idx==1), NNN(idx==2), NNNN(idx==3)...�� ���� ���¸���� �Լ�
    int result = N;
    for (int i = 1; i <= idx; i++) {
        result = result * 10 + N;
    }
    return result;
}

int solution(int N, int number) {
    if (N == number) return 1;  // N�� number�� ���ٸ�, N�� �ѹ� ����ؼ� number�� ���� �� ����

    vector< unordered_set<int> > DP(8);
    //DP�� ������ �� -> DP[i] : i���� N���� ���� �� �ִ� ���ڵ� (set)

    DP[0].insert(N); // �Ѱ��� N���� ���� �� �ִ� ���� N����

    for (int k = 1; k < 8; k++) {

        // DP[k]�� NNN...(k+1��ŭ �ݺ�)�� ���� ���� ����
        DP[k].insert(get_Ns(N, k));

        // DP[k]�� ��Ģ ������ ������� ����
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i + j + 1 != k) continue;
                // i+j+1 == k �϶�
                for (int a : DP[i]) {
                    for (int b : DP[j]) {
                        DP[k].insert(a + b);
                        // �˻簡 �ʿ��� �����

                        // (1) ���� �����ϸ� �ȵ�
                        if (a - b > 0)
                            DP[k].insert(a - b);

                        DP[k].insert(a * b);

                        // (2) 0 �����ϸ� �ȵ�
                        if (a / b > 0) DP[k].insert(a / b);
                    }
                }
            }
        }

        if (DP[k].find(number) != DP[k].end()) //DP set�� number�� �ش��ϴ� ���� ������ k+1�� ��ȯ
            return k + 1;
    }
    return -1;
}