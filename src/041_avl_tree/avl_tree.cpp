#include "avl_tree.hpp"

int AVLTree::getBalance(AVLNode* curr) {
    if (curr == nullptr) return 0;
    return curr->getLeftChildHeight() - curr->getRightChildHeight();
}

AVLTree::AVLNode* AVLTree::leftRotate(AVLNode* node) {
    AVLNode* newRoot = node->right;
    AVLNode* oldLeft = newRoot->left;
    node->right = oldLeft;
    newRoot->left = node;
    node->updateHeight();
    newRoot->updateHeight();
    return newRoot;
}

AVLTree::AVLNode* AVLTree::rightRotate(AVLNode* node) {
    AVLNode* newRoot = node->left;
    AVLNode* oldRight = newRoot->right;
    node->left = oldRight;
    newRoot->right = node;
    node->updateHeight();
    newRoot->updateHeight();
    return newRoot;
}

AVLTree::AVLNode* AVLTree::leftRightRotate(AVLNode* node) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
}

AVLTree::AVLNode* AVLTree::rightLeftRotate(AVLNode* node) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
}

void AVLTree::insertNode(int val) {
    root = insertHelper(root, val);
}

void AVLTree::deleteNode(int val) {
    root = deleteHelper(root, val);
}

AVLTree::AVLNode* AVLTree::insertHelper(AVLNode* curr, int val) {
    if (curr == nullptr) {
        curr = new AVLNode(val);
        return curr;
    }
    if (val > curr->value) {
        curr->right = insertHelper(curr->right, val);
    }
    else if (val < curr->value) {
        curr->left = insertHelper(curr->left, val);
    }
    else if (val == curr->value) {
        return curr;
    }
    curr->updateHeight();
    int balance = getBalance(curr);
    // l > r
    if (balance > 1) {
        if (getBalance(curr->left) >= 0) {
            return rightRotate(curr);
        }
        else {
            return leftRightRotate(curr);
        }
    }
    // l < r
    else if (balance < -1) {
        if (getBalance(curr->right) <= 0) {
            return leftRotate(curr);
        }
        else {
            return rightLeftRotate(curr);
        }
    }
    return curr;
}

AVLTree::AVLNode* AVLTree::findMin(AVLNode* curr) {
    if (curr == nullptr || curr->left == nullptr) return curr;
    while (curr != nullptr && curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}

AVLTree::AVLNode* AVLTree::deleteHelper(AVLNode* curr, int val) {
    if (curr == nullptr) {
        return curr;
    }
    if (val == curr->value) {
        // has one or less child
        if (curr->left == nullptr || curr->right == nullptr) {
            AVLNode* temp = (curr->left != nullptr) ? curr->left : curr->right;
            delete curr;
            return temp;
        }
        // has both children
        else {
            AVLNode* temp = findMin(curr->right);
            // do not delete curr
            // assign val not node
            curr->value = temp->value;
            curr->right = deleteHelper(curr->right, temp->value);
        }
    }
    else if (val > curr->value) {
        curr->right = deleteHelper(curr->right, val);
    }
    else if (val < curr->value) {
        curr->left = deleteHelper(curr->left, val);
    }
    curr->updateHeight();
    int balance = getBalance(curr);
    if (balance > 1) {
        if (getBalance(curr->left) >= 0) {
            return rightRotate(curr);
        }
        else{
            return leftRightRotate(curr);
        }
    }
    else if (balance < -1) {
        if (getBalance(curr->right) <= 0) {
            return leftRotate(curr);
        }
        else {
            return rightLeftRotate(curr);
        }
    }
    return curr;
}

void AVLTree::deleteTree(AVLNode* root) {
    if (root == nullptr) return;
    AVLNode* l = root->left;
    AVLNode* r = root->right;
    deleteTree(l);
    deleteTree(r);
    delete root;
}