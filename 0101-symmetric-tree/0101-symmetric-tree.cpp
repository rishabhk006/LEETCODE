class Solution {
public:
    bool check(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        if (!a || !b) return false;
        if (a->val != b->val) return false;

        return check(a->left, b->right) &&
               check(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna