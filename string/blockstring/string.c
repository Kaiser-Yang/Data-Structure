#include "string.h"

void initString(blString **s){
    *s = malloc(sizeof(blString));
    (*s)->head = NULL;
    (*s)->tail = NULL;
    (*s)->len = 0;
}
bool assString(blString *s, char *t){
    if (s->len != 0) return false;
    s->len = strlen(t);
    for (int i = 0;i < s->len;i += BLOCKSIZE){
        block *now = malloc(sizeof(block));
        now->len = 0;
        for (int j = 0;j < BLOCKSIZE && j + i < s->len;j ++) now->ch[j] = t[i + j], now->len ++;
        if (s->tail == NULL){
            s->tail = s->head = now;
            now->nex = NULL;
        }
        s->tail->nex = now;
        s->tail = now;
        now->nex = NULL;
    }
    return true;
}
bool insString(blString *s, int pos, char *t){
    if (s->len < pos || pos < 0) return false;
    int p = (pos - 1) / BLOCKSIZE + 1;//p表示是pos这个位置在第几块
    int q = pos - (p - 1) * BLOCKSIZE;//q表示pos在这一块的第几个
    int len = strlen(t), tlen = 0;
    block *cur = s->head, *cur1, *cur2;
    for (int i = 1;i < p;i ++) cur = cur->nex;
    cur1 = cur->nex, cur2 = cur->nex;
    char temp[s->len + BLOCKSIZE];
    for (int i = q;i < cur->len;i ++) temp[tlen ++] = cur->ch[i];
    while(cur1 != NULL){
        if (cur2 != cur1) cur2 = cur1;
        for (int i = 0;i < cur1->len;i ++) temp[tlen ++] = cur1->ch[i];
        cur1 = cur1->nex;
        free(cur2);
    }
    cur->len = 0;
    for (int i = q;i < BLOCKSIZE && i - q < len;i ++) cur->ch[i] = t[i - q], cur->len ++;
    for (int i = cur->len;i < len;i += BLOCKSIZE){
        if (i != cur->len) cur = cur->nex;
        block *now = malloc(sizeof(block));
        now->len = 0;
        for (int j = 0;j < BLOCKSIZE && j + i < len;j ++) now->ch[j] = t[j + i], now->len ++;
        now->nex = cur->nex;
        cur->nex = now;
    }
    int tpos = 0;
    for (int i = cur->len;i < BLOCKSIZE && i - cur->len < tlen;i ++) cur->ch[i] = temp[i - cur->len], tpos ++;
    cur->len += tpos;
    for (int i = tpos;i < tlen;i += BLOCKSIZE){
        if (i != cur->len) cur = cur->nex;
        block *now = malloc(sizeof(block));
        now->len = 0;
        for (int j = 0;j < BLOCKSIZE && j + i < tlen;j ++) now->ch[j] = temp[j + i], now->len ++;
        now->nex = cur->nex;
        cur->nex = now;
    }
    s->tail = cur;
    s->len += len;
    return true;
}
bool delString(blString *s, int pos, int len){
    pos --;
    if (pos < 0 || len <= 0 || pos + len - 1 >= s->len) return false;
    int p = pos / BLOCKSIZE + 1;
    int q = pos + 1 - (p - 1) * BLOCKSIZE;
    char temp[s->len];
    memset(temp, 0, sizeof(temp));
    block *cur = s->head, *cur1;
    for (int i = 1;i < p;i ++) cur = cur->nex;
    int tp;
    for (int i = q;i <cur->len;i ++){
        if (len == 0){
            tp = q;
            break;
        }
        len --;
        cur->len --;
    }
    if (len) cur1 = cur->nex;
    else cur1 = cur;
    while(cur1 != NULL && len){
        if (len - cur1->len <= 0){
            tp = len;
            break;
        }
        len -= cur1->len;
        cur1 = cur1->nex;
    }
    block *cur2 = cur1;
    int tlen = 0;
    while(cur1){
        for (int i = tp;i < cur1->len;i ++) temp[tlen ++] = cur1->ch[i];
        cur1 = cur1->nex;
        if (tp) tp = 0;
    }
    cur1 = cur2;
    while(cur1){
        if (cur2 != cur1) cur2 = cur1;
        cur1 = cur1->nex;
        free(cur2);
    }
    insString(s, pos, temp);
    return true;
}
bool comString(blString *s, blString *t){
    if (s->len != t->len) return false;
    block *cur1 = s->head, *cur2 = t->head;
    while(cur1 != NULL && cur2 != NULL){
        if (cur1->len != cur2->len) return false;
        for (int i = 0;i < cur1->len;i ++) if (cur1->ch[i] != cur2->ch[i]) return false;
    }
    return cur1 == NULL && cur2 == NULL;
}
void preKMP(char *s, int *nex){
    int len = strlen(s);
    int j = -1;
    nex[0] = -1;
    for (int i = 1;i < len;i ++){
        while(j != -1 && s[i] != s[j + 1]) j = nex[j];
        if (s[j + 1] == s[i]) j ++;
        nex[i] = j;
    }
}
int KMP(char *s, char *t){
    int len1 = strlen(s);
    int len2 = strlen(t);
    int nex[len2];
    preKMP(t, nex);
    int j = -1;
    for (int i = 0;i + len2 <= len1;i ++){
        while(j != -1 && s[i] != t[j + 1]) j = nex[j];
        if (s[i] == t[j + 1]) j ++;
        if (j == len2){
            //j = nex[j];
            return i + 1 - len2 + 1;
        }
    }
    return -1;
}
int posString(blString *s, int pos, blString *t){
    pos --;
    if (pos < 0 || pos >= s->len) return -1;
    int p = pos / BLOCKSIZE + 1;
    int q = pos + 1 - (p - 1) * BLOCKSIZE;
    char temp1[s->len], temp2[t->len];
    int len1 = 0, len2 = 0;
    memset(temp1, 0, sizeof(temp1));
    memset(temp2, 0, sizeof(temp2));
    block *cur = s->head;
    for (int i = 1;i < p;i ++) cur = cur->nex;
    for (int i = q;i < cur->len;i ++) temp1[len1 ++] = cur->ch[i];
    cur = cur->nex;
    while(cur != NULL){
        for (int i = 0;i < cur->len;i ++) temp1[len1 ++] = cur->ch[i];
        cur = cur->nex;
    }
    cur = t->head;
    while(cur != NULL){
        for (int i = 0;i < cur->len;i ++) temp2[len2 ++] = cur->ch[i];
        cur = cur->nex;
    }
    return KMP(temp1, temp2);
}