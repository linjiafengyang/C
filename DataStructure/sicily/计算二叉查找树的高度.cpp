#include <iostream>
using namespace std;
int preorder[1000001];//先序
int inorder[1000001];//中序
int height = 0;
void findHeight(int root, int left, int right, int h) {
	if (left >= right) return;//判断是否为空树
	int pivot = preorder[root];
	int pos = left;
	if (h > height) height = h;//更新树的高度
	while (pos < right && inorder[pos] != pivot) pos++;//找根节点在中序遍历中的下标
	if (left < pos) findHeight(root + 1, left, pos, h + 1);//递归遍历左子树
	if (pos + 1 < right) findHeight(root + pos - left + 1, pos + 1, right, h + 1);//递归遍历右子树
}
int main(int argc, char const *argv[])
{
	int t, n;
	cin >> t;
	while (t--) {
		height = -1;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> preorder[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> inorder[i];
		}
		findHeight(0, 0, n, 0);
		cout << height << endl;
	}
	return 0;
}
//http://blog.csdn.net/elliott_yoho/article/details/53965046