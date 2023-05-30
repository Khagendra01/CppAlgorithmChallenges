    string trvarse(TreeNode* a)
    {
        if( a == nullptr){
            return "";
        }
        return "l" + trvarse(a->left) + to_string(a->val) + trvarse(a->right) + "r"; 
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return (trvarse(p) == trvarse(q));
    }