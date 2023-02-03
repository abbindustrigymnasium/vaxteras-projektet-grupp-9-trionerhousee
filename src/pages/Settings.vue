<template>
  <q-page class="background row">
    <SideBar></SideBar>

    <div>Welcome to settings</div>
    <login ></login>

  </q-page>

</template>

<script setup>
import SideBar from "src/components/SideBar.vue"
import login from "../components/login.vue"

</script>

<style>
.background {
  background-image: url("../../public/icons/Wall_of_Ivy_Leaves_1.jpg");
}
</style>
