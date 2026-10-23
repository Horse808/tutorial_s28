# 视觉第四课:Git与GitHub

# 视觉第四课：git与github的使用

先学会如何管理i本地git仓库，在拓展到github的使用



# 1\.git的学习与使用

## 1\.1 啥是git

git简单来说，就是一个版本管理工具，在你的电脑本地运行。他可以记录代码的每次修改，让你可以随时回退到以前的版本以便于你大胆尝试新功能。

## 1\.2 安装与配置git

一般来讲ubuntu已经预置了git，不过保险起见还是查看一下，打开终端输入：

```Plain Text
git --version
```

如果没有，那就自己下载一个：

```Plain Text
sudo apt install git -y
```

然后安装完成后配置身份信息，用于查看每次是谁提交的：

```Plain Text
git config --global user.name "你的名字"
git config --global user.email "你的邮箱"
```

## 1\.3 使用git

“仓库”实际就是一个被Git管理的项目文件夹，可以先创建一个文件夹，打开终端输入：

```Plain Text
mkdir my-firsr-git && my-first-git
```

接着初始化仓库，类似于部署GIt来开始管理仓库：

```Plain Text
git init
```

这会在当前目录创建一个隐藏的\.git文件夹，Git开始跟踪这个项目的变化。

最后创建一个文件然后提交：

```Plain Text
echo "# My First Git" > README.md    # 创建一个简单的文件
git add README.md                    # 把文件添加到“暂存区”，表示准备提交
git commit -m "Initial commit"       # 把暂存区的改动正式记录为一个提交
```

这一套流程就是Git最核心的操作：修改 \-\-\> add \-\-\> commit ，每个提交都相当于可以回退的存档点。

## 1\.4 Git的常用指令

|git init|初始化仓库|
|---|---|
|git status|查看当前仓库状态|
|git add \.|把当前目录所有改动添加到缓存|
|git commit \-m "说明"|把暂存区的改动提交为一个版本|
|git log|查看提交历史|

还有许多其他指令，包括版本回溯，合并版本，此处只讲了核心功能，其他功能请自学，可以在 [廖雪峰的git教程](https://www.liaoxuefeng.com/wiki/896043488029600) 上学习，讲的非常好。

## 1\.5 Git在VSCode上的使用

打开VSCode左侧选项可以看到Git管理，可以直接在VSCode上进行提交修改，通用的。



# 2\.Github的使用

## 2\.1 啥是GitHub

GitHub简单来说就是一个仓库托管平台，本质就一网站。他把你的Git仓库放到云端，方便备份，分享和多人协作。

## 2\.2 使用GitHub

现在本地仓库有了，需要把他和GitHub上的远程仓库关联起来

### 2\.2\.1 连接GitHub

1\.使用SSH方式连接，在电脑上生成一对钥匙（公钥和私钥），公钥放到GitHub上，私钥自己保管。

所以先生成密钥，打开终端输入：

```Plain Text
ssh-keygen -t ed25519 -C "your_email@example.com"
```

一路回车即可。

然后复制公钥添加到GitHub

```Plain Text
cat ~/.ssh/id_ed25519.pub
```

登陆GitHub，头像 \-\-\> Settings \-\-\> SSH and GPG keys \-\-\> New SSH key

把复制的内容粘贴进去，取个名字，保存。

最后测试一下连接，终端输入：

```Plain Text
ssh -T git@github.com
```

如果看到 “Hi XXX\! You've successfully authenticated, but GitHub does not provide shell access\.” 就说明成功了。



2\.使用HTTPS连接，但比较麻烦，不推荐

### 2\.2\.2 推送代码（仓库）

先在GitHub上创建空仓库（全部默认即可）,然后在打开终端到你的仓库文件夹下输入：

```Plain Text
git remote add origin git@github.com:用户名/仓库名字.git
git push -u origin main
```

不出意外就是顺利推送代码到你的github上了，然后之后每次都add，然后commit，最后git push 就可以了。

### 2\.2\.3 克隆仓库

打开终端输入：

```Plain Text
git clone git@github.com:用户名/仓库名字.git
```

就可以把别人的仓库克隆下来为己所用。



# 学习资源：

## 1\.[廖雪峰的git教程](https://www.liaoxuefeng.com/wiki/896043488029600)

## 2\.[GitHub Guides](https://guides.github.com/)

在学习的时候，一定要动手跟着一起实践，切忌光看不动！俗话说熟能生巧。



# 课后实践：

在本地写一个代码使用cmake编译，成功运行后写个README\.md，然后git提交，最后上传到github仓库。（记得使用gitignore来忽略一些无关紧要的文件，比如build文件夹）



