<template>
  <q-page class="background row">
            <SideBar></SideBar>


<SideBar></SideBar>
<div class="BoxWithBoxIn column flex items-center ">
  <login class="Abox column justify-center items-center"></login>

</div>


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
.bruh{
  background-color:blue;
}

.Abox {
  opacity: 95%;
  box-shadow: 3px 3px 5px;
  background-image: url("./../../public/icons/wallpaper1.jpg");
}
</style>
