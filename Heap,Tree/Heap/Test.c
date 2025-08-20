#include"Heap.h"

void TestHeap1()
{
	int a[] = { 4,2,8,1,5,6,9,7,3,2,23,55,232,66,222,33,7,1,66,3333,999 };
	HP hp;
	HPInit(&hp);
	for (size_t i = 0; i < sizeof(a) / sizeof(int); i++)
	{
		HPPush(&hp, a[i]);
	}

	int i = 0;
	while (!HPEmpty(&hp))
	{
		printf("%d ", HPTop(&hp));
		//a[i++] = HPTop(&hp);
		HPPop(&hp);
	}
	printf("\n");

	// �ҳ�����ǰk��
	/*int k = 0;
	scanf("%d", &k);
	while (k--)
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}
	printf("\n");*/

	HPDestroy(&hp);
}

// ������    O(N*logN)
// ð������  O(N^2) 
void HeapSort(int* a, int n)
{
	// ���򣬽�С��
	// ���򣬽����
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/

	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/

	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void TestHeap2()
{
	int a[] = { 4,2,8,1,5,6,9,7,2,7,9 };
	HeapSort(a, sizeof(a) / sizeof(int));
}
void TestHeap3()
{
	int k;
	printf("������k>:");
	scanf_s("%d", &k);
	int* kminheap = (int*)malloc(sizeof(int) * k);
	if (kminheap == NULL)
	{
		perror("malloc fail");
		return;
	}
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen error");
		return;
	}

	// ��ȡ�ļ���ǰk����
	for (int i = 0; i < k; i++)
	{
		scanf_s(fout, "%d", &kminheap[i]);
	}
	// ��K������С��
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(kminheap, k, i);
	}

	// ��ȡʣ�µ�N-K����
	int x = 0;
	while (fscanf(fout, "%d", &x) > 0)
	{
		if (x > kminheap[0])
		{
			kminheap[0] = x;
			AdjustDown(kminheap, k, 0);
		}
	}

	printf("���ǰ%d������", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d ", kminheap[i]);
	}
	printf("\n");
}
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(6);


	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;

	return node1;
}
void PrevOrder(BTNode * root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}
//����ʾ��
//int TreeSize(BTNode* root)
//{
//	static int size = 0;
//	if (root == NULL)
//		return 0;
//	else
//		++size;
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}
//int size = 0;
//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	else
//		++size;
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}
//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//		return 0;
//	else
//		++(*psize);
//
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) + TreeSize(root->right) + 1;
}
int TreeLeafsize(BTNode * root)
{
		if (root == NULL)  // �������� 0
			return 0;
		if (root->left == NULL && root->right == NULL) // Ҷ�ӽ��
			return 1;
		// ����ݹ�ͳ����������
		return TreeLeafsize(root->left) + TreeLeafsize(root->right);
}
//����Ч������
//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)  // �������� 0
//		return 0;
//	return TreeHeight(root->left) > TreeHeight(root->right) ?
//		TreeHeight(root->left) + 1 :TreeHeight(root->right)+ 1;
//}
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ?
		leftHeight + 1 : rightHeight + 1;
}
int TreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	// ������
	return TreeLevelKSize(root->left, k - 1)
		+ TreeLevelKSize(root->right, k - 1);
}
//����ʾ��
//����������ֵΪx�Ľڵ�
//BTNode* TreeFind(BTNode* root, BTDataType x)
//{
//	if (root == NULL)
//		return NULL;
//
//	if (root->data == x)
//		return root;
//	TreeFind(root->left, x);
//	TreeFind(root->right,x);
//}
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;

	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;

	return NULL;
}

//BTNode* TreeFind(BTNode* root, BTDataType x)
//{
//	if (root == NULL)
//		return NULL;
//
//	if (root->data == x)
//		return root;
//
//	BTNode* ret1 = TreeFind(root->left, x);
//	if (ret1)
//		return ret1;
//
//	return TreeFind(root->right, x);
//}
int main()
{
	/*BTNode* root1 = CreatBinaryTree();
	PrevOrder(root1);
	printf("\n");
	BTNode* root2 = CreatBinaryTree();
	InOrder(root2);
	printf("\n");
	BTNode* root3 = CreatBinaryTree();
	PostOrder(root3);
	printf("\n");*/
	//TestHeap2();
	//TestHeap3();
	BTNode * root = CreatBinaryTree();
	//int size = 0;
	//TreeSize(root, &size);
	//printf("TreeSize:%d\n",size);
	//printf("TreeSize:%d\n",size);
	printf("TreeSize:%d\n", TreeSize(root));
	printf("TreeLeafsize:%d\n", TreeLeafsize(root));
	printf("TreeHeight:%d\n", TreeHeight(root));
	printf("TreeLevelKSize:%d\n", TreeLevelKSize(root,2));
	return 0;
}