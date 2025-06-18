#ifndef BST_H
#define BST_H

// Node untuk Binary Search Tree
typedef struct TreeNode {
    char name[20];
    double value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(const char* name, double value);
TreeNode* insertNode(TreeNode* root, const char* name, double value);
TreeNode* searchNode(TreeNode* root, const char* name);
void inorderTraversal(TreeNode* root); // Untuk menampilkan semua konstanta terurut

#endif