
#include <stdio.h>
#include <stdlib.h>

//����ڵ� 
typedef struct  Node {
	int data;
	Node* next;
};


//�����ڵ�
Node* createNode(int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("�����ڵ�ʧ��\n");
		exit(0);//�˳�����
	}
	else {
		newNode->data = val;
		newNode->next = NULL;
		return newNode;
	}
}


//��ӡ
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

//β���뷨��tail��������˼����Ҫ���µĽڵ���ӵ��������ڵ㣨β�ڵ㣩֮��
void LinkedListCreatTail(Node* &phead,int data) {
	//���㲽�����pheadΪnull�����ʾͷ�ڵ�Ϊ�գ���û�г�ʼ�����������Ҫ����ͷ�ڵ�
	if (phead == NULL)
		phead = createNode(data);
	else {
		Node* tail = phead;
		//��һ������Ҫ�ҵ�β�ڵ�(β�ڵ���ص��ǣ�����next��ֵһ��Ϊnull)
		while (tail->next != NULL)
			tail = tail->next;

		//�ڶ����������½ڵ㲢��ʼ��
		Node* newNode = createNode(data);

		//�����������뵽β�ڵ�֮��
		tail->next = newNode;
	}
}
//βɾ��
void LinkedListDeleteTail(Node*& phead) {
	//����һ��
	//if (phead->next == NULL) {
	//	//�����һ��ָ��Ϊ�գ����ʾ����ֻʣ��һ���ڵ��ˣ�ֱ���ÿ�
	//	free(phead);//�ͷ��ڴ�
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

	//	free(tail);//�ͷ��ڴ�
	//	tail = NULL;

	//	//ע�⣬�ͷ�β�ڵ�ʱ����Ҫ��β�ڵ����һ��nextָ���ÿգ����Ҳ����Ѿ����ͷŵ��ڴ��ַ
	//	//�������prev����
	//	prev->next = NULL;
	//}

	//��������
	Node* tail = phead;
	while (tail->next->next)
		tail = tail->next;
	free(tail->next);//�ͷ��ڴ�
	tail->next = NULL;
}




//ͷ���뷨��Head��
void LinkedListCreatHead(Node*& phead, int data) {
	//1.����һ���½ڵ�
	Node* newNode = createNode(data);

	//2.�½ڵ�ָ����Ǿɽڵ㣬�� nowNode -> phead��
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
	//����ͷ�ڵ�
	printf("β���뷨��");
	Node* plist = NULL;
	LinkedListCreatTail(plist, 1);
	LinkedListCreatTail(plist, 2);
	LinkedListCreatTail(plist, 3);
	printList(plist);

	printf("\n");

	//����ͷ�ڵ�
	printf("ͷ���뷨��");
	Node* plist2 = NULL;
	LinkedListCreatHead(plist2, 1);
	LinkedListCreatHead(plist2, 2);
	LinkedListCreatHead(plist2, 3);
	printList(plist2);

	printf("\n\n");
	//βɾ��
	printf("βɾ����");
	LinkedListDeleteTail(plist);
	LinkedListDeleteTail(plist);
	LinkedListDeleteTail(plist);
	printList(plist);


	//���⣺�β�phead�ĸı䲻��Ӱ��ʵ��plist����Ϊʵ�����β�phead�ǿ�����plist��˲��ᷢ���ı�
	//���������ʹ�ö���ָ��-��ָ���ָ��(������)��ֻ��Ҫȡָ����ڴ��ַ����Node* &phead
}