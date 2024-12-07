<template>
    <div>{{ msg }}</div>
</template>

<script setup>
import {ref} from 'vue'
let msg = ref('不积跬步,无以至千里') 

setTimeout(() => {
    console.log("更新前", msg.value)
    msg.value = '不积小流,无以成江海'
    console.log("更新后", msg.value)
}, 2000)

</script>

<style></style>