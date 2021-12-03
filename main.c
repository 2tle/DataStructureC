#include <stdio.h>
#include "DataStructure.h"

DBLinkedList dlist;
BTreeNode* mainTree;
BTData bdata;
ListData data;

int sendMenu() {
	printf("===================================================\n");
	printf("|         C언어 프로그래밍 자료구조 구현             |\n");
	printf("| 1.양방향 연결리스트 생성 2.양방향 연결리스트 값추가|\n");
	printf("| 3. 양방향 연결 리스트 출력 4. 이진 트리 생성       |\n");
	printf("| 5. 이진트리 전위순회 출력 6. 이진트리 중위순회 출력|\n");
	printf("| 7.이진트리 후위순회 출력             나머지. 종료  |\n ");
	printf("===================================================\n");
	printf("| 번호를 선택하세요(나머지는 종료) >");
	int m;
	scanf("%d",&m);
	return m;
}

void initDBLL() {
	initDBLinkedList(&dlist);
	printf("===================================================\n");
	printf("             양방향 연결 리스트 생성 완료            \n");
	printf("===================================================\n");
}

void addDBLL() {
	printf("===================================================\n");
	printf("| 추가 할 값의 개수를 입력하세요 >");
	int size=0;
	scanf("%d",&size);
	for(int i = 0;i <size;i++) {
		ListData ldata = 0;
		printf("| (%d 번째 값 입력) >",i+1);
		scanf("%d",&ldata);
		insertDBLinkedList(&dlist, ldata);
	}
	printf("===================================================\n");
	printf("             양방향 연결리스트 값 추가완료            \n");
	printf("===================================================\n");
}

void printDBLL() {
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
}

void inorder() {
	inorderTraverseBT(mainTree);
	printf("\n");
}

void preorder() {
	preorderTraverseBT(mainTree);
	printf("\n");
}

void postorder() {
	postorderTraverseBT(mainTree);
	printf("\n");
}

void ejin() {
	mainTree = MakeBTreeNode();
	printf("===================================================\n");
	int size=3;
	for(int i = 0;i <size;i++) {
		BTData ldata = 0;
		printf("| (%d 번째 값 입력) >",i+1);
		scanf("%d",&ldata);
		if(i==0) SetBTData(mainTree, ldata);
		else if(i==1) {
			BTreeNode* tempBTreeNode = MakeBTreeNode();
			SetBTData(tempBTreeNode, ldata);
			MakeBTLeftSubTree(mainTree, tempBTreeNode);
		} else {
			BTreeNode* tempBTreeNode = MakeBTreeNode();
			SetBTData(tempBTreeNode, ldata);
			MakeBTRightSubTree(mainTree, tempBTreeNode);
		}	
	}
	printf("===================================================\n");
	printf("                이진 트리 생성 완료                 \n");
	printf("===================================================\n");

}

int main(void) {
	int menu;
	int whileVar = TRUE;
	while(whileVar) {
		menu = sendMenu();

		switch(menu) {
			case 1:
				initDBLL();
				break;
			case 2:
				addDBLL();
				break;
			case 3:
				printDBLL();
				break;
			case 4:
				ejin();
				break;
			case 5:
				preorder();
				break;
			case 6:
				inorder();
				break;
			case 7:
				postorder();
				break;
			default:
				whileVar = FALSE;
				break;
				
		}

	}
	/*
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
	*/

}