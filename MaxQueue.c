/*
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value?需要返回 -1

示例 1：

输入: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
输出:[null,null,null,2,1,2]

示例 2：

输入: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
输出:[null,-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 

typedef struct {
    int front, rear;
    int data[10001];
} MaxQueue;//基本的队列结构体 

MaxQueue *obj = NULL;

MaxQueue* maxQueueCreate() {
    obj = (MaxQueue*)malloc(sizeof(MaxQueue));//不要忘记分配空间 
    obj->front = 0;
    obj->rear = 0;
    return obj; 
}//基本的队列初始化 

int maxQueueMax_value(MaxQueue* obj) {
    if(obj == NULL) return NULL;
    if(obj->front == obj->rear) return -1;
    else{
        int max = 0;
        int init_f = obj->front;
        while(obj->front != obj->rear){
            if(obj->data[obj->front] > max) max = obj->data[obj->front];//基本的查找队列中的最大值 
            obj->front ++;            
        }
        obj->front = init_f;
        return max;  
    }
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    if(obj != NULL)
        obj->data[obj->rear++] = value;//入队 
}

int maxQueuePop_front(MaxQueue* obj) {
    
    if(obj != NULL){
        if(obj->front == obj->rear) return -1;
        else{
            int f = obj->data[obj->front];//出队 
            obj->front++;
            return f;
        }    
        
    }
    else return NULL;
}

void maxQueueFree(MaxQueue* obj) {
    free(obj);
}

/**
 * Your MaxQueue struct will be instantiated and called as such:
 * MaxQueue* obj = maxQueueCreate();
 * int param_1 = maxQueueMax_value(obj);
 
 * maxQueuePush_back(obj, value);
 
 * int param_3 = maxQueuePop_front(obj);
 
 * maxQueueFree(obj);
*/
