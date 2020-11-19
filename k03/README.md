# 課題3 レポート
学生番号　氏名


## 課題  

以下の2つのアルゴリズムで文字列を検索するプログラムを作成する。  
- 力ずく法
- BM法

1. 使用するデータ  
以下のデータを使用する。ただし、検索対象文字列、検索する文字列は変更しても良い。  
    - StrOriginal: 検索対象データ
    - StrKey: 検索する文字列

2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。C言語の標準ライブラリは使用しないこと。  
    (1) ForceSearch: 力ずく法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  

    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

    (2) BMSearch: BM法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  
 
    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

3. 補助関数  
なし

## ソースコードの説明
力ずく法->text_len,key_lenの文字数を数える。(l9-28)
比較開始位置(start)を探索文字列の先頭、比較場所をキーの先頭にする。探索対象文字列(start+pos)とキーのインデックス(pos)を比較する。一致すれば、文字列を発見、不一致なら比較開始位置(start)を右に1つずらし、比較場所(pos)も先頭(0)にする。比較位置をずらせなくなったら終了。これをfor文で繰り返す。(30-49)

BM法->text_len,key_lenの文字数を数える。(61-67)
不一致となった場合、文字毎にどれだけずらすか計算をする。(69-76)
最初の比較場所をキー文字列の末尾にする。キー文字列の末尾から前に向かって文字列を比較する。一致した場合は、次の文字列を比較する。不一致の場合 は、文字毎に決められた量だけ、比較の開始点をずらす。比較位置が前に戻ってしまう場合は、比較開始点を前回より、1つだけ右にずらす。ずらした後にまた末尾から比較をする。キー文字列がすべて一致すれば、見つかりポインタを返し、比較位置が探索文字列の最後を超えてしまえば見つからないのでNULLを返す。(79-103)


## 出力結果

```

Force Search. Find keyword at:wind in my hair.
On a dark deseart highway, cool wind in my hair.
wind
index=0,key_index=3,text[index+key_index]=97,key_len=4,new_index=4
On a dark deseart highway, cool wind in my hair.
    wind
index=4,key_index=3,text[index+key_index]=114,key_len=4,new_index=8
On a dark deseart highway, cool wind in my hair.
        wind
index=8,key_index=3,text[index+key_index]=101,key_len=4,new_index=12
On a dark deseart highway, cool wind in my hair.
            wind
index=12,key_index=3,text[index+key_index]=114,key_len=4,new_index=16
On a dark deseart highway, cool wind in my hair.
                wind
index=16,key_index=3,text[index+key_index]=105,key_len=4,new_index=18
On a dark deseart highway, cool wind in my hair.
                  wind
index=18,key_index=3,text[index+key_index]=104,key_len=4,new_index=22
On a dark deseart highway, cool wind in my hair.
                      wind
index=22,key_index=3,text[index+key_index]=44,key_len=4,new_index=26
On a dark deseart highway, cool wind in my hair.
                          wind
index=26,key_index=3,text[index+key_index]=111,key_len=4,new_index=30
On a dark deseart highway, cool wind in my hair.
                              wind
index=30,key_index=3,text[index+key_index]=105,key_len=4,new_index=32
On a dark deseart highway, cool wind in my hair.
                                wind
BM Search. Find keyword at:wind in my hair.

```

## 修正履歴

