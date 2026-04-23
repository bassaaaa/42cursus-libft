*This project has been created as part of the 42 curriculum by tsito.*

# libft

## Description

**libft** は 42cursus の最初のプロジェクトであり、以降のすべてのプロジェクトで利用する自作C言語静的ライブラリ `libft.a` を作成する課題である。

### Mandatory part

| 項目 | 内容 |
|------|------|
| **Program Name** | `libft.a` |
| **Files to Submit** | `Makefile`, `libft.h`, `ft_*.c` |
| **Makefile** | `NAME`, `all`, `clean`, `fclean`, `re` |
| **External Functions** | 各関数ごとに個別に許可（詳細は後述） |
| **Libft authorized** | n/a（libft 自身の課題のため） |
| **Description** | 自分自身のライブラリを作成する：以降のカリキュラムで役立つ関数群のコレクション |

### 技術的要件（Technical considerations）

subject の IV.1 で定められた制約事項。

- グローバル変数の宣言は厳格に禁止
- 補助関数は`static`で同一ファイル内に閉じる
- 全ファイルをリポジトリのルートに配置
- 未使用ファイルの提出は禁止
- 全`.c`ファイルが`-Wall -Wextra -Werror`で通る
- `ar`コマンドでアーカイブを作成（`libtool`禁止）
- `libft.a`はリポジトリのルートに生成

## Instructions

### 必要環境

- C コンパイラ（`cc` または `gcc`）
- GNU Make
- 動作確認環境: macOS / Linux

### コンパイル

リポジトリのルートで以下を実行すると、静的ライブラリ `libft.a` が生成される。

```bash
make
```

その他のターゲット:

| ターゲット | 動作 |
|-----------|------|
| `make` / `make all` | `libft.a` をビルド |
| `make clean` | オブジェクトファイル（`.out/`）を削除 |
| `make fclean` | `libft.a` とオブジェクトファイルを削除 |
| `make re` | `fclean` 後に再ビルド |

### 自分のプロジェクトから使う

自作プログラムとリンクする場合は、`libft.h` をインクルードし、`libft.a` をリンクする：

```bash
cc -Wall -Wextra -Werror -I/path/to/libft -c main.c -o main.o
cc main.o -L/path/to/libft -lft -o my_program
```

ソースコード内での利用例:

```c
#include "libft.h"

int main(void)
{
   // sample 
    return (0);
}
```

## ライブラリの詳細

`libft.a` が提供する関数は、大きく 5 つのカテゴリに分類される。

### 1. Part 1 — libc 関数の再実装

`<ctype.h>`, `<string.h>`, `<stdlib.h>` に含まれる関数群を再実装する。

| 関数 | 機能 |
|------|------|
| `ft_isalpha` | 英字判定 |
| `ft_isdigit` | 数字判定 |
| `ft_isalnum` | 英数字判定 |
| `ft_isascii` | ASCII範囲判定 |
| `ft_isprint` | 印字可能文字判定 |
| `ft_toupper` | 小文字 → 大文字変換 |
| `ft_tolower` | 大文字 → 小文字変換 |
| `ft_strlen` | 文字列長を返す |
| `ft_memset` | メモリブロックを指定値で埋める |
| `ft_bzero` | メモリブロックをゼロクリア |
| `ft_memcpy` | メモリブロックをコピー（領域の重複不可） |
| `ft_memmove` | メモリブロックをコピー（領域の重複可） |
| `ft_memchr` | メモリ内から特定バイトを探索 |
| `ft_memcmp` | メモリブロックを比較 |
| `ft_strlcpy` | 文字列をサイズ制限付きでコピー |
| `ft_strlcat` | 文字列をサイズ制限付きで連結 |
| `ft_strchr` | 文字列内から文字を前方探索 |
| `ft_strrchr` | 文字列内から文字を後方探索 |
| `ft_strncmp` | 文字列をサイズ制限付きで比較 |
| `ft_strnstr` | 文字列内から部分文字列を探索 |
| `ft_atoi` | 文字列を `int` に変換（標準 `atoi` 互換） |
| `ft_calloc` | ゼロクリアされた領域を動的確保 |
| `ft_strdup` | 文字列を複製（`malloc` で領域確保） |

### 2. Part 2 — 追加ユーティリティ関数

libc には存在しない、または類似品が存在しない便利関数群。

| 関数 | 機能 |
|------|------|
| `ft_substr` | 部分文字列を切り出して新規確保 |
| `ft_strjoin` | 2つの文字列を連結した新文字列を確保 |
| `ft_strtrim` | 先頭・末尾から指定文字集合を除去 |
| `ft_split` | 区切り文字で文字列を分割し `char **` を返す |
| `ft_itoa` | `int` を文字列に変換（`INT_MIN` 対応） |
| `ft_strmapi` | 各文字に関数を適用して新文字列を生成（インデックス付き） |
| `ft_striteri` | 各文字に関数を適用してインプレース変更（インデックス付き） |
| `ft_putchar_fd` | 文字を指定 fd に出力 |
| `ft_putstr_fd` | 文字列を指定 fd に出力 |
| `ft_putendl_fd` | 文字列 + 改行を指定 fd に出力 |
| `ft_putnbr_fd` | 整数を指定 fd に出力 |

### 3. Bonus — 連結リスト操作関数

片方向連結リストのノード構造体 `t_list` と、それを操作する関数群を提供する。

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

| 関数 | 機能 |
|------|------|
| `ft_lstnew` | 新規ノードを生成 |
| `ft_lstadd_front` | リスト先頭にノードを追加 |
| `ft_lstadd_back` | リスト末尾にノードを追加 |
| `ft_lstsize` | リストのノード数を返す |
| `ft_lstlast` | リストの末尾ノードを返す |
| `ft_lstdelone` | 単一ノードの content を解放して削除 |
| `ft_lstclear` | リスト全体を解放 |
| `ft_lstiter` | 各ノードの content に関数を適用 |
| `ft_lstmap` | 各ノードの content に関数を適用して新リストを生成 |

### 4. ヘッダファイル

すべての関数プロトタイプ、`t_list` 構造体、必要なマクロは `libft.h` に集約されている。利用側は `#include "libft.h"` するだけで全機能にアクセスできる。

## Resources

### 公式ドキュメント・リファレンス

- [Linux man-pages](https://man7.org/linux/man-pages/) — `man 3 strlen` など、各関数の正確な仕様の一次情報
- [cppreference.com](https://en.cppreference.com/w/c) — C標準ライブラリのリファレンス（特に戻り値や境界値の確認に有用）
- [The GNU C Library Reference Manual](https://www.gnu.org/software/libc/manual/) — glibc の挙動と設計思想
- [C99 / C11 標準規格ドラフト (ISO/IEC 9899)](https://www.open-std.org/jtc1/sc22/wg14/) — 未定義動作（UB）・処理系定義動作の確認

### 42 関連資料

- [42 Norme](https://github.com/42School/norminette) — `norminette` による Norm 準拠チェック
- [42-Bern/libftest](https://github.com/alelievr/libft-unit-test) — libft 単体テスト用の定番ツール
- [Tripouille/libftTester](https://github.com/Tripouille/libftTester) — 境界値・メモリリーク検査に強いテスター
- 本プロジェクトでは `libft-tester-tokyo` も併用（リポジトリに同梱）

### 参考記事

- [42 libft 攻略記事（Qiita, Zenn 等）](https://zenn.dev/) — `ft_split` のメモリ解放、`ft_itoa` の `INT_MIN` 対応などハマりどころの確認
- Andrew Koenig『C Traps and Pitfalls』— ポインタと配列の落とし穴に関する古典
- Brian W. Kernighan, Dennis M. Ritchie 『The C Programming Language (K&R)』— 第5章ポインタ・第7章入出力の基礎固め

### AI の活用について

本プロジェクトでは Claude (Anthropic) を以下の用途で活用した：

| 用途 | 対象部分 |
|------|---------|
| **コードレビュー** | 実装後の Norm 違反チェック、未定義動作（UB）の検出、境界値ケースの洗い出し |
| **設計相談** | `ft_atoi` のオーバーフロー処理方針（saturation vs truncation）、`ft_strtol` 補助関数の導入判断 |
| **仕様確認** | man page と標準 `atoi` / `strtol` の挙動差分の確認（`LONG_MAX` saturate + `int` truncate など） |
| **テストケース生成** | `INT_MIN`・20桁オーバーフロー・連続符号・空白文字全種などのエッジケース洗い出し |
| **採点シミュレーション** | peer eval / Moulinette で指摘されうるポイントの事前検証 |

AI は**コードを書くためではなく、自分が書いたコードの品質を検証・議論するパートナー**として利用した。すべての実装は man page と 42 subject の要件を一次情報として自分の手で書き、AI の提案はあくまで参考意見として受け止めた上で採否を判断している。

その結果、単に「動く」だけでなく「なぜこの実装なのか」を peer eval の場で自分の言葉で説明できる状態に仕上げることを目指した。
