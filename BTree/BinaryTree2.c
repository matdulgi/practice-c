#include <stdio.h>
#include "BinaryTree2.h"
#include <stdlib.h>

BTreeNode * MakeBTreeNode(void){
    BTreeNode * node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->left = NULL;
    node->right = NULL;
}
BTData GetData(BTreeNode * bt){
    return bt->data;
}
void SetData(BTreeNode * bt, BTData data){
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt){
    return bt->left;
}
BTreeNode * GetRightSubTree(BTreeNode * bt){
    return bt->right;
}

//pass subtree by parameter
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub){
    if (main->left != NULL){
        free(main->left);
    }
    main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub){
    if (main->left != NULL){
        free(main->left);
    }
    main->right = sub;
}

//pass visitFunc dinamycally in caller 
typedef void (*VisitFuncPtr)(BTData data);

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action){
    if( (*bt) == NULL){

    }
}

void InorderTraverse(BTreeNode * bt, VisitFuncPtr action){

}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action){

}
