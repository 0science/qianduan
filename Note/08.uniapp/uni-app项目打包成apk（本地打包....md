# uni-app项目打包成apk（本地打包篇）


[blog.csdn.net](https://blog.csdn.net/zxczero/article/details/126624787)成就一亿技术人!



最近可能要接一个[uni-app](https://so.csdn.net/so/search?q=uni-app&spm=1001.2101.3001.7020)的项目，之前没有接触过，因此学习了一下，好在uni-app基本算是vue和微信小程序的结合体，所以写代码方面问题不是太多，不懂的百度一下基本都能处理。写完demo之后，demo的内容应该能告诉客户我可以做，但我一开始是先用手机录制视频，然后把录制的视频给客户看的。但这样不够好，因为不知道打包成apk后会遇到什么问题，因此还是自己摸索着去打包成可安装的apk，直接让客户试用。



下面的步骤，不要跳步，一步步看，肯定是可以成功的。



### {#t0}**1. 本次用到的工具:**


1.  代码开发工具：**HBuilder X** 
2.  apk打包工具：**Android Studio** 
3.  apk打包SDK：**Android离线SDK**（下载地址：[Android离线SDK](https://nativesupport.dcloud.net.cn/AppDocs/download/android)） 
4.  生成签名证书的工具：**jdk1.8** （网上说只要装jre就行，但jdk里包含jre，所以直接装jdk吧，jdk装完要配置环境变量，[jdk环境变量](https://so.csdn.net/so/search?q=jdk%E7%8E%AF%E5%A2%83%E5%8F%98%E9%87%8F&spm=1001.2101.3001.7020)的配置可以看这个：[jdk环境变量配置](https://www.bilibili.com/read/cv14139888)） 
5.  生成appkey的网站：DCLOUD的开发者中心（网址：[开发者中心](https://dev.dcloud.net.cn/#/pages/app/list)） 



### {#t1}2. 导出前的配置


在 **HBuilder X** 中打开uni-app项目中的 **mainifest.json**文件，会弹出来一些可配置的内容，这次我们简单一点，只配置基础配置。其中 **uni-app应用标识(AppID)**如果默认没有的话，点后面的 **重新获取**即可，它会警告你，不过点了没事，且会为你生成一个AppID。然后就是选择开发使用的vue版本，按实际选择即可，其它的貌似可以随便填（如果只是做打包测试的话）。



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2F332c167ff1ce40df9c537e84caad55d6.png&valid=false)



### {#t2}3. 导出uni-app项目供打包使用


项目代码在自己手机上测试运行成功后，我们需要把uni-app的项目导出。点击 **HBuilder X** 上方的 **发行** -->**原生App-本地打包** -->**生成本地打包App资源** 即可。如果是第一次点击，可能会提示你装什么东西，按提示的来，同意安装就可以了。



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2F06bb61fb22aa48d3b15fde9bb56a0645.png&valid=false)



导出成功后，**HBuilder X** 下方的控制台会告诉你导出路径。至此，**HBuilder X**的任务完成。



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2Feae7f81498c54355b25347c2ca763050.png&valid=false)



### {#t3} 4. 下载Android离线SDK


**Android离线SDK**下载地址：[Android离线SDK](https://nativesupport.dcloud.net.cn/AppDocs/download/android)



这个sdk可能不止用来打包apk，但目前我只是用来打包apk。



### {#t4} 5. 将HBuilder X导出的文件夹移动到离线SDK中


将刚才 **HBuilder X** 导出的以AppID命名的文件夹（www文件夹的上一级）整个移动到离线SDK的**HBuilder-Integrate-AS\simpleDemo\src\main\assets\apps**路径下，该路径下默认会有一个叫 **__UNI__A** 的文件夹，这个直接删除，我们用不到。



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2Ff3687d68676b43b7b6b7f419fc964535.png&valid=false)



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2F9352f1c249b645809ba94c4e27755771.png&valid=false)



### {#t5} 6. Android Studio 导入SDK中的示例项目


如果第一次安装 **Android Studio**，安装过程中会提示你缺啥好像，记不太清了，直接cancel那个提示，然后跟着引导一步步安装就行了，安装结束后，好像也没什么问题。



接着导入离线SDK中的 **HBuilder-Integrate-AS** 文件夹到 **Android Studio** 中。**注意：文件路径中不要出现中文！否则会报错！**



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2Fecb193a01ed3413aaa7bc6ec70262620.png&valid=false)



### {#t6}7. 修改dcloud_control.xml 中的 appid


接下来，别纠结截图中我 **Android Studio**的文件结构为什么你不一样，截图中有些文件夹或者路径好像被隐藏了，这不重要，我只是来打包的。



找到 assets/data 下的 **dcloud_control.xml**文件，点开它，将文件中appid的值，改成 **HBuilder X**中生成的appid。appid记不住没关系，还记得第5步中让你移动的那个文件夹吗，它的文件名就是appid



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2Fde6d4b9eb1d443ebb2d6bbcae17257f8.png&valid=false)



### {#t7}8. 生成Android证书签名


这一步我参考了别人的文章，所以不多讲了，按他的步骤做（jdk环境变量的配置虽然他文章里写了，小白最好还是看这个：[jdk环境变量配置](https://www.bilibili.com/read/cv14139888)），记下生成证书的文件路径、证书的SHA1安全码、证书的alias（别名）以及设置的两个密码（怕忘记，两个密码设一样的），后续步骤会用得到。参考网址（[生成Android证书签名](https://blog.csdn.net/qq_44693047/article/details/125089245)）。



### {#t8}9. 生成appkey


前往 DCLOUD 的开发者中心（网址：[开发者中心](https://dev.dcloud.net.cn/#/pages/app/list)），如果按照我的步骤做，那在第2步 **HBuilder X**中生成appid后，就能在开发者中心我的应用中看到这条应用，点击应用名称会跳转到该条应用的管理页面。



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2F9585547c6a524761af537d531e3dbf2f.png&valid=false)



点击上方的 **离线打包Key管理**按钮，进入生成appkey的菜单。我的这个菜单是已经生成appkey的，所以会和你第一次点进来有所不同，不用担心。



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2F5a7c435c465e48a2bdd542639fc4c3be.png&valid=false)



**选择平台：**我们选择Android，因为我们这次是打包apk。



**Android包名：****包名不能随便写，否则安装apk打开后会报错！** 它的值在离线SDK的 \HBuilder-Integrate-AS\simpleDemo\src\main\**AndroidManifest.xml** 中，没改过的话应该跟我一样，是 com.android.simple



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2F922fd4bb5e1f48aea7881cfca66b6631.png&valid=false)



**Android证书签名SHA1**：第8步中让你记下的SHA1安全码。



这些填完后，点确认还是啥的，应该就可以生成appkey了。



### {#t9}10. 在 **AndroidManifest.xml 中配置appKey**


回到**Android Studio** ，在 **AndroidManifest.xml** 中配置appKey![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2F71f7cde4a0d04d44bac499846c3a3652.png&valid=false)



### {#t10}11. 打包apk


现在万事俱备，只剩打包了，点击 **Android Studio** 上方的 **Build**-->**Generate Signed Bundle / APK...**



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2Fe2cb44eb834a4740bc775d8a21314ff9.png&valid=false)



弹出打包窗口，选择 **APK**，然后点击 **Next**



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2F4404540516da47debd921894279390a1.png&valid=false)



点击 **Choose existing...**，选择第8步让你记下的证书存放路径，**Key store path**就会自动填充，**Key store password、Key alias、key password** ，这三项也在第8步中设置。如果两个password记不住了，那就按第8步的教程重新生成一个证书吧。**Remember passwords** 根据自己需要吧（小白还是勾吧，记住密码）。全部填完后点击下方 **Next**



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2F12da6dc9203a435d94c6d35e98fd5522.png&valid=false)



最后就是选择导出路径，然后选择 **release**，然后点击下方**Finish**。



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2Faf5ac105ee184c989d3c8e42730585bd.png&valid=false)



导出成功后，**Android Studio** 下方的 **Build**控制台会提示 **BUILD SUCCESSFUL** 。



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2F15fa82fc2998451baf6fbe97cd27d973.png&valid=false)



然后就可以在导出路劲的release文件夹里找到打包好的apk文件了，截图里的是默认导出路径，你可以在release的时候选择你的导出路径。



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2F71c5dcfef34740bda52369f831ceeb8f.png&valid=false)



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2Ff313833751a44b17b4311c0069ec5ed5.png&valid=false)



然后在手机上安装刚才的apk并打开，如果正常打开，那基本就成功了。



我在摸索的时候，打包成功后，安装到手机，打开app的时候提示**appkey不存在或配置错误**，后来发现是第9步生成appkey的时候，包名写错了，一定要和 **AndroidManifest.xml**文件中的包名一样。



![](https://cubox.pro/c/filters:no_upscale()?imageUrl=https%3A%2F%2Fimg-blog.csdnimg.cn%2F4db756fc0dec49c5b61a7d6e05af7db3.jpeg&valid=false)



更多进阶的内容，等我摸索完再发文章，多多点赞，感谢支持！



[跳转到 Cubox 查看](https://cubox.pro/my/card?id=7167868944626221066)

