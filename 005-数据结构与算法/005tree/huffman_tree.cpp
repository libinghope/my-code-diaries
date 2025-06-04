/*--------------------------------------
|字符:  a    e    i    s    t    p    n  |
|频次:  10   15   12   3    4    13   1  |
---------------------------------------*/

//由以上字符及其频次生成赫夫曼编码(生成哈夫曼树)

typedef struct _binary_tree_node
{
    _binary_tree_node(int t){
        data=t;
    }
    int data;
    _binary_tree_node *pLeft;
    _binary_tree_node *pRight;
} BinaryTreeNode, *BinaryTree, __node;

//第一步是先排序，排序算法见sort文件夹
//假设已经排序好了,数组如下
int arr[] = {1,3,4,10,12,13,15};
BinaryTree createHuffmanTree(){
    BinaryTree minnode= new BinaryTreeNode(arr[0]);

    //每次取出一个最小的，和minnode值加在一起组成根节点
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        BinaryTree node = new BinaryTreeNode(arr[i+1]);
        int new_data = minnode->data + arr[i+1];
        BinaryTree root_node = new BinaryTreeNode(new_data);
        root_node->pLeft = minnode;
        root_node->pRight = node;
        minnode = root_node;
    }

    return minnode;
}

void free_huff_man_tree(){
    //todo
}