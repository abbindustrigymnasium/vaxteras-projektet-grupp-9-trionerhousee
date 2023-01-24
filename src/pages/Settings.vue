<template>
  <q-page class="row bg-grey">
    <q-page-sticky position="right" :offset="[30, 30]">
      <SideBar></SideBar>
    </q-page-sticky>
    <div>Welcome to settings</div>
  </q-page>
</template>

<script setup>
import SideBar from "src/components/SideBar.vue"
</script>
