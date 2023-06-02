#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int getCurrentIndex(vector<int> &inorder, int strt, int fini, int val)
{
    int i;
    for (int i = strt; i <= fini; i++)
    {
        if (inorder[i] == val)
        {
            return i;
        }
    }
    return -1;
}

TreeNode *buildTreeNow(vector<int> &preorder, vector<int> &inorder, int strt, int fini)
{
    static int index = 0;

    if (strt > fini)
    {
        return nullptr;
    }

    TreeNode *theNode = new TreeNode(preorder[index++]);

    if (strt == fini)
    {
        return theNode;
    }

    int cIndex = getCurrentIndex(inorder, strt, fini, theNode->val);
    if (cIndex == -1)
    {
        return theNode;
    }
    theNode->left = buildTreeNow(preorder, inorder, strt, cIndex - 1);
    theNode->right = buildTreeNow(preorder, inorder, cIndex + 1, fini);

    return theNode;
}

string toString(TreeNode *root)
{
    if (root == nullptr)
    {
        return "";
    }

    return toString(root->left) + to_string(root->val) + toString(root->right);
}

int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = buildTreeNow(preorder, inorder, 0, preorder.size() - 1);

    cout << toString(root);
    return 0;
}