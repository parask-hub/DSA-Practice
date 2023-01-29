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
    node *root = new struct node();
    root->data = d;
    root->left = NULL;
    root->left = NULL;
    return root;
}

node *binary_tree()

{
    node *root;
    int num;
    cin >> num;
    if (num == -1)
        return NULL;
    root = create_node(num);
    root->left = binary_tree();
    root->right = binary_tree();
    return root;
}

void level_order(node *root) // line by line printing
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
}

// input 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1

void pre_order(node *root) // root , left , right
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(node *root) // left , right , root
{
    if (root == NULL)
        return;
    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}

void in_order(node *root) // left , root , right
{
    if (root == NULL)
        return;
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

int main()
{
    node *root = binary_tree();
    cout << "LEVEL ORDER TRAVERSAL" << endl;
    level_order(root);
    cout << endl;
    cout << "PRE ORDER TRAVERSAL" << endl;
    pre_order(root);
    cout << endl;
    cout << "POST ORDER TRAVERSAL" << endl;
    post_order(root);
    cout << endl;
    cout << "INORDER TRAVERSAL" << endl;
    in_order(root);
}