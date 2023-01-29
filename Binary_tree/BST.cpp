#include <iostream>
#include <queue>
using namespace std;

// INORDER TRAVERSAL OF BST IS SORTED

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

node *insert_in_bst(node *root, int d)
{
    if (root == NULL)
    {
        return create_node(d);
    }
    if (root->data > d)
    {
        root->left = insert_in_bst(root->left, d);
    }
    else
    {
        root->right = insert_in_bst(root->right, d);
    }
    return root;
}

void level_order(node *&root)
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
                q.push(temp->left);
            if (temp->right != NULL)

                q.push(temp->right);
        }
    }
}

void inorder(node *root) // left , root , right
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root) // root , left , right
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root) // left , right , root
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void take_input(node *&root)
{
    int d;
    cin >> d;
    while (d != -1)
    {
        root = insert_in_bst(root, d);
        cin >> d;
    }
}

// RECURSIVE
void search_in_bst(node *root, int t)
{
    if (root == NULL)
        cout << "Target Not Found" << endl;
    if (root->data == t)
        cout << "Target Data Found" << endl;
    if (root->data > t)
        search_in_bst(root->left, t);
    if (root->data < t)
        search_in_bst(root->right, t);
}

// ITERATIVE
void search_in_BT_I(node *root, int t)
{
    node *temp = root;
    while (temp != NULL)
    {
        if (temp->data == t)
        {
            cout << "Target Data Found" << endl;
            return;
        }
        if (temp->data > t)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    cout << " Target Data Not Found" << endl;
}

//  FIND MINIMUM ELEMENT

node *min_ele(node *root)
{
    node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
// FIND MAX ELEMENT

node *max_ele(node *root)
{
    node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

// Deletion in binary tree

node *delete_bt(node *root, int t)
{
    if (root == NULL)
        return NULL;

    if (root->data == t)
    {
        // IF node to be deleted is leaf node
        if (root->right == NULL and root->left == NULL)
        {
            delete root;
            return NULL;
        }

        // if node to be deleted has single child either left or right
        else if (root->left != NULL and root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->right != NULL and root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        // when the node to be deleted has two childrens
        else
        {
            int mini = min_ele(root->right)->data;
            root->data = mini;
            delete_bt(root->right, mini);
            return root;
        }
    }
    else if (root->data < t)
    {
        root->right = delete_bt(root->right, t);
        return root;
    }
    else
    {
        root->left = delete_bt(root->left, t);
        return root;
    }
}

int main()
{
    node *root = NULL;
    take_input(root);
    cout << "LEVEL ORDER: " << endl;
    level_order(root);
    cout << endl;
    cout << "INORDER: " << endl;
    inorder(root);
    cout << endl;

    cout << "PREORDER: " << endl;
    preorder(root);
    cout << endl;

    cout << "POSTORDER: " << endl;
    postorder(root);
    cout << endl;

    // search_in_bst(root, 10);
    // search_in_bst(root, 80);
    // search_in_bst(root, 20);

    // search_in_BT_I(root, 10);
    // search_in_BT_I(root, 80);
    // // search_in_BT_I(root, 20);

    // cout << "Min Element : " << min_ele(root)->data << endl;
    // cout << "Max Element : " << max_ele(root)->data << endl;

    root = delete_bt(root, 30);
    level_order(root);
}

// 10 8 21 7 27 5 4 3 -1
// 50 20 70 10 30 90 110 -1