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
    cout << "Ledger System Started\n";
    return 0;
}
