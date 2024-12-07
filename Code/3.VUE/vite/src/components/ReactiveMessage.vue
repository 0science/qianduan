<template>
  <div>{{ obj.msg }}</div>
</template>

<script setup>
import { reactive } from 'vue'
const obj = reactive({
  msg: '不畏浮云遮望眼'
})

setTimeout(() => {
  obj.msg = '自缘身在最高层'
}, 2000)

</script>

<style></style>