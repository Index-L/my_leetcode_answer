/*
дһ������������ n ����쳲�������Fibonacci�����еĵ� n �쳲��������еĶ������£�

F(0) = 0, F(1)= 1
F(N) = F(N - 1) + F(N - 2), ���� N > 1.
쳲����������� 0 �� 1 ��ʼ��֮���쳲�������������֮ǰ��������Ӷ��ó���

����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
int fib(int n){
    if(n == 0)    return 0;
    if(n == 1)    return 1;
    int fibo[101];
    fibo[0] = 0;
    fibo[1] = 1;
    for(int i = 2; i < 101; i++){
        fibo[i] = (fibo[i-1] + fibo[i-2])%1000000007;
    }
    return fibo[n];
} //�ǵݹ��㷨 

int fib(int n){
    if(n == 0)    return 0;
    if(n == 1)    return 1;
    else{
        int fn = (fib(n-1) + fib(n-2)%1000000007;
        return fn;
    } 
} //�ݹ��㷨 
