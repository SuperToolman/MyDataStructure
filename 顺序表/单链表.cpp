
#include <stdio.h>
#include <stdlib.h>

//定义节点 
typedef struct  Node {
	int data;
	Node* next;
};


//创建节点
Node* createNode(int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("创建节点失败\n");
		exit(0);//退出程序
	}
	else {
		newNode->data = val;
		newNode->next = NULL;
		return newNode;
	}
}


//打印
void printList(Node* head) {
	Node* cur = head;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;

		if (cur == NULL)
			printf("NULL");
	}
}

//尾插入法（tail）：顾名思义需要将新的节点添加到链表最后节点（尾节点）之后
void LinkedListCreatTail(Node* &phead,int data) {
	//第零步、如果phead为null，则表示头节点为空，则没有初始化该链表，因此要创建头节点
	if (phead == NULL)
		phead = createNode(data);
	else {
		Node* tail = phead;
		//第一步、需要找到尾节点(尾节点的特点是：它的next的值一定为null)
		while (tail->next != NULL)
			tail = tail->next;

		//第二步、创建新节点并初始化
		Node* newNode = createNode(data);

		//第三步、插入到尾节点之后
		tail->next = newNode;
	}
}
//尾删除
void LinkedListDeleteTail(Node*& phead) {
	//方法一：
	//if (phead->next == NULL) {
	//	//如果下一个指向为空，则表示链表只剩下一个节点了，直接置空
	//	free(phead);//释放内存
	//	phead = NULL;
	//}
	//else
	//{
	//	Node* tail = phead;
	//	Node* prev = NULL;
	//	while (tail->next != NULL) {
	//		prev = tail;
	//		tail = tail->next;
	//	}

	//	free(tail);//释放内存
	//	tail = NULL;

	//	//注意，释放尾节点时，需要将尾节点的上一个next指向，置空，而且不是已经被释放的内存地址
	//	//因此引入prev变量
	//	prev->next = NULL;
	//}

	//方法二：
	Node* tail = phead;
	while (tail->next->next)
		tail = tail->next;
	free(tail->next);//释放内存
	tail->next = NULL;
}




//头插入法（Head）
void LinkedListCreatHead(Node*& phead, int data) {
	//1.创建一个新节点
	Node* newNode = createNode(data);

	//2.新节点指向的是旧节点，即 nowNode -> phead，
	newNode->next = phead;
	phead = newNode;
	
}



void testInsert(Node*& phead, int index,int val) {
	Node* newNode = createNode(val);
	Node* target = NULL;

	for (int i = 0; i < index; i++)
	{
		//target = 
	}
	

}

int main() {
	//创建头节点
	printf("尾插入法：");
	Node* plist = NULL;
	LinkedListCreatTail(plist, 1);
	LinkedListCreatTail(plist, 2);
	LinkedListCreatTail(plist, 3);
	printList(plist);

	printf("\n");

	//创建头节点
	printf("头插入法：");
	Node* plist2 = NULL;
	LinkedListCreatHead(plist2, 1);
	LinkedListCreatHead(plist2, 2);
	LinkedListCreatHead(plist2, 3);
	printList(plist2);

	printf("\n\n");
	//尾删除
	printf("尾删除：");
	LinkedListDeleteTail(plist);
	LinkedListDeleteTail(plist);
	LinkedListDeleteTail(plist);
	printList(plist);


	//问题：形参phead的改变不能影响实参plist，因为实际上形参phead是拷贝自plist因此不会发生改变
	//解决方法：使用二级指针-及指针的指针(解引用)，只需要取指针的内存地址：即Node* &phead
}