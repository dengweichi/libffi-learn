# libffi_learn
libffi学习测试代码,在wsl的linux上构建libffi。在


下载源代码，在wsl的linux系统下编译成静态库

```ssh
 git clone https://github.com/libffi/libffi.git
 ./configure --prefix=/code/libffi --enable-static --disable-shared
 make
```