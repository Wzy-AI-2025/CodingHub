#ifndef CONTACT_h//防止头文件重复包含,避免重复定义
#define CONTACT_h
#define DATA_FILE "contacts.txt"//文件名
#define MAX_NAME 20//姓名最大长度
#define MAX_SEX 6//性别
#define MAX_PASS 12//电话号码
#define MAX_ADRESS 100//住址

//联系人信息结构体定义
typedef struct People{
char name[MAX_NAME];
char sex[MAX_SEX];
char pass[MAX_PASS];
char adress[MAX_ADRESS];
}People;

//链表节点结构体定义
typedef struct  Node{
People date;//联系人信息
struct  Node *next;// 指向下一个节点
}Node;

//相关工具函数
Node* CheckName(char*,Node*head);//根据姓名查找联系人,返回对应节点指针
void CreatNode(People date,Node*head);// 创建新节点
void DeleteNode(Node*target,Node*head);//删除对应节点

// 文件操作
void SaveToFile(Node*head,char*filename);//保存到文件里
void LoadFromFile(Node*head,char*filename);//从文件中读取

//功能函数声明
void Add(Node*head);//添加联系人,使用头插法
void Delete(Node*head);//删除联系人
void Check(Node *head);//查询联系人
void Change(Node *head);//修改联系人信息
void Show(Node*head);//展示所有联系人
void Clear(Node*head);//清空通讯录
#endif