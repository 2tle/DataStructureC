#include <stdio.h>
#include "DataStructure.h"
int main(void) {
	printf("양방향 연결 리스트\n");
	DBLinkedList dlist;
	ListData data; //int
	initDBLinkedList(&dlist);
	insertDBLinkedList(&dlist, 1);
	insertDBLinkedList(&dlist, 2);
	insertDBLinkedList(&dlist, 3);
	insertDBLinkedList(&dlist, 4);
	insertDBLinkedList(&dlist, 5);
	insertDBLinkedList(&dlist, 6);
	if(getFirstDBLinkedList(&dlist, &data)) {
		printf("%d ", data);
		while(getNextDBLinkedList(&dlist, &data)) {
			printf("%d ",data);
		}
		while(getPreviousDBLinkedList(&dlist, &data)) {
			printf("%d ",data);
		}
		printf("\n\n");
	}

	
	printf("이진 트리\n");
	BTreeNode* bt1 = MakeBTreeNode();
	BTreeNode* bt2 = MakeBTreeNode();
	BTreeNode* bt3 = MakeBTreeNode();

	SetBTData(bt1, 1);
	SetBTData(bt2, 2);
	SetBTData(bt3, 3);

	MakeBTLeftSubTree(bt1, bt2);
	MakeBTRightSubTree(bt1, bt3);

	inorderTraverseBT(bt1);
	printf("\n");
  

}