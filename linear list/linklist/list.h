#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

#define elemType int
#define NL puts("");

typedef struct _linkList{
    elemType data;
    struct _linkList *nex;
}node, *linkList;

typedef void (*CALLBACK)(elemType*);

extern void initList(linkList *L);//初始化单链表
extern int delXtoY(linkList L, elemType x, elemType y);//删除位于x和y之间的元素， 要求元素非递减
extern bool insElem(linkList L, int i, elemType e);//在i（从1开始）位置插入e这个元素
extern void traverse(linkList L, CALLBACK f);//遍历链表
extern bool delElem(linkList L, int i, elemType *e);//删除第i（从1开始）位置的元素
extern bool destroyList(linkList *L);//释放链表
extern int locateElem(linkList L, elemType e);//返回e第一次出现的位置， 没有则为-1
extern int getElem(linkList L, int i);//返回i这个位置的元素， 如果没有则返回-1
extern void mergeLink(linkList A, linkList B, linkList C);//本质与归并排序的merge相同
extern void sortLink(linkList L);//用冒泡排序对L从小到大排序
extern int lenLink(linkList L);//返回L的长度