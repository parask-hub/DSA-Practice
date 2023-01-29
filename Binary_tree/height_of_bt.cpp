#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *create_node(int d)
{
    node *root = new node();
    root->data = d;
    root->left = NULL;
    root->right = NULL;
    return root;
}

node *binary_tree()
{
    int n;
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }
    node *node = create_node(n);
    node->left = binary_tree();
    node->right = binary_tree();
    return node;
}

void display(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    display(root->left);
    display(root->right);
}

// Height of binary_tree

int height(node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

// Diameter Of Binary_tree

int diameter(node *root)
{
    if (root == NULL)
        return 0;

    int l = diameter(root->left);
    int r = diameter(root->right);

    int lr = height(root->left) + height(root->right) + 1;
    int ans = max(l, max(lr, r));
    return ans;
}

int main()
{
    node *root = binary_tree();
    display(root);
    cout << endl;
    cout << "Height Of Binary Tree : ";
    cout << height(root);
    cout << endl;
    cout << "Diameter Of Binary Tree : ";
    cout << diameter(root);
}