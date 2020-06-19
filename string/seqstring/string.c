#include "string.h"

void initString(string *s, string *t){
    s->len = 0;
    for (int i = 0;i < t->len;i ++) s->ch[s->len ++] = t->ch[i];
}
bool insString(string *s, int pos, string *t){
    pos --;
    if (pos < 0 || pos >s->len) return false;
    if (s->len + t->len <= MAXSIZE){
        for (int i = t->len - 1;i >= 0;i --) s->ch[pos + t->len + i] = s->ch[pos + i];
        for (int i = 0;i < t->len;i ++) s->ch[pos + i] = t->ch[i];
        s->len = s->len + t->len;
    }
    else{
        if (pos + 1 + t->len >= MAXSIZE){
            for (int i = pos;i < MAXSIZE;i ++) s->ch[i] = t->ch[i - pos];
            s->len = MAXSIZE;
        }
        else{
            for (int i = MAXSIZE - 1;i >= pos + t->len;i --) s->ch[i] = s->ch[pos + i - pos - t->len];
            for (int i = 0;i < t->len;i ++) s->ch[pos + i] = t->ch[i];
            s->len = MAXSIZE;
        }
    }
    return true;
}
bool delString(string *s, int pos, int len){
    pos --;
    if (pos < 0 || len < 0 || pos + len - 1 >= s->len) return false;
    s->len -= len;
    for (int i = pos;i < s->len;i ++) s->ch[i] = s->ch[i + len];
    return true;
}
bool comString(string *s, string *t){
    if (s->len != t->len) return false;
    for (int i = 0;i < s->len;i ++) if (s->ch[i] != t->ch[i]) return false;
    return true;
}
int posString(string *s, int pos, string *t){// brute force
    pos --;
    if (pos < 0 || pos >= s->len) return -1;
    for (int i = pos;i + t->len - 1 < s->len;i ++){
        bool flag = true;
        for (int j = 0;j < t->len;j ++) if (s->ch[i + j] != t->ch[j]){
            flag = false;
            break;
        }
        if (flag) return i + 1;
    }
    return -1;
}
void preKMP(string *s, int *nex){
    nex[0] = - 1;
    int j = - 1;
    for (int i = 1;i < s->len;i ++){
        while(j != -1 && s->ch[i] != s->ch[j + 1]) j = nex[j];
        if (s->ch[j + 1] == s->ch[i]) j ++;
        nex[i] = j;
    }
}
int KMP(string *s, int pos, string *t){// KMP
    int nex[t->len];
    preKMP(t, nex);
    int j = -1;
    for (int i = pos;i + t->len - 1 < s->len;i ++){
        while(j != -1 && s->ch[i] != t->ch[j + 1]) j = nex[j];
        if (s->ch[i] == t->ch[j + 1]) j ++;
        if (j == t->len - 1){
            //j = nex[j];
            return i + 1 - t->len + 1;
        }
    }
    return -1;
}