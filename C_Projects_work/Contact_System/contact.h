#ifndef CONTACT_h//防止出现重复头文件,导致错误
#define CONTACT_h
#define MAX_NAME 20//定义名字最大长度字节
#define MAX_SEX 6//性别
#define MAX_PASS 12//电话号码
#define MAX_ADRESS 100//住址

//联系人数据
typedef struct People{
char name[MAX_NAME];
char sex[MAX_SEX];
char pass[MAX_PASS];
char adress[MAX_ADRESS];
}People;

//链表节点结构
typedef struct  Node{
People date;//联系人数据
struct  Node *next;//指针
}Node;

//基本工具
void CheckName(char*,char*);//检验名字是否匹配成功
void CreatNode(People date);//创建节点
void DeleteNode(Node*cur);//删除节点

//基本功能
void Add(Node*tail);//添加联系人,用尾插法
void Delete(Node*head);//删除联系人
void Check(Node *head);//查找联系人
void Change(Node *head);//修改联系人
void Show(Node*head);//展示所有联系人
void Clear(Node*head);//清空联系人

#endif