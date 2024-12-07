<template>
    <input v-model="msg" type="text">
</template>

<script setup>
import { ref, watch } from 'vue'

const msg = ref('Hello World')

watch(msg, (newValue, oldValue) => {
    console.log(newValue, oldValue)
})

</script>

<style>

</style>