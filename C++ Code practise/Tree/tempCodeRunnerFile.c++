cout<<root->data<<" ";
    for(int i=0; i<root->children.size(); i++){
        printPreOrder(root->children[i]);
    }