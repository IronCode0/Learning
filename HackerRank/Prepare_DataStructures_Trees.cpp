// Tree: Preorder Traversal
void preOrder(Node *root) {
    if (root == NULL) return;
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}
// Tree: Postorder Traversal
void postOrder(Node *root) {
    if (root == NULL) return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}
// Tree: Inorder Traversal
void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root -> left);
    cout << root -> data << " ";  
    inOrder(root -> right);
}
// Tree: Height of a Binary Tree
int height(Node* root) {
    if (root == nullptr) return -1;
    return max( height(root -> left)  + 1, height(root -> right) + 1 );
}
// Tree : Top View
void topView(Node * root) {
    queue<pair<int,Node*>> q;
    q.push(make_pair(0,root));
    map<int,Node*> output;
    for(auto i=q.front();!q.empty();q.pop(),i=q.front()){
        if(!i.second) continue;
        output.insert(i);
        q.push(make_pair(i.first+1,i.second->right));
        q.push(make_pair(i.first-1,i.second->left));
    }
    for(auto i : output) cout<<i.second->data<<" ";
}
// Tree: Level Order Traversal
void levelOrder(Node * root) {
    queue<Node*> q;
    if (root == NULL) return;
    q.push(root);
    while (!q.empty()) {
        Node *n = q.front();
        q.pop();

        cout << n->data << " ";

        if (n->left) q.push(n -> left);
        if (n->right) q.push(n -> right);
    }

}
// Binary Search Tree : Insertion
Node * insert(Node * root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);
    return root;
}
// 
Node *lca(Node *root, int v1,int v2) {
	if(root == nullptr) return nullptr;
    int data = root->data;
    if(v1 < data && v2 < data) return lca(root->left, v1, v2);
    if(v1 > data && v2 > data) return lca(root->right, v1, v2);
    return root;
}
