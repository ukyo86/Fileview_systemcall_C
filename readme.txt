﻿<概要>
OS(Linux,Windows)で、引数にファイル名を指定すると、
そのファイルのサイズとファイルの種類、最終変更時刻を表示できるコマンドの作成を行った。
制約としてopen,fstatシステムコールを用いて実装する。

------------------------------------------------------------------------

<必要ファイル>

fview.c     引数にファイル、フォルダを指定すると、ファイルの種類、サイズ、最終変更時刻を表示するプログラム
sample1.txt 任意のテキストファイルを用意
sample2.txt

-------------------------------------------------------------------------

コンパイル方法
gcc fview.c -o fview

実行方法 (.txtファイルを引数にする)
.//fview a.txt b.txt c.txt 

--------------------------------------------------------------------------

<結果1.PNG,結果2.PNG>
プログラムの実行結果を示している。ファイルを複数指定できる。
いずれもファイルサイズ、種類、最終変更時刻を表示している。

--------------------------------------------------------------------------