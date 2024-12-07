## 1.Linux环境搭建

## 2.Linux基本指令

### 压缩包解压

1、\*.tar 用 tar –xvf 解压 
2、\*.gz 用 gzip -d或者gunzip 解压 
3、\*.tar.gz和*.tgz 用 tar –xzf 解压 
4、\*.bz2 用 bzip2 -d或者用bunzip2 解压 
5、\*.tar.bz2用tar –xjf 解压 
6、\*.Z 用 uncompress 解压 
7、\*.tar.Z 用tar –xZf 解压 
8、\*.rar 用 unrar e解压 
9、\*.zip 用 unzip 解压

unrar e test.rar DestPath　　#解压（会在把当前压缩包内容解压到当前目录内，容易造成解压内容和当前目录原文件混合，不容易区分，不建议使用）

unrar x test.rar DestPath　　#解压（会在当前解压目录内产生一个以压缩包名字命名的目录，目录内是解压内容，推荐使用）

## 3.Docker

(2) 在虚拟机中输入如下指令完成Docker的安装与配置

安装Docker软件包
```
apt install docker.io -y
```
将Docker服务设置为每次开机启动
```
systemctl enable docker   
```
将Docker服务立即启动
```
systemctl start docker      
```
 Docker镜像加速设置
```
vim /etc/docker/daemon.json       
```
```
{   
	"registry-mirrors": ["https://ustc-edu-cn.mirror.aliyuncs.com"]  
}
```
将Docker服务重启
```
systemctl restart docker
```
查看当前Docker版本         
```
docker version
```
## 4.区块链

## 5.Fabric

## 6.超级账本

## 7.Fisco Bcos

## 8.长安链

## 9.环境

### vim
安装vim
```
sudo apt-get install vim
```

### nodejs
更新
```
sudo apt update
```
安装nodejs和npm
```
sudo apt install nodejs npm
```
查看nodejs版本
```
nodejs --version
```
查看npm版本
```
npm --version
```

### yum
