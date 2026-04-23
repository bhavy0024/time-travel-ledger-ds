#include <bits/stdc++.h>
using namespace std;
#define int long long
#include "persistenttree.h"
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
        if (new_root != versions.back())
        {
            detectfraud(versions.back(), new_root, n);
            versions.push_back(new_root);
        }
    }
    // queries after all transactions
    int k;
    cin >> k; // number of queries
     while (k--)
    {
        int version, l, r;
        cin >> version >> l >> r;
        if (version < 0 || version >= versions.size())
        {
            cout << "Invalid version\n";
            continue;
        }
        cout << query(versions[version], 0, n - 1, l, r) << "\n";
    }
    return 0;
}
