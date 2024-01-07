#include<stdio.h>
#include<string.h>

void left_move(char *point,int number)//(1)
{
    int length=strlen(point);
    for(int i=0;i<number;i++)
    {
        char tmp=*point;
        for(int j=0;j<length-1;j++)
        {
            *(point+j)=*(point+j+1);
        }
        *(point+length-1)=tmp;
        // printf("%s\n",point);
    }
}

//
//point--the first point of arr that you want to reverse
//width--the number of byte for each element in the arr that you want to reverse
//number--the number of element for the arr you want to reverse
void reverse(void* point,unsigned int width,unsigned int number)
{
    int i,j;
    for(i=0;i<number/2;i++)
    {
        for(j=0;j<width;j++)
        {
            char tmp=*((char*)point+i*width+j);
            *((char*)point+i*width+j)=*((char*)point+(number-1-i)*width+j);
            *((char*)point+(number-1-i)*width+j)=tmp;
        }
    }
}


void left_move1(char *point,int number)
{
    int size=sizeof(*point);
    int length=strlen(point);
    reverse(point,size,number);
    reverse(point+number,size,length-number);
    reverse(point,size,length);
}


int main(int argc, char const *argv[])
{
    char arr[]="abcdefg";
    int arr1[]={1,2,3,4,5,6};
    // left_move(arr,2);//(1)
    // left_move1(arr,2);//(2)
    // printf("%s\n",arr);
    int length=(int*)(&arr1+1)-arr1;
    reverse(arr1,sizeof(*arr1),length);
    for(int i=0;i<length;i++)
    {
        printf("%d\t",arr1[i]);
    }
    return 0;
}
