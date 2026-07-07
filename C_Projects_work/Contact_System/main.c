#include"contact.h"
#include<stdio.h>
void Menu(){
    printf("------------通讯录------------\n");
    printf("请输入1 添加联系人\n");
    printf("请输入2 删除联系人\n");
    printf("请输入3 查询联系人\n");
    printf("请输入4 修改联系人\n");
    printf("请输入5 显示所有联系人\n");
    printf("请输入6 清空通讯录\n");
    printf("请选择操作(1-6)\n");
    printf("-----------------------------\n");
}//菜单结构
int main(){
    //初始化一个头节点dummy;
    Node dummy;
    dummy.next=NULL;
    Node *head=&dummy;
    int choose;
     do{
         Menu();
         scanf("%d",&choose);
         switch(choose){
             case 1:Add(head);break;
             case 2:Delete(head);break;
             case 3:Check(head);break;
             case 4:Change(head);break;
             case 5:Show(head);break;
             case 6:Clear(head);break;
             case 0:printf("0");break;
             default:printf("输入错误,请重新操作:");
         }
     }while(choose!=0);
    return 0;
}