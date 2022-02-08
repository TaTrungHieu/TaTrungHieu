#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct shop
{
    int so_hieu;
    int so_luong_hang_hoa;
    char hang_hoa[100];
}shop;
int so_luong;
shop dsach[100];
void menu()
{
    printf("\nBan hay nhap chuc nang can thuc hien\n");
    printf("1. Xac dinh cac mon hang trong cua hang\n");
    printf("2. Xoa di cac mon hang cua mot cua hang\n");
    printf("3. Them mot cua hang va cac mon hang trong do\n");
    printf("4. Tinh toan chi phi di lai\n");
    printf("5. Thoat\n");
}
void load()
{
    FILE* f=fopen("input.txt","r");
    fscanf(f,"%d",&so_luong);
    char st[256];
    for (int i=0;i<so_luong;i++)
    {
        fscanf(f,"%d\t%s",&dsach[i].so_hieu,st);
        int len=strlen(st);
        int cs=0;
        for (int j=0;j<len;j++)
            if (st[j]!=',')
            {
                dsach[i].hang_hoa[cs]=st[j];
                cs++;
            }
        dsach[i].so_luong_hang_hoa=strlen(dsach[i].hang_hoa);
        
        for (int j=0;j<so_luong;j++)
        for (int j=0;j<dsach[i].so_luong_hang_hoa-1;j++)
            for (int k=j+1;k<dsach[i].so_luong_hang_hoa;k++)
                if (dsach[i].hang_hoa[j]>dsach[i].hang_hoa[k])
                {
                    char tmp=dsach[i].hang_hoa[j];
                    dsach[i].hang_hoa[j]=dsach[i].hang_hoa[k];
                    dsach[i].hang_hoa[k]=tmp;
                }
        printf("%s\n",st);
        strcpy(st,"");
    }
    fclose(f);    
}
int find(int sohieu)
{
    for (int i=0;i<so_luong;i++)
        if (dsach[i].so_hieu==sohieu) return i;
    return -1;
}
void process1()
{
    int stt;
    printf("Nhap so hieu cua hang: ");
    scanf("%d",&stt);
    int cs=find(stt);
    if (cs==-1)
    {
        printf("Khong tim thay cua hang.\n");
        return;
    }
    else 
    {
        for (int i=0;i<dsach[cs].so_luong_hang_hoa;i++)
        {
            printf("%c ",dsach[cs].hang_hoa[i]);
        }
    }
}
void process2()
{
    int sohieu;
    printf("Nhap ten cua hang: ");
    scanf("%d",&sohieu);
    while (find(sohieu)==-1)
    {
        printf("Nhap sai.\n");
        fflush(stdin);
        printf("Nhap ten cua hang: ");
        scanf("%d",&sohieu);
    } 
    char hang;
    sohieu=find(sohieu);
    printf("Nhap hang muon xoa: ");
    scanf("%c",&hang);
    if (hang=='q'||hang=='Q') return;
    for (int i=0;i<dsach[sohieu].so_luong_hang_hoa;i++)
        if (hang==dsach[sohieu].hang_hoa[i]) 
            for (int j=i+1;j<dsach[sohieu].so_luong_hang_hoa;j++)
                dsach[sohieu].hang_hoa[j-1]=dsach[sohieu].hang_hoa[j]; 
}
int main()
{
    load();
    while(1)
    {
        menu();
        printf("Thuc hien chuc nang: ");
        char cmd;
        scanf("%d",&cmd);
        while (cmd<1||cmd>5) 
        {
            printf("Yeu cau nhap lai chuc nang.\n");
            printf("Thuc hien chuc nang: ");
            fflush(stdin);
            scanf("%d",&cmd);
        }
        switch(cmd)
        {
            case 1: process1();break;
            case 2: process2();break;
            case 3: break;
            case 4: break;
            case 5: printf("Ket thuc chuong trinh.\n");return 0;
        }
    }
}
