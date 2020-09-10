/*
�붨��һ�����в�ʵ�ֺ��� max_value �õ�����������ֵ��Ҫ����max_value��push_back �� pop_front �ľ�̯ʱ�临�Ӷȶ���O(1)��

������Ϊ�գ�pop_front �� max_value?��Ҫ���� -1

ʾ�� 1��

����: 
["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
[[],[1],[2],[],[],[]]
���:[null,null,null,2,1,2]

ʾ�� 2��

����: 
["MaxQueue","pop_front","max_value"]
[[],[],[]]
���:[null,-1,-1]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/ 

typedef struct {
    int front, rear;
    int data[10001];
} MaxQueue;//�����Ķ��нṹ�� 

MaxQueue *obj = NULL;

MaxQueue* maxQueueCreate() {
    obj = (MaxQueue*)malloc(sizeof(MaxQueue));//��Ҫ���Ƿ���ռ� 
    obj->front = 0;
    obj->rear = 0;
    return obj; 
}//�����Ķ��г�ʼ�� 

int maxQueueMax_value(MaxQueue* obj) {
    if(obj == NULL) return NULL;
    if(obj->front == obj->rear) return -1;
    else{
        int max = 0;
        int init_f = obj->front;
        while(obj->front != obj->rear){
            if(obj->data[obj->front] > max) max = obj->data[obj->front];//�����Ĳ��Ҷ����е����ֵ 
            obj->front ++;            
        }
        obj->front = init_f;
        return max;  
    }
}

void maxQueuePush_back(MaxQueue* obj, int value) {
    if(obj != NULL)
        obj->data[obj->rear++] = value;//��� 
}

int maxQueuePop_front(MaxQueue* obj) {
    
    if(obj != NULL){
        if(obj->front == obj->rear) return -1;
        else{
            int f = obj->data[obj->front];//���� 
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
