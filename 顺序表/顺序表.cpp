// 顺序表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100 //顺序表最大存储空间
#define ERROR 0
#define OK 1


typedef int ElemType; //顺序表存储的元素类型
typedef struct SqList{ //定义顺序表类型
    ElemType elem[MAXSIZE];  //定义ElemType类型数据
    int length;  //顺序表当前长度
};

SqList* CreatList() {
    //代码中使用了动态内存分配函数`malloc`来给L申请了一段内存空间
    //函数原型如下：void* malloc(size_t size);

    SqList* L;
    
    //将申请的内存空间转换为SqList指针
    L = (SqList* )malloc(sizeof(SqList)); //申请存储顺序表的空间
    if (!L)
        return NULL;
    else {
        //申请成功，初始化长度为0
        L->length = 0; 
        return L;
    }
}

//为空表进行赋值
void AssignSqList(SqList* L) {
    printf("请为空表赋初值：\n（1）输入元素个数：");
    scanf_s("%d", &L->length);
    printf("（2）按照元素个数依次输入元素值（各元素以空格隔开）：");
    for (int i = 0; i < L->length; i++)
    {
        scanf_s("%d", &L->elem[i]);
    }
}

//顺序表的输出
void OutputSqList(SqList* L) {
    printf("顺序表的长度是%d\n", L->length);
    printf("顺序表元素依次是：");
    for (int i = 0; i < L->length; i++)
    {
        printf("%4d", L->elem[i]);
    }
    printf("\n");
}

int InsertSqList(SqList* L, int index, ElemType elem) {
    if (index <1 || index > L->length+1)
    {
        //插入的位置不能小于1也不能大于（现有长度 加 预留位置）
        return ERROR;
    }
    if (L->length>=MAXSIZE)
    {
        printf("线性表溢出！\n");
        return ERROR;
    }
    for (int i = L->length-1; i < i>=index-1; --i)
    {

    }
}

//int main()
//{
//    //建立顺序表
//    SqList* L = CreatList();
//    if (L == NULL) printf("初始化顺序表失败！\n");
//    else printf("初始化顺序表成功！申请的堆内存为%d\n", sizeof(L));
//    AssignSqList(L);
//    OutputSqList(L);
//}
