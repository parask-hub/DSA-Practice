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
        return NULL;
    node *root = create_node(n);
    root->left = binary_tree();
    root->right = binary_tree();
    return root;
}

void level_order(node *root)
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
                q.push(NULL);
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

void left_view(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            node *temp = q.front();
            q.pop();
            if (i == 1)
                cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

void right_view(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            node *temp = q.front();
            q.pop();
            if (i == n)
                cout << temp->data << " ";
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

int main()
{
    node *root = binary_tree();
    level_order(root);
    left_view(root);
    cout << endl;
    right_view(root);
}