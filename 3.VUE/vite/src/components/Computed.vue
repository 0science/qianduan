<template>
    <div>初始：{{ msg }}</div>
    <div>反转：{{ reversemsg }}</div>
</template>

<script setup>
import { ref, computed } from 'vue'

const msg = ref('Hello World')

const reversemsg = computed(() => {
    return msg.value.split('').reverse().join('')
})

</script>

<style>

</style>