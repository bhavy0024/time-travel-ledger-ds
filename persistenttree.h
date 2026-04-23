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
