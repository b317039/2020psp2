# 課題4 レポート

bb35317039  松崎　智久

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明

l.27: データファイル名を入力させ，fnameに格納

l.28: 入力させた文字列の最後にエンターキーが入っているので，fnameの文字列の最後をヌル文字'\0'に置換

l.29: fnameを確認

l.30: fnameで指定したファイルの先頭アドレスをファイルポインタ fp に読み込む

l.31: もしfpがNULLだったときは，ファイルを開けなかったので，即座にプログラム終了

l.35: ファイルを1行ずつbufに読み込む．もし読み込み成功する限り以下を繰り返す

l.36: bufからsscanfで数値文字列を実数としてgenderとheightsに読み込む

1.37:list型配列Dataの引数を表すiを+1する。

1.40：ファイル読み込みに失敗した際にはすぐにプログラムを終了する。

1.45～53：1.27～１．３５と同様の作業を変数IDについて行う

1.55: scanfで検索したいIDを変数IDに読み込む

1.57:bufからsscanfで数値文字列を実数としてID2に読み込む

1.58：入力したIDとID2が合っているかを調べもしもあっていたらflagを立ててID2の読み込みを終了する。

1.62：そうでなければデータの順番を表すnを+1する。

1.66：flagがたっていなければNODATAと表示する。

1.70：そうでなければ該当するデータの性別、身長、IDを出力

1.86：ファイルを閉じる．閉じれないときは，即座にプログラム終了


## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```

## 修正履歴

[comment "20200506]
- 入出力結果は想定通りで問題ないですが，せっかくなので，ID，gender, heightをメンバーとする構造体配列を作って，その配列を探索して結果を表示するようにしてください．
