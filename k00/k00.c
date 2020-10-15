#include <stdio.h>
 
typedef struct syPerson{
    char name[21];
    int birthday;
    int age;
}Person;

int main(void){

    int your_size=5;

    printf("your size=%d,actual size=%d\n",your_size,sizeof(Person));
    
}