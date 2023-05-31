    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
        {
            return nullptr;
        }
        auto temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }