#include <iostream>

using namespace std;

struct Node
{
    char data;
    char left;
    char right;
};

Node node[30];

void preorder(int n)
{
    cout << node[n].data;
    if (node[n].left != '.') preorder(node[n].left - 'A');
    if (node[n].right != '.') preorder(node[n].right - 'A');
}

void inorder(int n)
{
    if (node[n].left != '.') inorder(node[n].left - 'A');
    cout << node[n].data;
    if (node[n].right != '.') inorder(node[n].right - 'A');
}

void postorder(int n)
{
    if (node[n].left != '.') postorder(node[n].left - 'A');
    if (node[n].right != '.') postorder(node[n].right - 'A');
    cout << node[n].data;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        char root, l, r;
        cin >> root >> l >> r;

        node[root - 'A'].data = root;
        node[root - 'A'].left = l;
        node[root - 'A'].right = r;
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';

    return 0;
}