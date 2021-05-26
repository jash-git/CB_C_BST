#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

//https://www.cnblogs.com/skywang12345/p/3576328.html
static int arr[]= {1,5,4,3,2,6};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i, ilen;
    BSTree root=NULL;

    printf("== 依次添加: ");
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        printf("%d ", arr[i]);
        root = insert_bstree(root, arr[i]);
    }

    printf("\n== 前序遍歷: ");
    preorder_bstree(root);

    printf("\n== 中序遍歷: ");
    inorder_bstree(root);

    printf("\n== 後序遍歷: ");
    postorder_bstree(root);
    printf("\n");

    printf("== 最小值: %d\n", bstree_minimum(root)->key);
    printf("== 最大值: %d\n", bstree_maximum(root)->key);
    printf("== 樹的詳細資訊: \n");
    print_bstree(root, root->key, 0);

    printf("\n== 刪除根節點: %d", arr[3]);
    root = delete_bstree(root, arr[3]);

    printf("\n== 中序遍歷: ");
    inorder_bstree(root);
    printf("\n");

    // 銷毀二叉樹
    destroy_bstree(root);
    return 0;
}
