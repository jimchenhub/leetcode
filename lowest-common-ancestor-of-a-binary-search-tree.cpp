/**
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> list_p, list_q;
        TreeNode * temp = root;
        while (temp != NULL) {
            list_p.push_back(temp);
            if (temp != p) {
                if (temp->val > p->val) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            } else {
                break;
            }
        }
        temp = root;
        while (temp != NULL) {
            list_q.push_back(temp);
            if (temp != q) {
                if (temp->val > q->val) {
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            } else {
                break;
            }
        }

        TreeNode * result = NULL;
        for (vector<TreeNode*>::iterator temp = list_p.begin(); temp != list_p.end(); temp++) {
            for (vector<TreeNode*>::iterator t = list_q.begin(); t != list_q.end(); t++) {
                if (*temp == *t) {
                    result = *temp;
                }
            }
        }

        return result;
    }


};