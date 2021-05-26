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

    printf("== �̦��K�[: ");
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        printf("%d ", arr[i]);
        root = insert_bstree(root, arr[i]);
    }

    printf("\n== �e�ǹM��: ");
    preorder_bstree(root);

    printf("\n== ���ǹM��: ");
    inorder_bstree(root);

    printf("\n== ��ǹM��: ");
    postorder_bstree(root);
    printf("\n");

    printf("== �̤p��: %d\n", bstree_minimum(root)->key);
    printf("== �̤j��: %d\n", bstree_maximum(root)->key);
    printf("== �𪺸ԲӸ�T: \n");
    print_bstree(root, root->key, 0);

    printf("\n== �R���ڸ`�I: %d", arr[3]);
    root = delete_bstree(root, arr[3]);

    printf("\n== ���ǹM��: ");
    inorder_bstree(root);
    printf("\n");

    // �P���G�e��
    destroy_bstree(root);
    return 0;
}
