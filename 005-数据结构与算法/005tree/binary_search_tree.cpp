typedef struct _b_search_tree
{
    int data; //假设放的是整数
    _b_search_tree *pLeft;
    _b_search_tree *pRight;
} BinarySearchTreeNode, BSTree, bSearchTree, __node;

//遍历与一般二叉树一样 略

//查找最大最小，分别向右下和左下走到头，略

//查找
BSTree* InterFind(BSTree *bstree, int data)
{
    BSTree *cur_node = bstree;
    while (cur_node)
    {
        if (data > cur_node->data)
        {
            cur_node = cur_node->pRight;
        }
        else if (data < cur_node->data)
        {
            cur_node = cur_node->pRight;
        }
        else
        {
            return cur_node;
        }
    }
    return nullptr;
}


void free_node(BSTree* node){}
//删除 递归方法
BSTree* BSTreeDelete(BSTree *bstree,int data){
    if(!bstree){return nullptr;}

    BSTree *cur_node = bstree;
    if(data>cur_node->data){
        BSTreeDelete(cur_node->pRight, data);//要找的节点在右边
    }else if(data<cur_node->data){
        BSTreeDelete(cur_node->pRight, data);//要找的节点在左边
    }else{
        //找到目标结点
        //分四种情况，1、为叶子节点 2、只有左孩子 3、只有右孩子 4、左右都有 (2,3可合并)
        if(!cur_node->pLeft && !cur_node->pRight){//没有孩子
            free_node(cur_node);
        }else if(cur_node->pLeft || cur_node->pRight){//有一个孩子
            BSTree * tmp = cur_node;
            cur_node = cur_node->pLeft ? cur_node->pLeft :cur_node->pRight ;
            free_node(tmp);
        }else if(cur_node->pLeft && cur_node->pRight){//有两个孩子
            //这时候有两种选择来替换掉删除的结点,
            //1、取左子树的最大值
            //2、取右子树最小值
            BSTree *tmp = cur_node;
            BSTree * rt = cur_node->pRight;
            while (rt->pLeft)//这里取右子树最小值
            {
                rt = rt->pLeft;
            }
            BSTree tmprt = *rt;
            cur_node = &tmprt;//右子树最小节点替换要删除的结点
            free_node(rt);//切断右子树最小值与父节点的关联
            free_node(tmp);//释放目标节点 
        }
    }
}