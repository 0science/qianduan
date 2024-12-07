## 修改软件源

`sudo vim /etc/apt/sources.list`  修改Ubuntu系统的软件源

```
deb https://mirrors.ustc.edu.cn/ubuntu/ bionic main restricted universe multiverse

deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic main restricted universe multiverse

deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse

deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse

deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse

deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse

deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-security main restricted universe multiverse

deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-security main restricted universe multiverse

deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse

deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
```
中科大源

`sudo apt-get update`                apt资源更新

`sudo apt-get upgrade -y`           apt资源安装

## 安装常用软件

`sudo apt-get install openssh-server -y`      安装远程连接软件

`sudo apt-get install vim -y`               安装vim编辑器

`sudo apt-get install lrzsz -y`               安装上传与下载软件

`sudo apt-get install net-tools -y`            安装网络命令工具

`sudo apt-get install curl -y`                安装curl下载工具

`sudo apt-get install tree -y`                安装目录树状图

`sudo apt-get install build-essential -y`        安装gcc、make等软件

## 安装docker

`apt install docker.io -y`         安装Docker软件包

`systemctl enable docker`        将Docker服务设置为每次开机启动

`systemctl start docker`          将Docker服务立即启动

`vim /etc/docker/daemon.json`        Docker镜像加速设置

```
{

  "registry-mirrors": ["https://docker.mirrors.ustc.edu.cn"]

}
```

`systemctl restart docker`         将Docker服务重启

`docker version`                查看当前Docker版本

`docker run hello-world`          运行hello-world

`docker run -d -p 80:80 nginx`          完成Nginx的下载与启动

`curl -I 10.0.0.11`         测试

`docker search`     搜索镜像，优先选官方，STARTS数量多
`docker search alpine`

`docker pull`       下载镜像
`docker pull alpine`

`docker push`       上传镜像
`docker pull alpine:3.12.10`

`docker load -i`       导入镜像

[官方网址](https://hub.docker.com/)

`docker image ls`

`docker load -i docker_busybox.tar.gz`

`docker rmi alpine:3.15`

`docker run  -d -it -p 80:80  nginx:latest`

`docker ps`

`docker run -it --name centos6 centos:6.9 /bin/bash`

#### docker容器
`docker create`       创建容器 --name

`docker start`         启动容器  可以用容器的名字、ID

`docker  stop`        停止容器(正常关机)

`docker  restart`     重启容器

`docker  kill`        强制停止容器(直接拔电源)

`docker  rm`        

删除容器，删除容器的时候先停止，再删除，docker不能删除正在运行的容器，除非强制删除，参数-f

```
docker rm -f `docker ps -a -q`      
```
批量强制删除所有容器但是容器对应的镜像还在

## 安装Docker-Compose

```
curl -L https://get.daocloud.io/docker/compose/releases/download/v2.6.1/docker-compose-`uname -s`-`uname -m` > /usr/local/bin/docker-compose 
```

下载Docker-Compose

`chmod +x /usr/local/bin/docker-compose`               

修改Docker-Compose的权限

`docker-compose --version`                           查看Docker-Compose的版本

## 安装golang
`wget https://studygolang.com/dl/golang/go1.17.11.linux-amd64.tar.gz` 
下载Golang安装包

`tar -xzvf go1.17.11.linux-amd64.tar.gz -C /usr/local/  `         
解压缩Golang安装包

`vim /etc/profile`                                              修改环境变量

```
export GOROOT=/usr/local/go    

export GOPATH=$HOME/go

export PATH=$PATH:$GOROOT/bin:$GOPATH/bin

export GOPROXY=https://goproxy.cn
```

`source /etc/profile`                             使环境变量生效

`go version`                       查看Golang版本

## 搭建单一Fabric环境

(1) 创建项目目录

`mkdir -p ~/go/src/github.com/hyperledger`

`cd ~/go/src/github.com/hyperledger`

(2) 拉取Fabric项目

`git clone https://gitee.com/hyperledger/fabric.git`

(3) 切换Fabric版本，其结果如图4-2所示。

`cd fabric`

`git checkout v2.0.0`

(4) 拉取Fabric镜像，在140行和141行将参数改为false，其修改如图4-3所示。

`cd ~/go/src/github.com/hyperledger/fabric/scripts`

`vim bootstrap.sh`

(5) 进入~/go/src/github.com/hyperledger后拉取fabric-samples

`cd ~/go/src/github.com/hyperledger`

`git clone https://gitee.com/hyperledger/fabric-samples.git`

(6) 进入fabric-samples目录，拉取成功后切换到v2.0.0-beta分支，其结果如图4-5所示。

`cd ~/go/src/github.com/hyperledger/fabric-samples`

`git checkout v2.0.0-beta`

(7) 在fabric-samples目录，下载所需文件

`wget https://github.com/hyperledger/fabric/releases/download/v2.0.1/hyperledger-fabric-linux-amd64-2.0.1.tar.gz`

`tar -xzvf hyperledger-fabric-linux-amd64-2.0.1.tar.gz`