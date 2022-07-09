// C++ program to print Postorder
// traversal from given Inorder
// and Preorder traversals.
#include <iostream>
using namespace std;

int preIndex = 0;

int search(int arr[], int startIn,int endIn, int data)
{
	int i = 0;
	for (i = startIn; i < endIn; i++)
	{
		if (arr[i] == data)
		{
			return i;
		}
	}
	return i;
}
void printPost(int arr[], int pre[],int inStrt, int inEnd)
{
	if (inStrt > inEnd)
	{
		return;
	}

	// Find index of next item in preorder
	// traversal in inorder.
	int inIndex = search(arr, inStrt, inEnd,pre[preIndex++]);

	// traverse left tree
	printPost(arr, pre, inStrt, inIndex - 1);

	// traverse right tree
	printPost(arr, pre, inIndex + 1, inEnd);

	// print root node at the end of traversal
	cout << arr[inIndex] << " ";
}

// Driver code
int main()
{
	int arr[] = {10 ,50 ,60 ,90 ,93 ,95 ,99 ,100, 125 ,130, 135 ,150 ,180, 200 ,250};
	int pre[] = {100, 90, 50, 10, 60, 95, 93, 99, 150, 130, 125, 135, 200, 180, 250};
	int len = sizeof(arr)/sizeof(arr[0]);
	printPost(arr, pre, 0, len - 1);
}

// This code is contributed by SHUBHAMSINGH10
