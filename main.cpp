#include <bits/stdc++.h>
using namespace std;
#define int long long
#include "persistenttree.h"
Node* transaction(Node* prev, int n, int from, int to, int amount)
{
    int balfrom = query(prev, 0, n - 1, from, from);
    int balto = query(prev, 0, n - 1, to, to);
    if (balfrom < amount)
    {
        cout << "Transaction failed (insufficient funds)\n";
        return prev;
    }
    Node* temp = update(prev, 0, n - 1, from, balfrom - amount);
    Node* newroot = update(temp, 0, n - 1, to, balto + amount);
    return newroot;
}
int32_t main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<Node*> versions;
    Node* root0 = build(arr, 0, n - 1);
    versions.push_back(root0);
    int q;
    cin >> q;
    while (q--)
    {
        int from, to, amount;
        cin >> from >> to >> amount;
        Node* new_root = transaction(versions.back(), n, from, to, amount);
        detect_fraud(versions.back(), new_root, n);
        versions.push_back(new_root);
    }
    // queries after all transactions
    int k;
    cin >> k; // number of queries
     while (k--)
    {
        int version, l, r;
        cin >> version >> l >> r;
        cout << query(versions[version], 0, n - 1, l, r) << "\n";
    }
    return 0;
}
