#include<iostream>

typedef class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() {
        left = NULL;
        right = NULL;
    }

    Node(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

}* NodePointer;

NodePointer createNode(int data) {
    return new Node(data);
}

NodePointer insertNode(NodePointer root, int data) { /// Pass root by reference(for updating root.)
    if(root == NULL) { /// base condition...
        root = createNode(data);
    }
    else if(data < root -> data){ /// recursive call
        root -> left = insertNode(root -> left, data);
    }
    else if(data > root -> data){ /// recursive call
        root -> right = insertNode(root -> right, data);
    }
    return root;
}

void inOrderTraversal(NodePointer root){
    if(root != NULL){
        inOrderTraversal(root -> left);
        std :: cout << root -> data << " ";
        inOrderTraversal(root -> right);
    }
}
void preOrderTraversel(NodePointer root){
    if(root != NULL){
        std :: cout << root -> data << " ";
        inOrderTraversal(root -> left);
        inOrderTraversal(root -> right);
    }
}
void PostOrderTraversel(NodePointer root){
    if(root != NULL){
        inOrderTraversal(root -> left);
        inOrderTraversal(root -> right);
        std :: cout << root -> data << " ";
    }
}
int main() {

    NodePointer root = NULL;

    root = insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 1);
    insertNode(root, 9);
    insertNode(root, 4);
    insertNode(root, 7);

    std :: cout << "In-order traversal of binary tree\t: ";
    inOrderTraversal(root);
    std :: cout << "\n";
    std :: cout << "Pre-Order traversal of binary tree\t: ";
    preOrderTraversel(root);
    std :: cout << "\n";
    std :: cout << "Post-Order traversal of binary tree\t: ";
    PostOrderTraversel(root);

    return 0;
}
