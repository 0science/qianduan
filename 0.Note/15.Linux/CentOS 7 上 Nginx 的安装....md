# CentOS 7 上 Nginx 的安装、配置和使用


[juejin.cn](https://juejin.cn/post/7033349217359921183)程序猿秃头之路



前不久，一个项目开发完成要上线，作为项目主开发的我也要负责一下部署。



项目是前后端分离的微服务架构：`Spring Cloud 、Vue+ElementUI`。在测试环境是直接 jar 包部署各微服务模块，前端直接是 npm run dev 启动。



部署到正式环境，前端要将 `build` 之后的项目放在 `nginx` 中启动，并配置 `https`，由于我之前也没有配过 `nginx`，所以踩了很多坑，仅写这篇博客当做笔记。



## 简介


**Nginx**是一款开源的、跨平台的高性能web服务器，它有着高性能，稳定性高，配置简单，模块结构化，资源消耗低的优点。同时支持反向代理、负载均衡、缓存的功能。其采用多进程+epoll(IO多路复用)模型，也对互联网高并发连接业务有着很好的支持。



## CentOS 安装 Nginx


### A. 依赖环境安装


`要安装 nginx，要先安装 nginx 的依赖环境：gcc-c++、openssl、pcre、zlib`



**1. 安装 gcc-c++ 编译器和 openssl**



```plain
        r

    
        
复制代码

   
       
  
      yum install gcc-c++ 
yum install -y openssl openssl-devel
```



**2. 安装 pcre 包**



```plain
        复制代码

   
       
  
      yum install -y pcre pcre-devel
```



**3. 再安装 zlib 包**



```plain
        复制代码

   
       
  
      yum install -y zlib zlib-devel
```



### B. Nginx 安装


`依赖环境安装完成后，我们开始安装 nginx`



**1. 在 /usr/local/ 目录下创建 java 文件夹**



当然这个文件夹只是我用来放 nginx 安装包的



```plain
        bash

    
        
复制代码

   
       
  
      cd /usr/local
mkdir java
cd java/
```



**2. 使用 wget 命令直接下载 nginx 安装包，也可以直接上传下载好的压缩包**



```plain
        arduino

    
        
复制代码

   
       
  
      wget https://nginx.org/download/nginx-1.14.0.tar.gz
```



**3. 解压并进入解压好的目录**



```plain
        bash

    
        
复制代码

   
       
  
      tar -zxvf nginx-1.14.0.tar.gz 
cd nginx-1.14.0/
```



**4. 使用 nginx 默认配置**



```plain
        bash

    
        
复制代码

   
       
  
      ./configure
```



**5. 编译安装**



```plain
        go

    
        
复制代码

   
       
  
      make
make install
```



如果没有报错，那么你的 `/usr/local/`目录下会多出一个 `nginx/` 目录（默认安装目录）



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fp3-juejin.byteimg.com%2Ftos-cn-i-k3u1fbpfcp%2F2293aba4503b4edd98581bdb2d690103~tplv-k3u1fbpfcp-zoom-in-crop-mark%3A1512%3A0%3A0%3A0.awebp%3F&valid=true)



进入这个目录看一下（我这里是因为我启动过了，多了一些文件）



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fp6-juejin.byteimg.com%2Ftos-cn-i-k3u1fbpfcp%2Fe195c323b8ac40e6995c4aafb99c75ba~tplv-k3u1fbpfcp-zoom-in-crop-mark%3A1512%3A0%3A0%3A0.awebp%3F&valid=true)



此时，说明 nginx 已经安装成功，可以启动了。



**6. 进入 /usr/local/nginx/sbin 目录执行启动命令**



```plain
        bash

    
        
复制代码

   
       
  
      ./nginx
```



**7. 查看是否启动成功**



```plain
        perl

    
        
复制代码

   
       
  
      ps -ef | grep nginx
```



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fp9-juejin.byteimg.com%2Ftos-cn-i-k3u1fbpfcp%2F9724c24c16e74dfe9744dd40ba7e8a29~tplv-k3u1fbpfcp-zoom-in-crop-mark%3A1512%3A0%3A0%3A0.awebp%3F&valid=true)



网页上访问自己的 ip 地址端口为 80 ，会出现下图欢迎页，至此，nginx `安装完成`。



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fp3-juejin.byteimg.com%2Ftos-cn-i-k3u1fbpfcp%2Fe1a95293388248c4bff6a13457d03303~tplv-k3u1fbpfcp-zoom-in-crop-mark%3A1512%3A0%3A0%3A0.awebp%3F&valid=true)



### C. 安装过程中的错误处理


上面安装过程的 第 5 步可能会出现如下错误



**错误一**



> src/os/unix/ngx_user.c:26:7: error: 'struct crypt_data' has no member named 'current_salt'
>



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fp6-juejin.byteimg.com%2Ftos-cn-i-k3u1fbpfcp%2F5451fe784a9044c69de37c591c9f27b7~tplv-k3u1fbpfcp-zoom-in-crop-mark%3A1512%3A0%3A0%3A0.awebp%3F&valid=true) 这个错误一般是服务器系统版本高或者 nginx 版本高。



`解决办法：`



在nginx安装文件夹下输入



```plain
        bash

    
        
复制代码

   
       
  
      vim src/os/unix/ngx_user.c
```



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fp6-juejin.byteimg.com%2Ftos-cn-i-k3u1fbpfcp%2F10204322394c4269b8f8b800eb2ade62~tplv-k3u1fbpfcp-zoom-in-crop-mark%3A1512%3A0%3A0%3A0.awebp%3F&valid=true) 注释掉红框中的代码然后保存退出重新 make 即可。



**错误二**



> cast between incompatible function types from 'size_t (*)(ngx_http_script_engine_t _)' {aka 'long unsigned int (_ )(struct _)'} to 'void (_ )(ngx_http_script_engine_t _)' {aka 'void (_)(struct *)'} [-Werror=cast-function-type]
>



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fp1-juejin.byteimg.com%2Ftos-cn-i-k3u1fbpfcp%2F200ccdcfe04348e587c344929117286d~tplv-k3u1fbpfcp-zoom-in-crop-mark%3A1512%3A0%3A0%3A0.awebp%3F&valid=true)



`解决办法：`



打开 vim objs/Makefile 把 -Werrori删掉 （-Werror，它要求GCC将所有的警告当成错误进行处理）



## 配置 nginx


上面启动的 nginx，我们是用默认的配置文件启动的，真实项目使用的时候，我们肯定要去修改 nginx 的默认配置的。



### A. 配置解析


使用如下命令查看上文中安装的 nginx 的默认配置文件：



```plain
        bash

    
        
复制代码

   
       
  
      vim /usr/local/nginx/nginx-1.14.0/conf/nginx.conf
```



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fp9-juejin.byteimg.com%2Ftos-cn-i-k3u1fbpfcp%2F2dc9e8c0644543118f409e0b12932f3d~tplv-k3u1fbpfcp-zoom-in-crop-mark%3A1512%3A0%3A0%3A0.awebp%3F&valid=true)



这里只截取部分。下面我将列出 nginx 配置文件中的主要配置块的含义：



```plain
        ini

    
        
复制代码

   
       
  
      ...              #全局块

events {         #events块
   ...
}

http      #http块
{
    ...   #http全局块
    server        #server块
    { 
        ...       #server全局块
        location [PATTERN]   #location块
        {
            ...
        }
        location [PATTERN] 
        {
            ...
        }
    }
    server
    {
      ...
    }
    ...     #http全局块
}
```



1、**全局块**：配置影响nginx全局的指令。一般有运行nginx服务器的用户组，nginx进程pid存放路径，日志存放路径，配置文件引入，允许生成worker process数等。



2、**events块**：配置影响nginx服务器或与用户的网络连接。有每个进程的最大连接数，选取哪种事件驱动模型处理连接请求，是否允许同时接受多个网路连接，开启多个网络连接序列化等。



3、**http块**：可以嵌套多个server，配置代理，缓存，日志定义等绝大多数功能和第三方模块的配置。如文件引入，mime-type定义，日志自定义，是否使用sendfile传输文件，连接超时时间，单连接请求数等。



4、**server块**：配置虚拟主机的相关参数，一个http中可以有多个server。



5、**location块**：配置请求的路由，以及各种页面的处理情况。



我们一般主要配置的就是 http 块下的`server` 块。



### B. 配置实战


**1. 部署 npm build 之后的前端资源**



将 build 出来的 dist 文件夹放在 `/usr/local/nginx/html/` 路径下（也可以是其他路径，不固定）



然后，修改 nginx.config 配置文件：



```plain
        bash

    
        
复制代码

   
       
  
          location / {
            root /usr/local/nginx/html/dist;
            index index.html index.htm;
            try_files $uri $uri/ /index.html; # 配置使用路由
    }
```



> 这三行的意思是如果第一个存在，直接返回；不存在的话读取第二个，如果存在，读取返回；如果还是不存在，就会fall back到 try_files 的最后一个选项 /index.html,发起一个内部 "子请求"，也就是相当于 nginx 发起一个 HTTP 请求到 [http://localhost:80/index.html。](https://link.juejin.cn/?target=http%3A%2F%2Flocalhost%3A80%2Findex.html%25E3%2580%2582) 保存修改之后，重新启动 nginx：
>



```plain
        bash

    
        
复制代码

   
       
  
      cd /usr/local/nginx/sbin
./nginx -s reload
```



此时，前端已经部署好了，接下来我们来配置后端各个微服务的部署



**2. jar 包部署各个微服务，并配置 nginx**



首先，假设 jar 包也部署在这台有 nginx 服务的服务器上，我们需要先启动各个微服务



```plain
        bash

    
        
复制代码

   
       
  
      nohup java -jar xxx.jar > xxx.log & tail -f xxx.log     # 这里的命令不再解释
```



然后开始修改 nginx.config 配置文件:



```plain
        bash

    
        
复制代码

   
       
  
          location ^~ /erowplatform {
            proxy_pass https://localhost:8088/erowplatform;
    }

    location ^~ /gcgk {
            proxy_pass https://localhost:8088/gcgk;
    }

    location ^~ /auth {
            proxy_pass https://localhost:8088/auth;
    }


    location ^~ /code {
            proxy_pass https://locahost:8088/code;
    }

    location ^~ /ytb {
            proxy_pass https://localhost:8088/ytb;
    }
```



接下来我们来配置 https。



**3. 配置 https**



假设，你已经有了要配置 https 所需要的证书，至于证书的获取方式，本文不再叙述。



针对此项目，后端用 jar 包启动，我们需要`先在代码中配置 https`：



将你的证书放在`网关模块`下的 resources 下：xxx.pfx



然后修改 bootstrap.yml 文件：



```plain
        java

    
        
复制代码

   
       
  
      server:
  port: 8080
  ssl:
    key-store: classpath:xxx.pfx
    key-store-password: 123456
    key-store-type: PKCS12
    enabled: true #开启HTTPS
```



此时访问后端接口就要使用 https 了。



接下来我们来`配置 nginx.conf`,



先将 nginx 使用的两个证书文件（xxx.pem、xxx.key）放在某个路径下。



修改 server 块，正确指向证书所在路径：



```plain
        ini

    
        
复制代码

   
       
  
          ssl on;
    #ssl证书的pem文件路径
    ssl_certificate  /etc/nginx/conf.d/3997458__xxx.cn.pem;
    #ssl证书的key文件路径
    ssl_certificate_key /etc/nginx/conf.d/3997458__xxx.cn.key;

    ssl_session_timeout 5m;
    ssl_protocols TLSv1 TLSv1.1 TLSv1.2;
    ssl_ciphers ECDHE-RSA-AES128-GCM-SHA256:HIGH:!aNULL:!MD5:!RC4:!DHE;
    ssl_prefer_server_ciphers on;
```



然后保存修改重启 nginx。



下面贴出完整的 myconfig.conf



```plain
        java

    
        
复制代码

   
       
  
      server {
    #监听8080端口
    listen 8080;
    #对应的域名
    server_name yyt.xxx.cn;
    ssl on;
    #ssl证书的pem文件路径
    ssl_certificate  /etc/nginx/conf.d/3997458__xxx.cn.pem;
    #ssl证书的key文件路径
    ssl_certificate_key /etc/nginx/conf.d/3997458__xxx.cn.key;

    ssl_session_timeout 5m;
    ssl_protocols TLSv1 TLSv1.1 TLSv1.2;
    ssl_ciphers ECDHE-RSA-AES128-GCM-SHA256:HIGH:!aNULL:!MD5:!RC4:!DHE;
    ssl_prefer_server_ciphers on;
    client_max_body_size 500M;
    proxy_set_header X-Forwarded-Host $host;
    proxy_set_header X-Forwarded-Server $host;
    proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;

    location / {
            root /etc/nginx/html/dist;
            index index.html index.htm;
            try_files $uri $uri/ @router; # 配置使用路由
    }

    location ^~ /erowplatform {
     proxy_pass https://localhost:8088/erowplatform;
    }

    location ^~ /gcgk {
            proxy_pass https://localhost:8088/gcgk;
    }

    location ^~ /auth {
            proxy_pass https://localhost:8088/auth;
    }


    location ^~ /code {
            proxy_pass https://localhost:8088/code;
    }

    location ^~ /ytb {
            proxy_pass https://localhost:8088/yyt;
    }


    # 路由配置信息
    location @router {
             rewrite ^.*$ /index.html last;
    }
}
```



域名是映射到服务器地址的。



为什么是 myconfig.conf 呐？



是因为我将配置文件单独放了，只需要原来的 nginx.conf 指向 myconfig.conf 即可。



```plain
        bash

    
        
复制代码

   
       
  
              include /etc/nginx/conf.d/*.conf;
        #include /etc/nginx/sites-enabled/*;
```



myconfig.conf 放在 `/etc/nginx/conf.d/` 下。



至此，配置完成。



## 补充


**https 默认访问的是 443 端口**



假如访问 `https://yyt.xxx.cn` 地址，实际上相当于访问 `https://yyt.xxx.cn:443` 地址。



所以可以将上面 myconfig.conf 文件中的监听端口改为 443。不加端口号默认访问。



**http 默认访问的 80 端口**



假如访问 `http://yyt.xxx.cn` 地址，实际上相当于访问 `http://yyt.xxx.cn:80` 地址。



由此，我们可以这样配置让访问 `http` 的用户重定向到 `https`：



myconfig.conf 中新增一个 server



```plain
        perl

    
        
复制代码

   
       
  
      server { 
     listen 80; server_name localhost; 
     rewrite ^(.*) https://$server_name$1 permanent; 
    }
```



[跳转到 Cubox 查看](https://cubox.pro/my/card?id=7175079757460016627)

