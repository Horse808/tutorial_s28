# 视觉第二课：Ubuntu 安装、配置与基础命令

推荐各位使用双系统共存的方式安装Ubuntu，既可以使用 Windows 下的各种软件~~才不是为了打游戏呢，哼~~，也可以直接体验 Linux 下的开发环境

## 1. 安装 Ubuntu

### 1.1 准备工作
1. 下载 Ubuntu 镜像文件（ISO 格式）。建议选择 Ubuntu 24.04 LTS 等长期支持版本，可以从 [Ubuntu 官网](https://ubuntu.com/download/desktop) 下载
   > 当然更推荐在[清华源](https://mirrors.tuna.tsinghua.edu.cn/ubuntu-releases/)或者[杭电源](https://mirrors.hdu.edu.cn/ubuntu-releases/) ~~没想到吧小小泥电也有源~~ 下载。

2. 制作启动 U 盘。可以使用 Rufus（Windows）或 Etcher 将 ISO 写入 U 盘；该过程会清空 U 盘中的数据
3. 备份数据。安装或手动分区时如果选择错误磁盘，可能造成数据丢失；重要文件不要只保存在电脑本地
4. 预留磁盘空间：在 Windows 的“磁盘管理”中压缩现有分区，为 Ubuntu 留出至少 30GB 的**未分配空间**。不要提前在 Windows 中格式化这块空间
   > 右键“开始”菜单 -> “磁盘管理” -> 右键目标分区 -> “压缩卷” -> 输入压缩空间大小（建议 30000MB 或更多） -> “压缩”

### 1.2 BIOS 设置
重启电脑，进入 BIOS/UEFI 设置（通常按 `F2`、`F12`、`Delete` 等键）。

- 设置 U 盘为临时或优先启动项
- 建议关闭 Secure Boot
- Windows 的快速启动可能影响双系统访问磁盘，建议关闭
- 保持 Windows 和 Ubuntu 使用相同的 UEFI 启动方式

### 1.3 安装 Ubuntu

插入启动 U 盘，重启电脑，进入 Ubuntu 安装界面。
选择“安装 Ubuntu”，按照提示设置语言、键盘布局、网络连接和时区。

安装类型可以选择“与 Windows 共存”或“其他选项（Something else）”。第一次安装时，前者通常更简单；如果选择手动分区，只使用此前准备好的未分配空间。

### 1.4 选择分区
**不要删除 Windows 的 EFI、恢复分区和已有数据分区。** 如果选择手动分区，在未分配空间中创建挂载点为 `/`、格式为 `ext4` 的根分区即可；首次安装建议分配 30GB 到 50GB，后续可根据项目和数据量调整。除非明确了解用途，不需要自行创建过多分区。

### 1.5 安装过程
1. 选择时区，输入用户名和密码；
2. 等待安装完成，期间可以选择安装第三方软件（如图形驱动、媒体编解码器等）。

### 1.6 完成安装
1. 安装完成后，重启电脑，拔出 U 盘；
2. 进入 Ubuntu 系统后，先确认网络、磁盘空间和双系统启动是否正常，再进行更新和驱动配置：

```bash
sudo apt update
sudo apt upgrade
```

---

## 2. 学习使用 Ubuntu

### 2.1 熟悉 Ubuntu 的基本操作和命令行使用

终端是 Linux 开发中最常用的工具。先理解“当前目录、文件、权限、命令输出”这几件事，再逐步记忆命令即可。

| 命令 | 作用 |
| --- | --- |
| `pwd` | 查看当前目录 |
| `ls` / `ls -la` | 查看目录内容和隐藏文件 |
| `cd path` / `cd ..` | 进入目录 / 返回上一级 |
| `mkdir name` | 创建目录 |
| `cp` / `mv` | 复制、移动或重命名文件 |
| `cat` / `less` | 查看文件内容 |
| `grep` / `find` | 搜索文本或文件 |
| `man command` | 查看命令手册 |

执行 `rm`、`mv` 或批量命令前，先用 `pwd` 和 `ls` 确认当前位置和目标路径。Linux 不会因为你手滑就自动后悔，所以**路径要多看一眼**。你也不想手滑删掉老代码或者根目录导致重装系统吧(

### 2.2 安装和管理软件包

Ubuntu 使用 APT 管理软件包。常用命令如下：

```bash
sudo apt update              # 更新软件包索引
sudo apt upgrade             # 更新已安装的软件
sudo apt install git      # 安装软件
sudo apt remove package      # 卸载软件
apt search keyword           # 搜索软件包
```

`sudo` 表示以管理员权限执行命令。不要为了方便给每条命令都加 `sudo`，更不要执行来源不明的安装脚本；先看清命令会修改什么。

#### 2.2.1 安装常用软件

打开终端，安装 Git、Vim、GCC/G++ 和常用命令行工具：

```bash
sudo apt install build-essential git curl wget
```

图形界面软件如 VS Code、PyCharm 等，优先使用官网或官方软件源提供的安装方式。

#### 2.2.2 配置开发环境

1. 根据需要安装 Python、C++ 等编程环境。可以使用以下命令检查版本：

```bash
python3 --version
g++ --version
git --version
```

2. 配置 OpenCV、PyTorch 等计算机视觉库前，先阅读项目官方安装说明。特别是 GPU 环境，需要确认显卡驱动、CUDA、Python 和框架版本是否匹配

### 2.3 文件权限

Linux 中每个文件和目录都有权限设置，用于控制不同用户可以进行的操作。使用以下命令可以查看权限：

```bash
ls -l file.txt
```

输出通常类似于：

```text
-rwxr-xr-- 1 alice developers 1200 Aug 25 10:00 script.sh
```

最前面的 10 个字符可以分为四部分：

```text
-  rwx  r-x  r--
│   │    │    └── 其他用户（others）的权限
│   │    └─────── 所属用户组（group）的权限
│   └──────────── 文件所有者（owner）的权限
└──────────────── 文件类型：- 表示普通文件，d 表示目录
```

其中：

- `r`（read）：读取文件内容；
- `w`（write）：修改文件内容；
- `x`（execute）：执行文件。对于目录，`x` 表示可以进入该目录；
- `-`：不具备对应权限。

这里的权限对象分为三类：

- **文件所有者（owner）**：通常是创建文件的用户。例如，你在自己的主目录中创建 `train.py`，默认所有者就是你的 Ubuntu 账号；
- **所属用户组（group）**：一组用户的集合。可以把同一个项目的成员加入 `vision` 用户组，让他们共享项目文件的部分权限；
- **其他用户（others）**：既不是文件所有者，也不属于该文件所属用户组的其他账号。

`rwxr-xr--` 表示：文件所有者可以读、写和执行；同组用户可以读和执行；其他用户只能读取。

可以使用 `chmod` 修改权限。常见写法包括：

```bash
chmod u+x script.sh       # 给文件所有者增加执行权限
chmod g-w file.txt        # 移除所属用户组的写权限
chmod o-r secret.txt      # 移除其他用户的读权限
chmod a+r file.txt        # 给所有用户增加读权限
```

也可以使用数字表示权限：`r=4`、`w=2`、`x=1`，将每一组权限相加即可。例如：

```bash
chmod 755 script.sh       # 所有者 rwx，同组和其他用户 r-x
chmod 644 file.txt        # 所有者 rw，其他用户 r
```

脚本无法运行时，可以先增加执行权限：

```bash
chmod +x script.sh
./script.sh
```

不要为了省事使用 `chmod -R 777`。这会让目录中的所有用户都拥有读、写和执行权限，可能造成文件被意外修改或敏感信息泄露。应根据实际需求，只修改指定文件和必要的权限。

### 2.4 环境变量

环境变量是由系统或用户设置的一组变量，常用于保存路径、配置和程序运行所需的信息。查看环境变量可以使用：

```bash
echo $PATH
echo $HOME
printenv
```

`PATH` 决定终端会在哪些目录中寻找命令。遇到 `command not found` 时，可以检查：

```bash
which command
echo $PATH
```

临时设置环境变量：

```bash
export PROJECT_MODE=dev
echo $PROJECT_MODE
```

这种设置通常只对当前终端会话有效。需要长期配置时，可以将内容写入 `~/.bashrc`，修改后使用 `source` 重新加载。

### 2.5 常见问题排查

- **命令找不到**：确认软件是否已安装、命令是否拼写正确、虚拟环境是否激活、`PATH` 是否包含可执行文件目录；
- **权限不足**：先用 `ls -l` 检查文件所有者和权限，不要直接修改整个目录权限；
- **软件安装失败**：阅读完整错误信息，检查网络和软件源配置，不要反复复制安装命令；
- **驱动或图形界面异常**：记录 Ubuntu 版本、显卡型号、内核版本和错误信息，优先查看官方文档和已有讨论。

---

## 参考资源
1. [Ubuntu 官方文档](https://help.ubuntu.com/)
2. [Ubuntu 社区论坛](https://ubuntuforums.org/)
3. [Linux 命令行教程](https://linuxcommand.org/)
> 上面给出的链接有些是 AI 帮忙找的，不过我都亲自试过了，暂时可以正常使用。

如果看完本文后，对 Ubuntu 安装仍有疑问，可以观看 B 站视频：[机器人工匠阿杰的 Windows 11 安装 Ubuntu 避坑指南](https://www.bilibili.com/video/BV1Cc41127B9?vd_source=2d387c6c6531522d2ad4d23d445bfa68)。

现在你已经半只脚迈入了视觉组的大门，接下来就是不断学习和实践的过程。祝你好运！
