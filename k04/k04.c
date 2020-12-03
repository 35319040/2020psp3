#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int id;
    char name[19];  //  市の名前、UTF-8対応
    float members;  //  世帯人員
    int total;      //  食料合計
    int grain;      //  穀類
    int seafood;    //  魚介類
    int meat;       //  肉類
    int milk;       //  乳卵類
    int vegetable;  //  野菜類
    int fruit;      //  果物
    int seasoning;  //  調味料
    int snack;      //  菓子類
    int cocking;    //  調理料理
    int drink;      //  飲料
    int liquor;     //  酒類
    int eatout;     //  外食
} City;

#define DEBUG
#define MAX_CITY    47


void PrintCity(City city)
{
    printf("%d, %s, %.2f, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", 
        city.id, city.name, city.members, city.total, 
        city.grain, city.seafood, city.meat, city.milk, city.vegetable, city.fruit,
        city.seasoning, city.snack, city.cocking, city.drink, city.liquor, city.eatout);
}

void PrintArray(City city[], int size)
{
    int i;

    for (i=0; i<size; i++) {
        PrintCity(city[i]);
    }
}

int LoadData(City arrayCity[])
{
    char buf[256];
    FILE* fp;

    fp = fopen("consumption.csv","r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        return -1;
    }

    int cn = 0; // 市の数
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d,%[^,],%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", 
            &(arrayCity[cn].id), arrayCity[cn].name, &(arrayCity[cn].members), &(arrayCity[cn].total), 
            &(arrayCity[cn].grain),  &(arrayCity[cn].seafood),  &(arrayCity[cn].meat), &(arrayCity[cn].milk), 
            &(arrayCity[cn].vegetable),  &(arrayCity[cn].fruit),  &(arrayCity[cn].seasoning),  &(arrayCity[cn].snack),
            &(arrayCity[cn].cocking),  &(arrayCity[cn].drink),  &(arrayCity[cn].liquor),  &(arrayCity[cn].eatout));
#ifdef DEBUG
        PrintCity(arrayCity[cn]);
#endif
        cn++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        return -1;
    }

    return cn;
}


void BubbleSort(City arrayCity[], int size)
{
    int cnt=0;  //  ここを実装する
    int pos;
    int tmp;

    for(pos=0;pos<size-1;pos++){

        if(arrayCity->total[pos]>arrayCity->total[pos+1]){

            tmp=arrayCity->total[pos];
            arrayCity->total[pos]=arrayCity->total[pos+1];
            arrayCity->total[pos+1]=tmp;

            cnt++;
        }
    }

    if(cnt=0){
        return arrayCity;
    }else{
        BubbleSort(arrayCity->total,size);
    }

}


void QuickSort(City arrayCity[], int left, int right)
{                         
    int i=left; 
    int j=right;
    int pivot=arrayCity->seafood[left];
    int x;
    
    if(>1){

        while(1){
            while(i>pivot){
                i++;
            }

            while(j<=pivot){
                j--;
            }

            if(i>=j){
                break;
            }else{
                x=i;
                i=j;
                j=x;
            }
        }
        x=arrayCity->seafood[left];
        arrayCity->seafood[left]=arrayCity->seafood[j];
        arrayCity->seafood[j]=x;

        QuickSort(arrayCity->seafood, left, j-1);
        QuickSort(arrayCity->seafood, j+1, right);
    }


}



void HeapSort(City arrayCity[], int size)
{
    //  チャレンジ問題(1)
    //  ここを実装する

}


void MergeSort(City arrayCity[], int left, int right)
{
    int mid;//  チャレンジ問題2
    City left_buff[mid-left+1];
    int i,j,k;   //  ここを実装する

    if(left<right){
        mid=left+(right-left)/2;
        MergeSort(arrayCity,left,mid);
        MergeSort(arrayCity,mid+1,right);

        for(i=mid;i>=left;i--){
            left_buff[i]=arrayCity[i];
        }
        for(j=mid+1;j<=right;j++){
            left_buff[right-(j-(mid+1))]=arrayCity[j];
        }
        i=left;
        j=right;
        for(k=left;k<=right;k++){
            if(left_buff[i]<left_buff[j]){
                arrayCity[k]=left_buff[i++];
            }else{
                arrayCity[k]=left_buff[j--];
            }

        }
    }
}

int main(void)
{
 
    //  事前準備。データの読み込み、配列の作成
    City* arrayCity;
    int cn;
    arrayCity = (City*)malloc(sizeof(City) * MAX_CITY);
    cn = LoadData(arrayCity);
    if (cn == -1) {
        exit(EXIT_FAILURE);
    }

    //  食料品合計で並び替え
    printf("===== Sorted by total =====\n");
    BubbleSort(arrayCity, MAX_CITY);
    PrintArray(arrayCity, MAX_CITY);

    //  魚介類で並び替え   
    printf("===== Sorted by seafood =====\n");
    QuickSort(arrayCity, 0, MAX_CITY - 1);
    PrintArray(arrayCity, MAX_CITY);
   
//    MergeSort(arrayCity, 0, MAX_CITY - 1);
//    HeapSort(arrayCity, MAX_CITY);
    PrintArray(arrayCity, MAX_CITY);



    //  後処理
    free(arrayCity);

    return 0;
}