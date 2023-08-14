#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//qsort��ʹ��(qsortĬ���ų�����)
/*void bobble_sort(int arr[],int sz)
{
    int i = 0;  //����
    for (i = 0;i < sz - 1;i++)
    {
        int flag = 1;
        int j = 0;  //��������
        for(j = 0;j < sz-i-1;j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int tmp = 0;
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag = 0;
            }
        }
        if(flag == 1)
        {
            break;
        }
    }
}*/

/*int cmp_int(const void* e1,const void* e2)
{
    if(*(int*)e1 > *(int*)e2)
        return 1;
    else if ((*(int*)e1 == *(int*)e2))
        return 0;
    else
        return -1;
}*/
//�����������Ż�

/*int cmp_int(const void* e1,const void* e2)
{
    return (*(int*)e1 - *(int*)e2);//�ų�����
}*/
struct Stu
{
    char name[20];
    int age;
};
int cmp_int(const void* e1,const void* e2)
{
    return (*(int*)e2 - *(int*)e1);//�ųɽ���
}

int cmp_stu_by_name(const void* e1,const void* e2)
{
    //strcmp()����ֵΪ >0 ==0 <0,�ȽϷ�ʽΪ�����Ƚ��ַ�ASCII���С
    return strcmp(((struct Stu*)e1)->name,((struct Stu*)e2)->name);
}

int cmp_stu_by_age(const void* e1,const void* e2)
{
    //strcmp()����ֵΪ >0 ==0 <0
    return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void test1()
{
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    int sz = sizeof(arr)/sizeof(arr[0]);
    //bobble_sort(arr,sz);

    qsort(arr,sz, sizeof(arr[0]),cmp_int);

    int i = 0;
    for (i = 0;i < sz;i++)
    {
        printf("%d ",arr[i]);
    }
}
void test2()
{
    struct Stu s[] = {{"zhangsan",15},{"lisi",30},{"wangwu",25}};
    int sz = sizeof(s)/sizeof(s[0]);
    qsort(s,sz, sizeof(s[0]),cmp_stu_by_name);
}
int main()
{
    test1(); //�����������
    test2(); //����ʹ��qsort�������ݽṹ
    return 0;
}