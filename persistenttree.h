#ifndef PERSISTENT_TREE_H
#define PERSISTENT_TREE_H
#include <bits/stdc++.h>
using namespace std;
struct Node {
    long long val;
    Node* left;
    Node* right;
    Node(long long v) : val(v), left(NULL), right(NULL) {}
};
Node* build(vector<long long> &arr, int l, int r)
{
    if (l == r) return new Node(arr[l]);
    int mid = (l + r) / 2;
    Node* left = build(arr, l, mid);
    Node* right = build(arr, mid + 1, r);
    Node* root = new Node(left->val + right->val);
    root->left = left;
    root->right = right;
    return root;
}
Node* update(Node* prev, int l, int r, int idx, long long value)
{
    if (l == r) return new Node(value);
    int mid = (l + r) / 2;
    Node* root = new Node(0);
    if (idx <= mid)
    {
        root->left = update(prev->left, l, mid, idx, value);
        root->right = prev->right;
    }
    else
    {
        root->left = prev->left;
        root->right = update(prev->right, mid + 1, r, idx, value);
    }
    root->val = root->left->val + root->right->val;
    return root;
}
long long query(Node* root, int l, int r, int ql, int qr)
{
    if (!root || qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return root->val;
    int mid = (l + r) / 2;
    return query(root->left, l, mid, ql, qr) +
           query(root->right, mid + 1, r, ql, qr);
}
Node* transaction(Node* prev, int n, int from, int to, long long amount)
{
    if (from < 0 || from >= n || to < 0 || to >= n)
    {
        cout << "Invalid accounts\n";
        return prev;
    }
    long long bf = query(prev, 0, n - 1, from, from);
    long long bt = query(prev, 0, n - 1, to, to);
    if (bf < amount)
    {
        cout << "Transaction failed\n";
        return prev;
    }
    Node* t1 = update(prev, 0, n - 1, from, bf - amount);
    Node* t2 = update(t1, 0, n - 1, to, bt + amount);
    return t2;
}
bool detectfraud(Node* prev, Node* curr, int n)
{
    if (n == 0) return false;
    vector<long long> oldVal(n), newVal(n);
    long long sumOld = 0;
    for (int i = 0; i < n; i++)
    {
        oldVal[i] = query(prev, 0, n - 1, i, i);
        newVal[i] = query(curr, 0, n - 1, i, i);
        sumOld += oldVal[i];
    }
    long double meanOld = sumOld / (long double)n;
    long double var = 0;
    for (int i = 0; i < n; i++)
    {
        long double diff = newVal[i] - meanOld;
        var += diff * diff;
    }
    long double stddev = sqrt(var / n);
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        long long diff = llabs(newVal[i] - oldVal[i]);
        if (diff > 2000)
        {
            cout << "Fraud alert (spike) at account " << i << "\n";
            flag = true;
        }
        if (oldVal[i] != 0 && (diff * 100.0 / oldVal[i]) > 80)
        {
            cout << "Fraud alert (percentage) at account " << i << "\n";
            flag = true;
        }
        if (stddev > 0)
        {
            long double z = (newVal[i] - meanOld) / stddev;
            if (fabsl(z) > 3)
            {
                cout << "Fraud alert (z-score) at account " << i << "\n";
                flag = true;
            }
        }
    }
    return flag;
}
#endif
