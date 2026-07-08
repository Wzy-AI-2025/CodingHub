C语言链表通讯录管理系统

项目开发目的:
 
本项目为学习实践项目，用于练习C语言指针、单向链表、模块化编程与文件读写,主要验证所学
 
基础信息
 
1.开发语言：标准C语言
2.编译环境：VS2022/MinGW GCC
3.数据存储：通过contacts.txt实现数据持久化读写
4.工程架构：三文件模块化开发（contact.h/contact.c/main.c）
 
项目目录结构
plaintext
ContactSystem/
├── main.c        // 程序入口、菜单、功能调度
├── contact.c     // 链表操作与文件读写实现
├── contact.h     // 宏定义、结构体、函数声明
└── contacts.txt  // 自动生成的数据存储文件
 
 
数据结构
1. 联系人信息结构体
typedef struct People{
    char name[20];
    char sex[6];
    char pass[12];
    char adress[100];
} People;
 
 
2.链表节点（采用带头虚拟头结点设计）
typedef struct Node{
    People date;
    struct Node *next;
} Node;
 
核心功能
通讯录基础操作
1.添加联系人：头插法存入链表，自动校验重名，修改后自动保存文件
2.删除联系人：按姓名查找节点，断开链表并释放内存
3.精准查询：根据姓名检索并展示联系人信息
4.修改信息：单独修改联系人任意一项资料
5.全部展示：遍历链表打印所有联系人
6.清空通讯录：循环释放全部节点内存
 
持久化功能
1.SaveToFile每次数据改动后自动保存到文本文件
2.LoadFromFile程序启动时自动读取本地历史数据
 
核心技术要点
1.虚拟头结点统一链表增删逻辑，无需单独处理边界情况
2.使用malloc/free手动管理堆内存，避免内存泄漏
3.严格分离头文件声明与源文件实现，工程结构规范
4.文本文件实现数据永久保存，重启程序数据不丢失
 
项目现存限制
1.由于这个项目是以练习为目的,没有对输入严格要求,进行校验
 
编译运行方式
vscode,VS2022
1.vscode编写代码文件
2.vs创建空C++项目，导入全部代码文件
3.预处理器定义添加 _CRT_SECURE_NO_WARNINGS 
4.字符集改为多字符集
3.设置编译为C代码（/TC）后运行
GCC终端编译
bash
gcc main.c contact.c -o contact.exe
./contact.exe
