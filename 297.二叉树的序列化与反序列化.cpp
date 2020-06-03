/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// #include <string>
// #include <sstream>
// using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream s;
        se(root, s);
        return s.str();
    }

    void se(TreeNode *root, ostringstream &out)
    {
        if (root == nullptr)
        {
            out << "# ";
            return;
        }
        out << root->val << " ";
        se(root->left, out);
        se(root->right, out);
        return;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return de(in);
    }
    TreeNode *de(istringstream &in)
    {
        TreeNode *res;
        string tmp;
        in >> tmp;
        if (tmp == "#")
        {
            return nullptr;
        }
        else
        {
            res = new TreeNode(stoi(tmp));
            res->left = de(in);
            res->right = de(in);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
