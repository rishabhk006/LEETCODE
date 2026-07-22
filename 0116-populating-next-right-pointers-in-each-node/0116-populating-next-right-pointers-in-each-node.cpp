class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        Node* leftMost = root;

        while (leftMost->left) {
            Node* head = leftMost;

            while (head) {
                head->left->next = head->right;

                if (head->next)
                    head->right->next = head->next->left;

                head = head->next;
            }

            leftMost = leftMost->left;
        }

        return root;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna