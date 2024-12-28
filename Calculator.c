#include<stdio.h>
void add(int a,int b){
printf("sum of two number is %d\n ",a+b);
}
void diff(int a,int b){
printf("Difference between the two numbers is %d\n ",a-b);
}
void mul(int a, int b){
printf("product of two numbers is %d\n ",a*b);
}
void divide(int a ,int b){
printf("Division of two numbers is %d\n ",a/b);
}
void main(){
while(1){
        char op;
    printf("enter the operator + - * / only \n");
    scanf(" %c",&op);
    int a,b;
    printf("enter the a value:\n");
    scanf("%d",&a);
    printf("enter the b value:\n");
    scanf("%d",&b);
    if(op=='+'){
        add(a,b);
    }else if(op=='-'){
    diff(a,b);
    }else if(op=='*'){
        mul(a,b);
    }else if(op=='/'){
    divide(a,b);
    }else{
    printf("invalid option\n");
    }
  }
}
