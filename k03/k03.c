#include <stdio.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    int text_len;
    int start=0;
    int pos;
    int key_len;

    text_len=StrOriginal://  ここを実装する

    for(start=0;)
        for(pos=0;text[start+pos]==key[pos];pos++){

    }

}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する

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