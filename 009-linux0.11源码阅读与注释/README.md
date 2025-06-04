# Linux-0.11

(感谢yuan-xy)原项目地址：[(https://github.com/yuan-xy/Linux-0.11)](https://github.com/yuan-xy/Linux-0.11)

老版本的linux内核源码0.11版本，已经在 modern linux， MacOSX下测试过。

## 1. Build on Linux

### 1.1. Linux Setup

* 一个发布的linux版本，推荐使用debian,ubuntu，mint等。
* 必需的工具: gcc gdb qemu
* 一个linux-0.11磁盘镜像: hdc-0.11.img, 请在<http://www.oldlinux.org,> 或者 <http://mirror.lzu.edu.cn/os/oldlinux.org/,> 下载，并放入根目录.
* 现在这个版本已经支持 Ubuntu 16.04, 愉快的玩耍吧.

### 1.2. hack linux-0.11

```bash
$ make help   // get help
make         // compile
$ make start   // 在qemu中启动
$ make debug   // 用qemu虚拟机和gdb进行调试，需要用 gdb 连接。
```

```gdb
$ gdb tools/system
(gdb) target remote :1234
(gdb) b main
(gdb) c
```

## 2. Build on Mac OS X

### 2.1. Mac OS X Setup

* 安装gcc交叉编译工具和bin utils
* install qemu
* install gdb. 你需要下载gdb的源码进行编译，因为通常情况下gdb不支持网络端口(i386-elf-gdb)。或者你可以使用已经提前编译好的gdb文件(在tools文件夹下).
* linux-0.11 镜像文件: hdc-0.11.img

```bash
$ sudo port install qemu
sudo port install i386-elf-binutils i386-elf-gcc
```

```bash
wget ftp://ftp.gnu.org/gnu/gdb/gdb-7.4.tar.bz2
$ tar -xzvf gdb-7.4.tar.bz2
$ cd gdb-7.4
$ ./configure --target=i386-elf
$ make
```

### 2.2. hack linux-0.11

参考 1.2

## 3. Build on Windows

todo...
