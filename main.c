#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int data;
    struct tagNode* left;
    struct tagNode* right;
}Node;

Node* AddItemToTree(Node* root, int dataToAdd);

Node* AddItemToTree(Node* root, int dataToAdd)
{
    if (NULL == root) {
        Node* pNewNode;
        pNewNode = (Node*) malloc(sizeof(Node));
        if (NULL == pNewNode) {
            printf("AddItemToTree - Can NOT allocate memory\n");
            exit(EXIT_FAILURE);
        }
        pNewNode->data = dataToAdd;
        pNewNode->left = NULL;
        pNewNode->right = NULL;

        return pNewNode;
    } else {
        if (root->data < dataToAdd)
            root->right = AddItemToTree(root->right, dataToAdd);// GO RIGHT!
        else
            root->left = AddItemToTree(root->left, dataToAdd);// GO LEFT!
        return root;
    }
}

void PrintTreeVLR(Node* root)
{

    if (NULL == root)
        return;
    printf("Data : %d\n", root->data);
    PrintTreeVLR(root->left);
    PrintTreeVLR(root->right);
}
void PrintTreeLVR(Node* root)
{
    if (NULL == root)
        return;
    PrintTreeLVR(root->left);
    printf("Data : %d\n", root->data);
    PrintTreeLVR(root->right);
}
void PrintTreeRVL(Node* root)
{
    if (NULL == root)
        return;
    PrintTreeRVL(root->right);
    printf("Data : %d\n", root->data);
    PrintTreeRVL(root->left);
}
void PrintTreeVRL(Node* root)
{
    if (NULL == root)
        return;
    printf("Data : %d\n", root->data);
    PrintTreeVRL(root->right);
    PrintTreeVRL(root->left);
}
void PrintTreeLRV(Node* root)
{
    if (NULL == root)
        return;
    PrintTreeLRV(root->left);
    PrintTreeLRV(root->right);
    printf("Data : %d\n", root->data);
}
void PrintTreeRLV(Node* root)
{
    if (NULL == root)
        return;
    PrintTreeRLV(root->right);
    PrintTreeRLV(root->left);
    printf("Data : %d\n", root->data);
}
int DoubleKid(Node* root){
    if(root == NULL)
        return 0;
    if(root->left != NULL && root->right != NULL){
        return 1 + DoubleKid(root->left) + DoubleKid(root ->right);
    }
return  DoubleKid(root->left) + DoubleKid(root ->right);
}

int DoubleKid2(Node* pRoot)
{
    if(pRoot==NULL) {
        return 0;
    }
    if(pRoot->left!=NULL && pRoot->right!=NULL) {
        return 1 + DoubleKid2(pRoot->left) + DoubleKid2(pRoot->right);
    }
    return DoubleKid2(pRoot->left) + DoubleKid2(pRoot->right);
}
/*
int onlyLeft(Node* root){
    if(root == NULL)
        return 0;
    if(root->left != NULL && root->right == NULL){
        return onlyLeft(root->left) + onlyLeft(root->right) +1;

    }
    return onlyLeft(root->left) + onlyLeft(root->right);
}
*/
int onlyLeft(Node* root)
{
  
    if(root==NULL)
        return -1;
    if(root->left!=NULL&&root->right!=NULL)
    {
        return onlyLeft(root->left)+onlyLeft(root->right);
    }
    else if(root->left!=NULL)
    {
        return 1+onlyLeft(root->left);
    }
   else if(root->left==NULL && root->right!=NULL)
     {
        return 1+onlyLeft(root->left);
    }

}

int onlyRight(Node* root)
{
    if(root==NULL)
        return -1;
    if(root->left!=NULL&&root->right!=NULL)
    {

        return onlyRight(root->left)+onlyRight(root->right);
    }
    else if(root->right!=NULL)
    {
        return 1+onlyRight(root->right);
    }
    else if(root->right==NULL && root->left!=NULL)
    {
        return 1+onlyRight(root->right);
    }
}
/*
int onlyRight(Node* root){
    int r = 0;
    int l = 0;
    if(root == NULL){
        return -1;
    }
   if(root->left == NULL && root->right == NULL){
        return 0;
   }
   if(root->right != NULL && root->left == NULL){
        l = onlyRight(root->left);
        r = onlyRight(root->right);
        return 1 + r + l ;
}
return onlyRight(root->right) + onlyRight(root->left)+1;
}
*/
int getLeafCount(Node* root){
  if(root == NULL)
    return 0;
 else{
  if(root->left == NULL && root->right==NULL)
    return 1;
  else
    return getLeafCount(root->left) + getLeafCount(root->right);
}
}

int getParentCount(Node* root){
if(root == NULL)
  return 0;
else{
        if(root->left != NULL || root ->right != NULL)
            return getParentCount(root->left) + getParentCount(root->right)+1;
        else
            return getParentCount(root->left) + getParentCount(root->right);
    }
}
int height(Node*root){
    int leftH;
    int rightH;
if(root == NULL)
    return -1;
if(NULL == root->left && NULL == root->right)
    return 0;
else
    leftH = 1 + height(root->left);
    rightH = 1 + height(root->right);

    if(leftH> rightH)
        return leftH;
    else
        return rightH;
}


int search(Node *root, int dataToSearch)
{
    if(root==NULL)
        return -1;
    if(root->data==dataToSearch)
        return 1;
    else{
    if(dataToSearch>root->data){
        return search(root->right, dataToSearch);
    }
    else
        return search(root->left,dataToSearch);
}
}

int depthAnyData(Node*root , int dataToSearch){
  int rightS;
    int leftS;
    if(root==NULL)
        return -1;
    else if(search(root,dataToSearch)==1){
    if(root->data==dataToSearch)
        return 0;
    else{
    if(dataToSearch>root->data){
        rightS = depthAnyData(root->right, dataToSearch);
        return rightS + 1;
    }
    else
        leftS = depthAnyData(root->left,dataToSearch);
        return leftS + 1;
}
}
    else
        printf("data not exist \n");
        return -1;
}

int main()
{
    int i;
    Node* root = NULL;
    int data[] = { 4, 6, 2, 5, 3, 1, 25,28,32,30,29,40,50};
    for (i = 0; i < 13; ++i)
        root = AddItemToTree(root, data[i]);
printf("%d \n",onlyLeft(root));
printf("%d",onlyRight(root));
    return 0;
}
