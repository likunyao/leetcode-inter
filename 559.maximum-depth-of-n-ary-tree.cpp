/*
 * @lc app=leetcode id=559 lang=cpp
 *
 * [559] Maximum Depth of N-ary Tree
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
    int maxDepth(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        int max = 0;
        for (auto &&i : root->children)
        {
            int d = maxDepth(i);
            max = max < d ? d : max;
        }
        return max + 1;
    }
};
// @lc code=end
