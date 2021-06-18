# libffi_learn
libffi学习测试代码,在wsl的linux上构建libffi。在


下载源代码，在wsl的linux系统下编译成静态库

```ssh
 git clone https://github.com/libffi/libffi.git
 // 构建release版本的静态库
 ./configure --prefix=/code/libffi --enable-static --disable-shared
 // 构建debug版本的静态库
  ./configure --prefix=/code/libffi --enable-static --disable-shared --enable-purify-safety --enable-debug 
 make
```
