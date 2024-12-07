# 一. **项目背景**

本次开发的目的是打造一个类似美团的电商app，主要实现了页面布局、页面跳转、数据引用等基础功能，搭建一个拥有浏览、登录、收藏、加购物车、下单等基础模块的app，采用了vue框架搭建。

# 二. **需求分析**

1. **登录功能**：用户在登录前仅可浏览首页和分类页面，登录后可浏览

2. **购物车功能**：用户能够将物品添加到购物车之中

3. **收藏功能**：用户能够将物品添加到收藏夹之中

4. **购买功能**：用户能够下单购买所选物品

# **三．数据库设计**

![](file:///C:\Users\djm\AppData\Local\Temp\ksohtml14632\wps1.jpg) 

E-R图

# **四．详细设计说明**

![](file:///C:\Users\djm\AppData\Local\Temp\ksohtml14632\wps2.jpg) 

# 五．**系统实现（核心功能代码以及拓展功能部分代码）**

**登录功能**

<script>

import { ref } from "vue";

import axios from "axios";

import { Toast } from "vant";

import router from "@/router";

export default {

  setup() {

    const username = ref("");

    const password = ref("");

    const onSubmit = (values) => {

      console.log("submit", values);

      axios({

        method: "POST",

        url: "http://47.115.51.185/api/login",

        data: {

          account: values.username,

          password: values.password,

        },

      }).then(function (res) {

        if (res.data.status == 200) {

          console.log("密码输入正确");

          Toast("登录成功，请稍后");

          router.push({

                path:"/my"

          });

          localStorage.setItem("token", res.data.token);

          }else if (res.data.status == 400) {

          Toast("账号密码输入错误，请重输入");

        }

      });

    };

    return {

      username,

      password,

      onSubmit,

    };

  },

};

</script>

**购物车功能**

<script>

import { ref, computed } from "vue";

import { useStore } from "vuex";

import { useRouter } from "vue-router";

export default {

  name: "cart",

  setup() {

    var router=useRouter()

    var store = useStore();

    var cartListData = ref(store.state.cartList);

    // console.log(cartListData.value.length)

    var getTotal = computed(function () {

      var totalPrice = 0;

      cartListData.value.forEach(function (item) {

        totalPrice += Number(item.price);

      });

      return totalPrice;

    });

    console.log(getTotal.value);

    // console.log("cartListData=>",cartListData)

    // console.log("cartListData.value",cartListData.value)

    // console.log(getTotal.value)

    var del = function (index) {

      console.log("你正在点击删除按钮");

      console.log(index);

      cartListData.value.splice(index, 1);

    };

    var goDetail = function (item) {

      console.log("你在点击跳转");

      var detail = JSON.stringify(item);

      console.log(item.store_name);

      router.push({

        path: "/detail",

        query: {

          detail,

        },

      });

    };

    return {

      cartListData,

      getTotal,

      del,

      goDetail,

    };

  },

};

</script>

**收藏功能**

<script>

import {ref,computed}from "vue"

import { useStore } from "vuex";

import { useRouter } from "vue-router";

export default {

    name:"cart",

    setup(){

        var router=useRouter()

        var store=useStore()

        var collectListData = ref(store.state.collectList);

//计算购物车总价

var getTotal=computed(function(){

    var totalPrice = 0

    collectListData.value.forEach(function(item){

  totalPrice += Number(item.price)

})

return totalPrice

})

console.log(getTotal.value)

var del=function(index){

console.log(index)

collectListData.value.splice(index,1)

}

 var goDetail=function(item){

        console.log("你在点击跳转");

var detail=JSON.stringify(item)

        console.log(item.store_name);

        router.push({

            path:"/detail",

            query:{

             detail

            }

        })

    }

        return{

            collectListData,

            getTotal,

            del,

            goDetail

        }

    }

}

</script>

**购买功能**

<script>

import { useRoute } from 'vue-router'

import { ref,computed } from 'vue'

import { Toast } from 'vant'

export default{

    setup(){

        var num = ref(1)

        var route = useRoute()

         var  goBack = function(){

    history.back()

 }

 var orderDetail = JSON.parse(route.query.detail)

 console.log(orderDetail)

 var add = function(){

    num.value ++

 }

 var sub = function(){

    num.value --

    if(num.value < 1){

        num.value = 1

        Toast("再减就没有了")

    }

 }

  return{

    goBack,orderDetail,add,num,sub

  }

 }

}

</script>

# 六．**项目运行效果**

1. 登录功能

![](file:///C:\Users\djm\AppData\Local\Temp\ksohtml14632\wps3.jpg)          ![](file:///C:\Users\djm\AppData\Local\Temp\ksohtml14632\wps4.jpg)

2. 购物车功能

![](file:///C:\Users\djm\AppData\Local\Temp\ksohtml14632\wps5.jpg) 

3. 收藏功能

![](file:///C:\Users\djm\AppData\Local\Temp\ksohtml14632\wps6.jpg)          ![](file:///C:\Users\djm\AppData\Local\Temp\ksohtml14632\wps7.jpg)

4. 购买功能

![](file:///C:\Users\djm\AppData\Local\Temp\ksohtml14632\wps8.jpg) 

# **七．测试分析（测试数据及调试时错误描述）**

问题1：购物车价格不能正常显示

解决方法：

1. 检查报错信息，未发现拼写错误

2. 发现 totalPrice = Number(item.price); 有歧义，价格一直显示为定值

3. 修改为 totalPrice += Number(item.price); ，可正常显示商品总价

4. 问题解决

问题2：打包后的dist文件中的html网页不能正常打开

解决方法：

1. 检查拼写错误，发现createWebHashHistory拼写错误后修正

2. 网页可正常打开

3. 问题解决

# 七．**课程实训总结**

知识点：

1. 了解了移动端 Vue 组件库vant，从前编程要么是模仿他人，要么自己造轮子，现在终于知道了原来可以使用现成的组件来编写程序，编程也可以变得如此简单

2. 学会了许多vue指令，例如v-for，v-show，v-if；还有vue路由vue-router的添加和配置参数

收获和建议

1. 发现自己所掌握的知识还远远不够，活到老，学到老

2. 不懂得问题还是得找专业的人请教，这样才能进步的更快

3. 一个人学习的热情总是有限的，大家一起学习，一起讨论更能激发斗志，能学得更持久

# **参考文献**

[1] 吕云翔，《软件工程理论与实践》，机械工业出版社

[2] 传智播客高教产品研发部，《HTML5+CSS3网站设计基础教程》，人民邮电出版社

[3] Matt Frisbie著 李松峰译，《JavaScript高级程序设计》 ，人民邮电出版社

# **附录**

用户名：13565659698

密码：admin8899