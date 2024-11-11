[TOC]

## 一、Git命令速查表
![image.png](https://img-blog.csdnimg.cn/img_convert/bb553d59bc02b03547e4f986bb9e4c3c.png)
## 二、Git简介
### 1.Git是什么
Git是一个开源的分布式版本控制系统，可以有效、高速地处理从很小到非常大的项目版本管理.
### 2.Git工作流程
![请添加图片描述](https://i-blog.csdnimg.cn/direct/16686aa63e65443f8687037032d90ac8.jpeg)

## 三、Git安装配置
### 1.下载

[Git官网](https://git-scm.com/download)

#### 查看Git版本
```
git --version
```

> Git GUI：Git提供的图形界面工具 
> Git Bash：Git提供的命令行工具


### 2.配置
#### 新建.git文件

```
git init 
```

#### 全局配置

```
git config --global user.name '你的账户名称'
git config --global user.email '你的 Email'
```




#### 局部配置
```
git config --local user.name '你的账户名称'   
git config --local user.email '你的 Email'
```

### 3.查看
#### 查看全局配置

```
git config --global --list
```
#### 查看当前配置
```
git config --local --list
```

#### 查看用户和邮箱
```
git config user.name
git config user.email
```

### 4.报错修改
#### Windows系统下在提交代码时自动将LF转换为CRLF

```
git config --global core.autocrlf true
```

#### Linux/macOS系统下在提交代码时自动将CRLF转换为LF
```
git config --global core.autocrlf input
```
## 四、Git基本操作
### 1.查看内容
#### 查看详细日志
```
git log
```
#### 查看简化日志
```
git log --pretty=oneline --all --graph --abbrev-commit
```
#### 查看版本号
```
git reflog
```
#### 查看变更状态

```
git status
```
#### 查看暂存区

```
git ls-files
```
#### 查看工作区与暂存区的差异
```
git diff
```
#### 查看暂存区与本地仓库的差异
```
git diff --cached
```

> --pretty=oneline：显示为一行
> --all：显示所有
> --graph：图形化显示
> --abbrev-commit：使用短提交哈希值

### 2.修改内容

#### 恢复工作区内容
```
git restore .
```
#### 删除工作区文件

```
git rm 文件
```
#### 删除暂存区文件
```
git rm --cached
```

#### 撤销上次提交

```
git commit --amend
```
#### 重命名
```
git mv 旧名称 新名称
```

#### 版本回退
```
git reset --hard id
```

> 版本id可以用git reflog查看，只用输入前7位即可

### 3.提交内容

#### 全部提交
```
git add .
```

#### 指定提交
```
git add 文件
```
#### 无注释
```
git commit
```
#### 有注释
```
git commit -m "注释内容"
```
#### 跳过暂存区提交(新文件不行)
```
git commit -am "注释内容"
```
### 4.回滚操作

#### 删除记录回滚
```
git reflog
git reset --hard id
git push -f
```

#### 保留记录回滚
```
git reflog
git revert -n id
git commit -m "注释"
git push
```

## 五、分支操作

### 1.增删改查

#### 创建分支
```
git branch 分支名
```

#### 查看所有分支
```
git branch
```
#### 查看当前分支
```
git branch -v
```
#### 切换分支
```
git checkout 分支名
```
#### 创建并切换分支
```
git checkout -b 分支名
```
#### 合并分支
```
git merge 分支名
```
#### 删除分支
```
git branch -d 分支名
```
#### 强制删除分支
```
git branch -D 分支名
```
#### 删除远程分支
```
git push remote --delete 远程分支名
git push remote:远端分支名 
```
> 切换分支前要先提交到暂存区

### 2.标签管理

#### 添加标签
```
git tag -a 标签名
```

#### 指定版本添加标签
```
git tag -a 标签名 id
```

#### 查看标签
```
git tag
```

#### 添加标签内容
```
git tag -a 标签名 -m '标签内容'
```

#### 查看标签信息
```
git show 标签名
```

#### 推送单个标签
```
git push origin 标签名
```

#### 推送所有标签
```
git push origin --tags
```
## 六、远程仓库

#### 添加远程仓库
```
git remote add 远程仓库名 地址
```
#### 克隆仓库
```
git clone 远程仓库地址
```

#### 查看远程仓库地址
```
git remote -v
```

#### 查看远程仓库名称
```
git remote
```

#### 删除远程仓库
```
git remote remove 远程仓库名
```

#### 重命名远程仓库
```
git remote rename 旧名称 新名称
```

#### 抓取(同步本地没有的数据)
```
git fetch 远程仓库名
```

#### 拉取(同步到本地并合并)
```
git pull
```

#### 同步远程分支到本地
```
git remote prune origin
```
#### 推送(上传到远程仓库)
```
git push 仓库名 分支名
```

> git pull = git fetch + git merge
> 远程仓库默认命名为origin
> 如果远程分支名和本地分支名称相同，则可以只写本地分支
> 可以省略已关联仓库的分支名和远端仓库名
> 可以直接克隆已有的仓库到本地，本地目录可以省略，会自动生成一个目录