<template>
  <q-page class="row bg-grey">
    <SideBar></SideBar>
    <div class="BoxWithBoxIn bg-red column flex justify-center items-center justify-around">
      <div class="Abox bg-pink flex row justify-end">

        <img class="picture q-ma-xl" src="../../public/icons/bild_på_växthus_här.png">

        <q-slider class="" v-model="value" :min="10" :max="50" :step="1" label color="light-green" />

      </div>
      <div class="Abox bg-yellow">

      </div>
      <div class="Abox bg-pink">

      </div>
    </div>


  </q-page>
</template>

<script setup>
import SideBar from "src/components/SideBar.vue"
import { ref } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseList } from 'vuefire'
import { ref as dbref } from 'firebase/database'

const value = ref(0)

</script>

<style>
.BoxWithBoxIn {
  margin-left: 5%;
  margin-top: 30px;
  margin-bottom: 30px;
  width: 145vh;
  height: 200vh;
}

.Abox {
  width: 130vh;
  height: 60vh;
}

.picture {
  width: 60vh;
  height: 40vh;
}
</style>
