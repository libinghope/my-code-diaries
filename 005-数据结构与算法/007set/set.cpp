/*
在cpp stl当中，set就是hashmap，只不过是key，value是同一个而已
*/


//用数组来表示set，以下是浙大公开课当中讲的内容
typedef struct common_set{
    int data;

    //跟节点的parent是-1，其实可以用一种更加巧妙的方式，如果Node是root，size是总共元素个数，可设
    //其parent = -size;负号表示根节点，绝对值代表size(元素个数)
    int parent;//父节点下标，没有为-1
}Set,Set_Node,set_type;

#define MAX_SIZE 1000
//查找x元素所在的集合
int find(Set set[], int x){

    int i=0;
    for(;i<MAX_SIZE && set[i].data!=x;i++);
    if(i>=MAX_SIZE) return -1;
    for(;set[i].parent >=0; i= set[i].parent);
    return i;
}

void uion(Set s[], int x1,int x2){
    
    //先找出x1,x2所在集合的下标
    int root1 = find(s,x1);
    int root2 = find(s,x2);

    //把s2的parent设置为 s1(根节点)的下标,太简单
    if(root1 != root2) s[root2].parent = root1;
}