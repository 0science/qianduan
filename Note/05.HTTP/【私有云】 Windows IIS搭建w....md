# 【私有云】 Windows IIS搭建webdav服务实现公网文件共享「内网穿透」


[blog.csdn.net](https://blog.csdn.net/qq_53847859/article/details/129982070?ops_request_misc=&request_id=&biz_id=102&utm_term=windows%E6%96%87%E4%BB%B6%E5%A4%B9%E5%85%B1%E4%BA%ABiis&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-1-129982070.142%5Ev93%5EchatsearchT3_1&spm=1018.2226.3001.4187)成就一亿技术人!



#### {#t0}文章目录


+ [前言](#_2)
+ [视频教程](#_12)
+ [1. 安装IIS必要WebDav组件](#1_IISWebDav_16)
+ [2. 局域网浏览器访问测试](#2__82)
+ [3. cpolar内网穿透](#3_cpolar_92)
+  
    - [3.1 安装cpolar内网穿透](#31_cpolar_96)
    - [3.2 登录cpolar web UI管理界面](#32_cpolar_web_UI_104)
    - [3.2 创建隧道](#32__110)
    - [3.3 获取公网地址](#33__128)
+ [4. 公网远程访问](#4__134)
+  
    - [4.1 浏览器访问测试](#41__136)
    - [4.2 映射本地盘符访问](#42__142)
    - [4.3 安装Raidrive客户端](#43_Raidrive_182)
+ [5. 配置固定公网地址](#5__196)
+  
    - [5.1 保留固定TCP端口地址](#51_TCP_200)
    - [5.2 配置固定TCP端口地址](#52_TCP_217)
+ [6. 使用固定公网TCP端口地址远程连接](#6_TCP_236)
+  
    - [6.1 浏览器访问](#61__238)
    - [6.2 映射本地盘符](#62__244)
    - [6.3 通过RaiDrive客户端访问](#63_RaiDrive_254)
+ [图书推荐](#_259)



## {#t1}前言


常用的[文件共享](https://so.csdn.net/so/search?q=%E6%96%87%E4%BB%B6%E5%85%B1%E4%BA%AB&spm=1001.2101.3001.7020)有三种：FTP、Samba、WebDAV。FTP虽然简单方便、容易部署，但它的的传输效率低、安全性不佳，目前并不推荐使用。SMB使用的是445端口，因为安全原因，445端口可能会被封掉，所以SMB在内网中的应用会受限。



而[WebDAV](https://so.csdn.net/so/search?q=WebDAV&spm=1001.2101.3001.7020)是基于HTTP的共享协议，用户可以使用用户名和密码来访问存储资源，可供多个用户共享文件。并且，在windows上，我们可以通过系统自带的IIS服务来启用搭建webdav，并做内网穿透，实现在公网下的文件共享，搭建私有云服务。



本文使用的是WIN10 专业版。  
![](https://img-blog.csdnimg.cn/5da09ff874f142a5a17b7dce3a8d7ef4.jpeg#pic_center)



## {#t2}视频教程


[https://www.bilibili.com/video/BV15G4y1S7Ud/?spm_id_from=333.999.0.0](https://www.bilibili.com/video/BV15G4y1S7Ud/?spm_id_from=333.999.0.0)



## {#t3}1. 安装IIS必要WebDav组件


1.1 打开控制面板，查看方式改为`类别`，进入`程序`------`启用或关闭Windows功能`



![](https://img-blog.csdnimg.cn/img_convert/ba3a33914629115d10d175c04443b36c.png#pic_center)



1.2 在Internet Information Services（IIS）中勾选`IIS管理控制台`、`Windows身份验证`、`管理服务`、`WebDAV发布`和`目录浏览`，然后确定安装。



![](https://img-blog.csdnimg.cn/img_convert/0f0e41a6a7c8828f0c28a05dcc7d33a8.png#pic_center)



1.3 完成安装后，在"Windows管理工具"中找到`IIS管理器`并打开。



![](https://img-blog.csdnimg.cn/img_convert/7167e5ad0b4a7c4fd20f46d5acc3e0a3.png#pic_center)



1.4 在网站，按右键`添加网站`



![](https://img-blog.csdnimg.cn/img_convert/555eb2d7be176616d358ecf13e4c60e7.png#pic_center)



1.5 为网网起个名，并且选择一个物理路径，这里，我起名称为webdav，路径选择：D:\WebDav（选择想要共享的文件路径），端口号，我们设置为8090



![](https://img-blog.csdnimg.cn/img_convert/53cfca50a5653938f94a9f47a1049ece.png#pic_center)



1.6 选中webdav站点，并进入它的`WebDAV创作规则`



![](https://img-blog.csdnimg.cn/img_convert/58581ea324ee1bc5ef0ae73109f4f668.png#pic_center)



1.7 启用创作规则



![](https://img-blog.csdnimg.cn/img_convert/bac208bbfbf2f1b8a3a399e088645e7d.png#pic_center)



1.8 添加创建规则



![](https://img-blog.csdnimg.cn/img_convert/1b12cb41d1a52c245a9770e17e4a0bc4.png#pic_center)



![](https://img-blog.csdnimg.cn/img_convert/320a6f847da9bcf12cba2b47a028f358.png#pic_center)



1.9 选择webdav站点，进入`身份认证`



![](https://img-blog.csdnimg.cn/img_convert/232ff1701771179a3f5d3640d3ec93a4.png#pic_center)



1.10 启用`基本身份验证`，禁用`Windows身份验证`、`匿名身份验证`



![](https://img-blog.csdnimg.cn/img_convert/cdd010d3df74c7f1dc13c2accf7443ba.png#pic_center)



1.11 选中"webdav"，进入`目录浏览`



![](https://img-blog.csdnimg.cn/img_convert/b286d3d5fab7294f2812149e57aefea1.png#pic_center)



1.12 点击`启用`



![](https://img-blog.csdnimg.cn/img_convert/a0d515e2d8fb67bbdadb64dabc4004e4.png#pic_center)



1.13 重启webdav站点



![](https://img-blog.csdnimg.cn/img_convert/490aea25c817a6bfbd5a7097272380df.png#pic_center)



## {#t4}2. 局域网浏览器访问测试


在浏览器中，输入http://127.0.0.1:8090/，就可以访问WebDav服务中的文件内容了。



![](https://img-blog.csdnimg.cn/img_convert/58e8bd1da0a477049a6a9015af0443e6.png#pic_center)



输入windows账号密码登录



![](https://img-blog.csdnimg.cn/img_convert/d3833c2e257c627a73f5adf8673e8a22.png#pic_center)



## {#t5}3. cpolar内网穿透


测试在局域网内访问成功后，接下来用cpolar做内网穿透，将其发布到公网上，实现在外也可以访问到家里/公司的webdav服务，进行文件共享，无需公网IP，也不需要设置路由器。



### {#t6}3.1 安装cpolar内网穿透


> cpolar官网：[https://www.cpolar.com/](https://www.cpolar.com/)
>



在cpolar官网注册一个账号，并下载安装windows版本的客户端



![](https://img-blog.csdnimg.cn/img_convert/887468e5386e03e482e40c4eab677216.png#pic_center)



### {#t7}3.2 登录cpolar web UI管理界面


cpolar内网穿透安装完成后，打开浏览器访问127.0.0.1:9200，并用cpolar邮箱账号登录。



![](https://img-blog.csdnimg.cn/img_convert/1e699c2c0682923667d39a31cd34aa0a.png#pic_center)



### {#t8}3.2 创建隧道


登录到cpolar web UI管理界面后，点击左侧的隧道管理------创建隧道，我们来创建一条隧道将本地webdav服务映射到公网上。



![](https://img-blog.csdnimg.cn/img_convert/cf4a2ce586ebe18abe588bccf04a7dc6.png#pic_center)



+ `隧道名称`：可自定义填写，注意不要与已有的隧道名称重复
+ `协议`：选择tcp协议
+ `本地地址`：8090
+ `端口类型`：先按默认选择随机临时端口
+ `地区`：按默认选择或者也可以选择China其他地区



点击`创建`



![](https://img-blog.csdnimg.cn/img_convert/2240b6c3fc5dd20eb3fc8f4e8de96ea3.png#pic_center)



### {#t9}3.3 获取公网地址


隧道创建成功后，点击左侧的状态------在线隧道列表，我们可以看到，已经生成了一个TCP随机隧道，将其复制下来，接下来测试公网远程访问。



![](https://img-blog.csdnimg.cn/img_convert/0382f5135f00b87defc1211ed338471c.png#pic_center)



## {#t10}4. 公网远程访问


### {#t11}4.1 浏览器访问测试


我们在浏览器中，粘贴隧道地址，因为是从外网访问，会提示账号及密码进行身份验证。我们使用windows账号及密码登录。



![](https://img-blog.csdnimg.cn/img_convert/b39b9bb421e36ddce52bf4514d034988.png#pic_center)



### {#t12}4.2 映射本地盘符访问


在应用之前需要我们需要先修改注册表，需要修改注册表使得WIN10同时支持http和https，否则无法映射WebDAV网络驱动器的。因为如果WebDAV不是https的，win10默认是添加不上的，默认只支持https。



点击左下角开始菜单栏，右键点击运行



![](https://img-blog.csdnimg.cn/img_convert/f373b4b3634bc1c19ed6c2d4eaeeaa07.png#pic_center)



输入`regedit`，点击确定即可打开注册表编辑器



![](https://img-blog.csdnimg.cn/img_convert/b0a857645d75c22dda15be7bcf0ecfbe.png#pic_center)



路径：计算机\HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\WebClient\Parameters



![](https://img-blog.csdnimg.cn/img_convert/afed4d63cdc586ff2da64e625678d0bd.png#pic_center)



找到`BasicAuthLevel`后，右键点击修改，将数值数据改成`2`，并点击确定，修改成功后，`重启电脑`



![](https://img-blog.csdnimg.cn/img_convert/534f098c257209ae409a16e96a30130b.png#pic_center)



打开文件夹，点击此电脑，点击上方的计算机------映射网络驱动器



![](https://img-blog.csdnimg.cn/img_convert/64d26da38c3fa3764113dce71863bdeb.png#pic_center)



输入刚刚通过cpolar映射本地8090端口所生成的公网地址，注意需要以`http://` 格式填写



![](https://img-blog.csdnimg.cn/img_convert/42af61f59d1c90b908ebbbef29868e18.png#pic_center)



连接中



![](https://img-blog.csdnimg.cn/img_convert/b0d165171ebda56f63ec33f5ea07586e.png#pic_center)



填写windows账号密码进行连接



![](https://img-blog.csdnimg.cn/img_convert/9dd11b62ba4f471df576e50ecdabc317.png#pic_center)



连接成功，可以直接访问资源



![](https://img-blog.csdnimg.cn/img_convert/8c1cae20923848d22df4e147abb07d22.png#pic_center)



### {#t13}4.3 安装Raidrive客户端


当然，我们还可以通过WebDav客户端，将远程服务器虚拟机本地盘符【无需修改注册表数据】，这里我们用Raidrive公户来实现。



Raidrive客户端下载地址：[https://www.raidrive.com/download](https://www.raidrive.com/download)



安装Raidrive成功后，连接WebDav服务器



![](https://img-blog.csdnimg.cn/img_convert/2996b28a93fc884ae3a673213863d0ce.png#pic_center)



连接成功



![](https://img-blog.csdnimg.cn/img_convert/9d75258d2d748f77206eade8cae34b16.png#pic_center)



## {#t14}5. 配置固定公网地址


目前测试使用的是随机TCP隧道创建的链接，所生成的公网地址会在24小时内会变化，如果需要长期使用，我们可以将其配置为固定的公网TCP地址，同时提高带宽。



### {#t15}5.1 保留固定TCP端口地址


配置保留固定的TCP端口地址，需要将cpolar套餐升级至专业版或以上才支持【登录`cpolar官网后台`------[套餐](https://dashboard.cpolar.com/billing)】



登录cpolar官网后台，点击左侧的`预留`，我们来为webdav保留一个固定的TCP端口地址



+ 地区：选择China或者China VIP
+ 描述：即备注，可自定义填写



点击`保留`



![](https://img-blog.csdnimg.cn/img_convert/8ebf0e6f68c4fd6aceffb0f396780c69.png#pic_center)



地址保留成功后，系统会返回一个固定的TCP端口地址，将其复制下来



![](https://img-blog.csdnimg.cn/img_convert/c9ea1d18cc2f29a2a96feb2c5f158ea6.png#pic_center)



### {#t16}5.2 配置固定TCP端口地址


登录cpolar web ui管理界面[http://localhost:9200/](http://localhost:9200/#/dashboard)，点击左侧的`隧道管理`------`隧道列表`，找到wwebdav隧道，点击右侧的`编辑`



![](https://img-blog.csdnimg.cn/img_convert/da111c96c05b059a96e38df3d9f5fea1.png#pic_center)



修改隧道信息：



+ 端口类型：选择`固定TCP端口`
+ 预留的TCP地址：填入刚刚所保留成功的固定TCP端口地址



点击`更新`



![](https://img-blog.csdnimg.cn/img_convert/61b763ead3ed6a8ec3c0edf1aea1f760.png#pic_center)



隧道更新成功后，点击左侧仪表盘的`状态`------`在线隧道列表`，可以看到公网地址已经变成了固定的公网TCP端口地址。



![](https://img-blog.csdnimg.cn/img_convert/0b0e2f2769cdfd5e4e491faa12633033.png#pic_center)



## {#t17}6. 使用固定公网TCP端口地址远程连接


### {#t18}6.1 浏览器访问


在浏览器上访问固定公网TCP端口地址，测试正常。



![](https://img-blog.csdnimg.cn/img_convert/00834fa58b8fb484d6fc59c91199e513.png#pic_center)



### {#t19}6.2 映射本地盘符


使用固定公网tcp端口地址连接



![](https://img-blog.csdnimg.cn/img_convert/bb818cb06f5f1d298eea1cd755902c98.png#pic_center)



连接成功



![](https://img-blog.csdnimg.cn/img_convert/2541c7b690c29a4888ef212d0349b57a.png#pic_center)



### {#t20}6.3 通过RaiDrive客户端访问


打开RaiDrive，修改一下之前的虚拟盘符的链接，将其改为我们配置成功的公网TCP端口地址，并点击连接即可。



![](https://img-blog.csdnimg.cn/img_convert/40407360963902947e8c1d62ed06539f.png#pic_center)



## {#t21}图书推荐


![](https://img-blog.csdnimg.cn/e4c54be6276a457a9220252ec2d685e3.jpeg#pic_center)



【内容简介】  
　Git是一款让人一开始觉得很容易学，但却很难精通的工具。本书除了介绍Git的相关知识外，还会模拟各种常见的状况，让读者知道应该在什么时候使用什么指令。  
　　《Git从入门到精通》共分11个章节，1~3 章介绍安装工具及环境，对于已经安装完成的读者可直接从第4章开始阅读。第5章介绍Git基本的使用方式，虽然难度不高，但却是整个Git系统的基础。第6章介绍Git中常用的分支功能以及使用情境，第7~9章则是介绍如何修改现有的历史记录、使用标签，以及如何应对其他常见的状况。  
　　前面的内容都是在自己的计算机上就可以完成的，从第10章开始介绍如何将自己计算机里的记录推一份到线上（GitHub）。*后一章（第11章）介绍团队开发时可能会使用的开发过程Git Flow。  
　　市面上的参考书籍或网络教程大多是教大家如何通过终端机指令来学习Git，这让不少想学习Git的新手打了退堂鼓。本书除了教大家如何在终端机视窗中输入Git指令，还搭配了图形界面工具，缓和了读者的学习曲线，让读者更容易上手。



评论区留言：人生苦短，我用cpolar，抽取两名幸运观众。



京东自营购买链接：[点击跳转](https://item.jd.com/12793056.html)



[跳转到 Cubox 查看](https://cubox.pro/my/card?id=7122168450868317885)

