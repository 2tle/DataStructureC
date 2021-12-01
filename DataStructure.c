#include <stdio.h>
#include <stdlib.h>
#include "DataStructure.h"

/*DBLinkedList*/
void initDBLinkedList(DBLinkedList* plist) {
	plist->head = NULL;
	plist->length = 0;
}

void insertDBLinkedList(DBLinkedList* plist, ListData data) {
	DoubleNode* nNode = (DoubleNode*)malloc(sizeof(DoubleNode));
	nNode->data = data;
	nNode->next = plist->head;
	if(plist->head != NULL) {
		plist->head->prev = nNode;
	}
	nNode->prev = NULL;
	plist->head=nNode;
	(plist->length)++;
}

int getFirstDBLinkedList(DBLinkedList* plist, ListData* data) {
	if(plist->head == NULL) return FALSE;
	plist->cur = plist->head;
	*data = plist->cur->data;
	return TRUE;
}
int getNextDBLinkedList(DBLinkedList* plist, ListData* data) {
	if(plist->cur->next == NULL) return FALSE;
	plist->cur = plist->cur->next;
	*data = plist->cur->data;
	return TRUE;
}
int getPreviousDBLinkedList(DBLinkedList* plist, ListData* data) {
	if(plist->cur->prev == NULL) return FALSE;
	plist->cur = plist->cur->prev;
	*data = plist->cur->data;
	return TRUE;
}

int getDBLinkedListLength(DBLinkedList* plist, ListData* data) {return plist->length;}

/*Binayr Tree*/
BTreeNode* MakeBTreeNode(void) {
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));

	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetBTData(BTreeNode* bt) {
	return bt->data;
}

void SetBTData(BTreeNode* bt,BTData data) {
	bt->data = data;
}

BTreeNode* GetBTLeftSubTree(BTreeNode* bt) {
	return bt->left;
}

BTreeNode* GetBTRightSubTree(BTreeNode* bt) {
	return bt->right;
}

void MakeBTLeftSubTree(BTreeNode* main, BTreeNode* sub) {
	if(main->left != NULL) {
		free(main->left);
	}
	main->left = sub;
}

void MakeBTRightSubTree(BTreeNode* main, BTreeNode* sub) {
	if(main->right != NULL) {
		free(main->right);
	}
	main->right = sub;
}

void inorderTraverseBT(BTreeNode* bt) {
	if(bt==NULL) return;
	inorderTraverseBT(bt->left);
	printf("%d ",bt->data);
	inorderTraverseBT(bt->right);
}

void preorderTraverseBT(BTreeNode* bt) {
	if(bt==NULL) return;
	printf("%d ",bt->data);
	preorderTraverseBT(bt->left);
	preorderTraverseBT(bt->right);
}

void postorderTraverseBT(BTreeNode* bt) {
	if(bt==NULL) return;
	postorderTraverseBT(bt->left);
	postorderTraverseBT(bt->right);
	printf("%d ",bt->data);
}