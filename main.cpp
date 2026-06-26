#include <bits/stdc++.h>
using namespace std;
#define int long long
#include "persistenttree.h"
vector<Node*> versions;
int32_t main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    Node* root0 = build(arr, 0, n - 1);
    versions.push_back(root0);  
    int q;
    cin >> q;
    while (q--)
    {
        string type;
        cin >> type;
        if (type == "txn")
        {
            int from, to;
            long long amount;
            cin >> from >> to >> amount;
            Node* new_root = transaction(versions.back(), n, from, to, amount);
            if (new_root != versions.back())
            {
                detectfraud(versions.back(), new_root, n);
                versions.push_back(new_root);
            }
        }
        else if (type == "query")
        {
            int version, l, r;
            cin >> version >> l >> r;
            if (version < 0 || version >= (int)versions.size())
            {
                cout << "Invalid version\n";
                continue;
            }
            cout << query(versions[version], 0, n - 1, l, r) << "\n";
        }
        else if (type == "status")
        {
            cout << "Total versions: " << versions.size() << "\n";
        }
    }
    return 0;
}
