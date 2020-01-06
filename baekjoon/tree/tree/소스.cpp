#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode { //트리 노드 정의
	int data;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* makeRootNode(int data, treeNode* leftNode, treeNode* rightNode) 
{ //data를 루트 노드로 하여 왼쪽 서브트리와 오른쪽 서브트리를 연결하는 연산
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

void preorder(treeNode* root) //이진 트리에 대한 전위 순회 연산
{
	if (root) {
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(treeNode* root) //이진 트리에 대한 중위 순회 연산
{
	if (root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void postorder(treeNode* root) //이진 트리에 대한 후위 순회 연산
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