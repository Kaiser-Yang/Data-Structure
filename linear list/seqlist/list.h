#pragma once

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define elemType int
#define MAXSIZE 1010

typedef struct _seqList{
    elemType elem[MAXSIZE];
    int last;
}seqList, *listPtr;

typedef void (*CALLBACK)(elemType*);

extern void initList(listPtr *L);//用于初始化顺序表
extern int lenList(listPtr L);//获取顺序表长度
extern void separateList(listPtr L);//将顺序表变换成左边全为奇数， 右边全为偶数
extern int delDepnum(listPtr L);//当线性表是非递减时， 用于删除重复元素， 返回删除元素的个数
extern bool emptyList(listPtr L);//判断顺序表是否为空
extern bool insElem(listPtr L, int i, elemType e);//在i（从1开始）位置插入e元素
extern bool delElem(listPtr L, int i, elemType *e);//删除i（从1开始）位置的元素
extern int locatElem(listPtr L, elemType e);//获取e第一次出现位置（从1开始）没有则返回-1
extern elemType getElem(listPtr L, int i);//获取i（从1开始）的元素
extern int delElemXtoY(listPtr L, elemType x, elemType y);//删除位于x到y之间的元素返回删除元素的个数
extern void traverse(listPtr L, CALLBACK f);//遍历顺序表