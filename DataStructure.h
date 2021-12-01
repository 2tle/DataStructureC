

#define TRUE 1
#define FALSE 0

/* Default Data Type */
typedef int ListData;
typedef int BTData;



typedef struct __doubleNode {
	ListData data;
	struct __doubleNode* prev;
	struct __doubleNode* next;
} DoubleNode;

typedef struct __doubleNodeLinkedList {
	DoubleNode* head;
	DoubleNode* cur;
	int length;
} DBLinkedList;

typedef struct __bTreeNode{
	BTData data;
	struct __bTreeNode *left;
	struct __bTreeNode *right;
} BTreeNode;

/*DBLinkedList Func */

void initDBLinkedList(DBLinkedList* plist);

void insertDBLinkedList(DBLinkedList* plist, ListData data);

int getFirstDBLinkedList(DBLinkedList* plist, ListData* data);
int getNextDBLinkedList(DBLinkedList* plist, ListData* data);
int getPreviousDBLinkedList(DBLinkedList* plist, ListData* data);

int getDBLinkedListLength(DBLinkedList* plist, ListData* data);

/* Binary Tree Func */

BTreeNode* MakeBTreeNode(void);

BTData GetBTData(BTreeNode * bt);

void SetBTData(BTreeNode* bt, BTData data);

BTreeNode* GetBTLeftSubTree(BTreeNode* bt);

BTreeNode* GetBTRightSubTree(BTreeNode* bt);

void MakeBTLeftSubTree(BTreeNode* main, BTreeNode* sub);

void MakeBTRightSubTree(BTreeNode* main, BTreeNode *sub);

void preorderTraverseBT(BTreeNode* bt);

void inorderTraverseBT(BTreeNode* bt);

void postorderTraverseBT(BTreeNode* bt);





































