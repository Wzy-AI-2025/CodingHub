
#include<stdio.h>
void Menu(){
    printf("------------通讯录------------\n");
    printf("操作1 增加联系人\n");
    printf("操作2 删除联系人\n");
    printf("操作3 查找联系人\n");
    printf("操作4 修改联系人\n");
    printf("操作5 显示所有联系人\n");
    printf("操作6 清空通讯录\n");
    printf("请选择操作(1-6)\n");
    printf("-----------------------------\n");
}//菜单结构
int main(){
    //后面记得创建虚拟头节点dummy
    int choose;
    do{
        Menu();
        scanf("%d",&choose);
        switch(choose){
            case 1:printf("1");break;
            case 2:printf("2");break;
            case 3:printf("3");break;
            case 4:printf("4");break;
            case 5:printf("5");break;
            case 6:printf("6");break;
            case 0:printf("0");break;
            default:printf("操作错误,请重新操作:");
        }
    }while(choose!=0);
    return 0;
}