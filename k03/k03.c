#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    int text_len=0;
    int start;
    int pos;
    int key_len=0;
    int i,j;


    for(i=0;text[i]!=NULL;i++){
   
    text_len=text_len+1;//  ここを実装する

    }

    for(j=0;key[j]!=NULL;j++){

        key_len=key_len+1;
    }

    for(start=0;text_len-key_len>=start;start++){
        for(pos=0;pos<key_len;pos++){

            if(text[start+pos]==key[pos]){

                if((key_len-1)==pos){
                    
                    return text+start;
                }

            }else{
                break;
            }
        

        }
       
    }
     return NULL;
}

char* BMSearch(char text[], char key[])
{
    int index;
    int text_len=0;
    int key_index;
    int key_len=0;
    int i; 
    char table[256];   //  ここを実装する
    int new_index;

    for(i=0;text[i]!=NULL;i++){
        text_len=text_len+1;  //textの長さを調べる
    }

    for(i=0;key[i]!=NULL;i++){
        key_len=key_len+1;  //keyの長さを調べる
    }

    for(i=0;i<256;i++){
        table[i]=key_len; //全部４にした
    } 

    
    for(i=0;i<key_len;i++){
        table[key[i]]=key_len-1-i; //ずらし量テーブルを作成する
    }


    for(index=0;text_len-key_len>=index; ){  
        printf("%s\n",text);
        for(i=0;i<index;i++){
            printf(" ");
        } 
        printf("%s\n",key);
        for(key_index=key_len-1;key_index>=0;key_index--){
            if(text[index+key_index]==key[key_index]){
                if(key_index==0){
                    return text+index;  //見つかった場合
                }
            }else{
                    break;
            }
        }

        new_index=index+key_index+table[text[index+key_index]]-key_len+1;
        
        if(new_index<=index){
            index++;
        }else{
            index=new_index;
        }

    }    
    
}








int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}