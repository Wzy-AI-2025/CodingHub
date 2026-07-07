#include "contact.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node* CheckName(char* target, Node* head) {
    Node*cur=head->next;
    while(cur!=NULL){
     if(strcmp(cur->date.name,target)==0)return cur;
     cur=cur->next;
    }
    return NULL;//未找到
}

void CreatNode(People date,Node*head){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->date=date;
    Node*cur=head->next;
    head->next=newNode;
    newNode->next=cur;//使用头插法插入节点
}

void DeleteNode(Node*target,Node*head) {
    Node*cur=head;
    while(cur->next!=target) {
        cur=cur->next;
    }//找到要删除节点的前一个节点
    cur->next=target->next;
    free(target);//释放删除节点的内存
}

void Add(Node*head) {
    People p;
    printf("请输入姓名:\n");
    scanf("%19s",p.name);
    while (CheckName(p.name,head) != NULL) {
        printf("姓名重复!请重新输入:\n");
        scanf("%19s",p.name);
    }
    printf("请输入性别:\n");
    scanf("%3s",p.sex);
    printf("请输入电话号码:\n");
    scanf("%10s",p.pass);
    printf("请输入地址:\n");
    scanf("%99s",p.adress);
    CreatNode(p,head);
    printf("添加成功!!!\n");
}

void Delete(Node*head) {
    printf("请输入要删除的联系人的姓名:\n");
    char name[20];
    scanf("%19s",name);
    Node* cur=CheckName(name,head);
    if(cur==NULL) {
      printf("该用户不在通讯录中\n");
      return;
    }
    else{
      DeleteNode(cur,head);
    }
    printf("删除成功!!!\n");
}

void Check(Node* head){
    printf("请输入要查询的姓名:\n");
    char name[20];
    scanf("%19s",name);
    Node* cur=CheckName(name,head);
    if(cur==NULL){
        printf("查询的人不存在于通讯录中!!!\n");
        return;
    }
    printf("姓名:%s,性别:%s,电话号码:%s,家庭住址:%s\n",cur->date.name,cur->date.sex,cur->date.pass,cur->date.adress);
}

void Change(Node* head) {
    printf("请输入需要修改的联系人的姓名:\n");
    char name[20];
    scanf("%19s",name);
    Node* cur=CheckName(name, head);
    if(cur==NULL) {
        printf("未找到指定联系人的信息!!!\n");
        return;
    }
    int chose;
    do {
        printf("请选择要修改的项(1-5)分别对应姓名,性别,电话号码,住址,退出:\n");
        scanf("%d",&chose);
        switch (chose) {
        case 1:
            printf("姓名修改为:\n");
            scanf("%19s",cur->date.name);
            break;
        case 2:
            printf("性别修改为:\n");
            scanf("%3s",cur->date.sex);
            break;
        case 3:
            printf("电话号码修改为:\n");
            scanf("%10s",cur->date.pass);
            break;
        case 4:
            printf("住址修改为:\n");
            scanf("%99s",cur->date.adress);
            break;
        case 5:
            printf("退出修改!\n");
            break;
        default:
            printf("输入错误!!!\n");
        }
    }while(chose!= 5);
}

void Show(Node* head) {
    Node* cur=head->next;
    while(cur!=NULL) {
        printf("姓名:%s,性别:%s,电话号码:%s,住址:%s\n",cur->date.name,cur->date.sex,cur->date.pass,cur->date.adress);
        cur=cur->next;
    }
}

void Clear(Node* head) {
    Node* cur=head->next;
    while(cur!=NULL) {
        Node* next=cur;
        cur=cur->next;
        DeleteNode(next,head);
    }
}