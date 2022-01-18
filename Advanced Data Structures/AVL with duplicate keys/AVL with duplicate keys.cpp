// AVL with duplicate keys

#include <iostream>

class TreeNode
{
public:
    int key;
    int height;
    int balance;
    int count;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : key(0), height(0), balance(0), count(1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : key(x), height(0), balance(0), count(1), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : key(x), height(0), balance(0), count(1), left(left), right(right) {}
};

class AVLTree
{
public:
    AVLTree() {}

    TreeNode* insertNode(TreeNode* node, int key)
    {
        // Perform normal BST insertion
        if (node == NULL)
            return(new TreeNode(key));

        // If key already exists, increment count and return
        if (key == node->key)
        {
            (node->count)++;
            return node;
        }

        if (key < node->key)
            node->left = insertNode(node->left, key);
        else if (key > node->key)
            node->right = insertNode(node->right, key);

        node = getRotation(node);
        return node;
    }

    TreeNode* removeNode(TreeNode* root, int key)
    {
        if (root == nullptr)
            return root;

        if (key < root->key)
            root->left = removeNode(root->left, key);
        else if (key > root->key)
            root->right = removeNode(root->right, key);
        else
        {
            // If key is present more than once, simply decrement count and return
            if (root->count > 1) 
            {
                (root->count)--;
                return root;
            }

            if (root->left == nullptr || root->right == nullptr)
            {
                TreeNode* temp = root->left ? root->left : root->right;
                if (temp == nullptr)     // No child case
                {
                    temp = root;
                    root = nullptr;
                }
                else     // One child case
                    *root = *temp;      // Copy the contents of the non-empty child 
                delete temp;
            }
            else   // Node with two children: Get the inorder successor (smallest in the right subtree)
            {
                TreeNode* minNode = getMinNode(root->right);
                root->key = minNode->key;
                root->count = minNode->count;
                minNode->count = 1;
                root->right = removeNode(root->right, minNode->key);
            }
        }

        root = getRotation(root);
        return root;
    }

    void preOrder(TreeNode* root)
    {
        if (root != NULL)
        {
            std::cout << root->key << "(" << root->count << ")" << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

private:
    void updateHeightAndBalance(TreeNode* node)
    {
        int lh = -1;
        int rh = -1;
        if (node->left != nullptr)
            lh = node->left->height;
        if (node->right != nullptr)
            rh = node->right->height;

        node->height = std::max(lh, rh) + 1;
        node->balance = lh - rh;
    }

    TreeNode* rightRotate(TreeNode* A)
    {
        TreeNode* B = A->left;
        TreeNode* rightSubtreeOfB = B->right;

        B->right = A;
        A->left = rightSubtreeOfB;

        updateHeightAndBalance(A);
        updateHeightAndBalance(B);
        return B;
    }

    TreeNode* leftRotate(TreeNode* A)
    {
        TreeNode* B = A->right;
        TreeNode* leftSubtreeOfB = B->left;

        B->left = A;
        A->right = leftSubtreeOfB;

        updateHeightAndBalance(A);
        updateHeightAndBalance(B);
        return B;
    }

    TreeNode* getRotation(TreeNode* node)
    {
        updateHeightAndBalance(node);

        if (node->balance == 2)
        {
            if (node->left->balance == 1)   // LL
            {
                return rightRotate(node);
            }
            else    // LR
            {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        else if (node->balance == -2)
        {
            if (node->right->balance == -1)   // RR
            {
                return leftRotate(node);
            }
            else    // RL
            {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node;
    }

    TreeNode* getMinNode(TreeNode* node)
    {
        TreeNode* curr = node;
        while (curr->left != nullptr)
            curr = curr->left;
        return curr;
    }
};


int main()
{
    TreeNode* root = NULL;
    AVLTree* tree = new AVLTree();
    root = tree->insertNode(root, 9);
    root = tree->insertNode(root, 5);
    root = tree->insertNode(root, 10);
    root = tree->insertNode(root, 5);
    root = tree->insertNode(root, 9);
    root = tree->insertNode(root, 7);
    root = tree->insertNode(root, 17);

    std::cout << "Preorder traversal of the constructed AVL tree is \n";
    tree->preOrder(root);

    root = tree->removeNode(root, 9);

    std::cout << "\nPreorder traversal after deletion of 9 \n";
    tree->preOrder(root);

    return 0;
}

