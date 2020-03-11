/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
public:
    vector<int> res;
    vector<int> postorder(Node *root)
    {
        dfs(root);
        return res;
    }
    void dfs(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        for (auto &&i : root->children)
        {
            dfs(i);
        }
        res.push_back(root->val);
    }
};
// @lc code=end
