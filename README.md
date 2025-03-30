# X68000 クロス開発テンプレート

[elf2x68k](https://github.com/yunkya2/elf2x68k) + MinGW64 でクロス開発を行うためのテンプレートです。個人用なのでノークレームで。

## makefile について

- `make` : ビルド
- `make clean` : クリーン
- `make veryclean` : クリーン + `dist` ディレクトリ削除
- `make release` : リリースビルド。 `dist` ディレクトリに配布モジュールを作る。 `README.md` から `README.txt` を生成するために [Pandoc](https://pandoc.org/) が必要
- `make bump-version` : `makefile` を書き換えてバージョンを上げる

## VS Code 向け情報

- Windows エクスプローラーから起動せず、 MinGW64 のターミナルから `code` コマンドで起動するといい (MinGW64 の環境変数が引き継がれ、ツールチェイン等にパスが通る)
- 推奨する拡張機能
  - [Makefile Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.makefile-tools)
- `/.vscode/launch.json`
  - [gdbserver-x68k](https://github.com/yunkya2/gdbserver-x68k) の設定あり
