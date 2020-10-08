# 課題1 レポート
学籍番号　bb35319040 氏名   藤井英梨花


## 課題
長崎県にある市町村別人口データを読み込み、IDを用いて検索し、該当する市町村名、人口を出力するプログラムを作成する。

1. 使用するデータ
長崎県の人口データは、nagasaki.csvに保存されている。
nagasaki.csvには、csv形式で以下のデータが含まれる
    - ID
    - 県名
    - 市町村名
    - 人口
    - 男性人口
    - 女性人口

    長崎県の市町村別人口データは、下記に構造体の配列に読み込まれる。

```C: 市町村別データ構造体
typedef struct {  
    int id;  
    char pref[13];  // UTF-8対応  
    char name[19];  // UTF-8対応  
    int population;  
    int m_population;  
    int f_population;  
} City;  
```



2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。  
   (1) LinearSearch：IDをキーとし、リニアサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity: 検索対象の都市別人口データ(配列)
    - int size: データの数  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。

    (2) BinarySearch: IDをキーとし、バイナリサーチで市町村を検索する。  
    [入力]
    - int key: 検索する市町村のID
    - City arrayCity: 検索対象の都市別人口データ(配列)
    - int left: バイナリサーチを行う配列のindex(左端)
    - int right: バイナリサーチを行う配列のindex(右端)  

    [出力]  
    - return値: IDが合致した配列データのindex。IDが一致するデータがない場合は-1。


3. 補助関数
以下の関数はすでに実装されており、利用することができる。  
- PrintCity: 特定の市町村別人口データを出力する  
- PrintArray: 市町村別人口データをすべて出力する  
- LoadData: 市町村別人口データを読み込み、City型の配列に格納する  
- main: メイン関数。データをロードし、リニアサーチ、バイナリサーチを呼び出す  


## ソースコードの説明
リニアサーチ
はじめresultを-1にして、配列を先頭にした。(pos=o)
keyとidを一つずつ比較していく。
posの値が配列のサイズより大きくなるまで続け、途中でkeyとidが一致すれば、そのときの  posを返し、なければ-1を返す。

バイナリサーチ
リストが順番に並んでいることを確認する。
posをリストの真ん中に設定する。
keyとidを比較。
一致->そのときのposを返す
keyのほうが大きい->リストの範囲を変える(pos+1<x<right)
keyのほうが小さい->リストの範囲を変える(left<x<pos-1)
right-left>=0になるまで続ける。


## 出力結果

```
===== linear search =====
City ID?42307
42307, 長崎県, 長与町, 42548, 20090, 22458

===== binary search =====
City ID?42391
42391, 長崎県, 佐々町, 13626, 6426, 7200

===== linear search =====
City ID?11111111111
city was not found

===== binary search =====
City ID?1111111111111
city was not found

```



## 修正履歴

