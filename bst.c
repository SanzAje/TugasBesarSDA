#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

// Membuat node baru untuk tree
TreeNode* createNode(const char* name, double value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    strncpy(newNode->name, name, 19);
    newNode->name[19] = '\0';
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Memasukkan node baru ke dalam BST (secara rekursif)
TreeNode* insertNode(TreeNode* root, const char* name, double value) {
    if (root == NULL) {
        return createNode(name, value);
    }
    // Bandingkan nama untuk menentukan posisi (kiri atau kanan)
    if (strcmp(name, root->name) < 0) {
        root->left = insertNode(root->left, name, value);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertNode(root->right, name, value);
    }
    return root;
}

// Mencari node berdasarkan nama (secara rekursif)
TreeNode* searchNode(TreeNode* root, const char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return searchNode(root->left, name);
    }
    return searchNode(root->right, name);
}

// Menampilkan tree secara In-order (menghasilkan urutan abjad)
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("  - %-10s = %lf\n", root->name, root->value);
        inorderTraversal(root->right);
    }
}