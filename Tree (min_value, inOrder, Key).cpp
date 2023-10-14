#include<iostream>
using namespace std;

typedef class BST {
public:
    int data;
    BST* right;
    BST* left;

    BST(int value) {
        this -> data = value;
        right = NULL;
        left = NULL;
    }
}* BSTP;

BSTP createNode(int value) {
    return new BST(value);
}

BSTP insertNode(BSTP root, int value) {
    if(root == NULL) {
        root = createNode(value);
    } else if(value < root -> data) {
        root -> left = insertNode(root -> left, value);
    } else if(value > root -> data) {
        root -> right = insertNode(root -> right, value);
    }
    return root;
}


BSTP findMinValueNode(BSTP root) {
    BSTP min = root;

    while(min && min -> left != NULL) {
        min = min -> left;
    }
    return min;
}


BSTP delelteNode(BSTP root, int value) {
    if(root == NULL) {  // Empty tree or node not found.
        return root;
    } else if(value < root -> data) {
        // If the node to be deleted is in the left subtree.
        root -> left = delelteNode(root -> left, value);
    } else if(value > root -> data) {
        // If the node to be deleted is in the right subtree.
        root -> right = delelteNode(root -> right, value);
    } else {
        // Node to be deleted found

        // Node with only one child or no child

        if(root -> left == NULL) {
            BSTP temp = root -> right;
            delete root;
            return temp;
        } else if(root -> right == NULL) {
            BSTP temp = root -> left;
            delete root;
            return temp;
        }
        BSTP temp = findMinValueNode(root -> right);
        root -> data = temp -> data;
        root -> right = delelteNode(root -> right, temp -> data);
    }
    return root;
}

int Searching(BSTP root, int key, int& index) {
    // If the current node is NULL, key not found, return -1
    if (root == NULL) {
        return -1;
    }

    // Recursively search in the left subtree
    int leftResult = Searching(root -> left, key, index);

    // If the key is found in the left subtree, return the result
    if(leftResult != -1){
        return leftResult;  // Key found in the left subtree
    }

    index ++;  // Increment the index for the current node (in-order traversal)

    // Check if the current node's data is the key
    if (key == root->data) {
        return index - 1;  // Key found in the current node.
    }
    return Searching(root -> right, key, index);  // Recursively search in the right subtree
}


void in_Order(BSTP root) {
    if(root != NULL) {
        in_Order (root -> left);
        cout << root -> data << " ";
        in_Order (root -> right);
    }
}


int main() {

    BSTP root = NULL;
    root = insertNode(root, 17);

    insertNode(root, 15);
    insertNode(root, 5);
    insertNode(root, 25);
    insertNode(root, 12);
    insertNode(root, 14);
    insertNode(root, 7);

    BSTP minValueNode = findMinValueNode(root);
    if (minValueNode != NULL) {
        cout << "Minimum value in the binary tree\t\t: " << minValueNode->data << "\n";
    } else {
        cout << "The binary tree is empty.\n";
    }

    /*BSTP minValue = findMinValueNode(root);
    cout << "The minimum value of the tree is: " << minValue -> data << endl << "\n";*/

    cout << "In-order traversal of binary tree\t\t: ";
    in_Order(root);
    cout << "\n";

    delelteNode(root, 7);
    cout << "In-order traversal of binary tree\t\t: ";
    in_Order(root);
    cout << "\n";

    int key = 25;
    int index = 0;
    int searchIndex = Searching(root, key, index);
    index = index - 1; // start with 0 number index.
    if(searchIndex != -1){
        cout << "Searching key " << key << " found at the position of\t: " << index << endl;
    }
    else{
        cout << "Searching key not found." << endl;
    }

    return 0;
}
