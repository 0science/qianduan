【速查速记】Linux命令

## 防火墙命令

```
#查看防火墙状态  
systemctl status firewalld  
#开启防火墙  
systemctl start firewalld  
#关闭防火墙  
systemctl stop firewalld  
#重启防火墙  
systemctl restart firewalld  
# 重新加载防火墙  
firewall-cmd --reload  
firewall-cmd --complete-reload  
# 两者的区别就是第一个不会断开连接，就是firewalld特性之一动态添加规则，第二个会断开所有连接，类似重启服务加载  
```

## Git

```
git config --global --unset http.proxy 
git config --global --unset https.proxy
```

