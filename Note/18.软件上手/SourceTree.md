
# 一、概述

## 1.SourceTree是什么

定义：可视化版本管理工具

## 2.SourceTree的功能

> 通过一个简单的用户界面即可使用所有的Git命令
> 通过一次单击，即可管理所有的Git库，无论是托管的还是本地的
> 通过一次单击，即可进行commit、push、pull、merge等操作
> 一些先进的功能，如补丁处理、rebase、shelve、cherry picking等
> 可以连接到你托管在Bitbucket、Stash、Microsoft TFS或GitHub中的代码库

## 3.SourceTree的使用场景



# 2.安装SourceTree

## 2.1 下载注册

官网入口：[Sourcetree](https://www.sourcetreeapp.com/)
账号注册：[Atlassian](https://www.atlassian.com/zh/try/cloud/signup?product=jira-software.ondemand)

## 2.2 名词解释

- **克隆**(clone)：从远程仓库URL加载创建一个与远程仓库一样的本地仓库
- **提交**(commit)：将暂存文件上传到本地仓库（我们在Finder中对本地仓库做修改后一般都得先提交一次，再推送）
- **检出**(checkout)：切换不同分支
- **添加**(add)：添加文件到缓存区
- **移除**(remove)：移除文件至缓存区
- **暂存**(git stash)：保存工作现场
- **重置**(reset)：回到最近添加(add)/提交(commit)状态
- **合并**(merge)：将多个同名文件合并为一个文件，该文件包含多个同名文件的所有内容，相同内容抵消
- **抓取**(fetch)：从远程仓库获取信息并同步至本地仓库
- **拉取**(pull)：从远程仓库获取信息并同步至本地仓库，并且自动执行合并（merge）操作，即 pull=fetch+merge
- **推送**(push)：将本地仓库同步至远程仓库，一般推送（push）前先拉取（pull）一次，确保一致
- **分支**(branch)：创建/修改/删除分支
- **标签**(tag)：给项目增添标签
- **工作流**(Git Flow)：团队工作时，每个人创建属于自己的分支（branch），确定无误后提交到master分支
- **终端**(terminal)：可以输入git命令行

# 三、远程仓库

## 1.常用仓库

[gitHub](https://github.com/ )

[码云](https://gitee.com/ )

[GitLab](https://about.gitlab.com/ )

## 2.创建远程仓库

### 2.1注册码云

![image.png](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306031614271.png)

### 2.2新建仓库

![git流程](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306022344977.png)
![git流程](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306022344978.png)

### 2.3克隆仓库到本地

![git](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306031516015.png)
![git](https://djm-1317856319.cos.ap-shanghai.myqcloud.com/djm-1317856319/202306031518561.png)

