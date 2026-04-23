struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};
Node* build(vector<int> &arr, int l, int r)
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
Node* update(Node* prev, int l, int r, int idx, int value)
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
int query(Node* root, int l, int r, int ql, int qr)
{
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return root->val;
    int mid = (l + r) / 2;
    return query(root->left, l, mid, ql, qr) + query(root->right, mid + 1, r, ql, qr);
}
