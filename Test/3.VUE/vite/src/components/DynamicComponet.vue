<template>
    <button @click="showComponent = MyLeft">展示左边</button>
    <button @click="showComponent = MyRight ">展示右边</button>
    <div><component :is="showComponent"></component></div>
  </template>
  
  <script setup>
  import MyLeft from './MyLeft.vue'
  import MyRight from './MyRight.vue'
  import { shallowRef } from 'vue';

  const showComponent = shallowRef(MyLeft);

  </script>
  
  <style>
  
  </style>