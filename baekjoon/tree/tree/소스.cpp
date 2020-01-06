#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode { //Ʈ�� ��� ����
	int data;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* makeRootNode(int data, treeNode* leftNode, treeNode* rightNode) 
{ //data�� ��Ʈ ���� �Ͽ� ���� ����Ʈ���� ������ ����Ʈ���� �����ϴ� ����
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

void preorder(treeNode* root) //���� Ʈ���� ���� ���� ��ȸ ����
{
	if (root) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(treeNode* root) //���� Ʈ���� ���� ���� ��ȸ ����
{
	if (root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void postorder(treeNode* root) //���� Ʈ���� ���� ���� ��ȸ ����
{
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

int main()
{
	treeNode* n9 = makeRootNode(4, NULL, NULL);
	treeNode* n8 = makeRootNode(11, NULL, NULL);
	treeNode* n7 = makeRootNode(5, NULL, NULL);
	treeNode* n6 = makeRootNode(9, n9, NULL);
	treeNode* n5 = makeRootNode(6, n7, n8);
	treeNode* n4 = makeRootNode(2, NULL, NULL);
	treeNode* n3 = makeRootNode(5, NULL, n6);
	treeNode* n2 = makeRootNode(7, n4, n5);
	treeNode* n1 = makeRootNode(2, n2, n3);
	
	printf("\n preorder : ");
	preorder(n1);

	printf("\n inorder : ");
	inorder(n1);

	printf("\n postorder : ");
	postorder(n1);

	getchar();

	return 0;
}