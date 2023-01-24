<template>
  <q-page class="row bg-grey">
    <q-page-sticky position="right" :offset="[30, 30]">
      <SideBar></SideBar>
      <pre> {{todos}}</pre>
    </q-page-sticky>


  </q-page>
</template>

<script setup>
import SideBar from "src/components/SideBar.vue"
import { ref } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseList } from 'vuefire'
import { ref as dbref } from 'firebase/database'


const todos = useDatabaseList(dbref(db, 'todos'))
console.log(todos)
console.log('aaaa')
</script>
