<template>
  <div>{{ msg }}</div>
  <div>{{ obj.msg }}</div>
</template>

<script setup>
import {toRef } from 'vue'

const obj = {
  msg: '不积跬步,无以至千里'
}
</script>

<style>

</style>