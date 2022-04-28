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

//pass VisitFunc dinamycally in caller 
//VisicFunc ditermine what to do at Node
typedef void (*VisitFuncPtr)(BTData data);

void PreorderTraverse(BTreeNode * bt, VisitFuncPtr action){
    if( bt == NULL){
        return;
    }
    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

//passed bt is leftmost Node?? root Node?
void InorderTraverse(BTreeNode * bt, VisitFuncPtr action){
    if( bt == NULL){
        return;
    }
    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode * bt, VisitFuncPtr action){
    if( bt == NULL){
        return;
    }
    InorderTraverse(bt->left, action);
    InorderTraverse(bt->right, action);
    action(bt->data);
}

void DeleteTree(BTreeNode * bt){
    if( bt == NULL){
        return;
    }
    DeleteTree(bt->left);
    DeleteTree(bt->right);
    free(bt);
}