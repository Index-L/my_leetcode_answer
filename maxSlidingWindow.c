/*
����һ������ nums �ͻ������ڵĴ�С k�����ҳ����л�������������ֵ��

ʾ��:

����: nums = [1,3,-1,-3,5,3,6,7], �� k = 3
���: [3,3,5,5,6,7] 
����: 

  �������ڵ�λ��                ���ֵ
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
?

��ʾ��

����Լ��� k ������Ч�ģ����������鲻Ϊ�յ�����£�1 �� k ��?��������Ĵ�С��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if(numsSize==0 || nums==NULL){//����������� 
        *returnSize=0;
        return NULL;
    }
    
    int* maxarr = (int*)malloc(sizeof(int)*(numsSize-k+1));//��Ҫ���Ƿ���ռ� 
    for(int i = 0; i < numsSize-k+1; i++){
        int max = nums[i];
        for(int j = i; j < i+k; j++) 
            if(nums[j] > max) max = nums[j];
        maxarr[i] = max;
    }

    *returnSize=numsSize-k+1;//�������������Ĵ�С 
    return maxarr;

}
