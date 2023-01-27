
<template>
  <q-page class="background row">

    <SideBar></SideBar>
    <div class="BoxWithBoxIn column flex justify-center items-center justify-around">
      <div class="Abox bg-amber-1 column justify-center">

      </div>


      <div class="Abox bg-amber-1 column justify-center">

      </div>


      <div class="Abox bg-amber-1 column justify-center">

      </div>
    </div>


  </q-page>
</template>

<script setup>
import SideBar from "src/components/SideBar.vue"
import { ref } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseObject } from 'vuefire'
import { ref as dbref, set } from 'firebase/database'

const liveData = useDatabaseObject(dbref(db, 'LiveData'))





</script>

<style>
.BoxWithBoxIn {
  margin-left: 8vh;
  margin-top: 30px;
  margin-bottom: 30px;
  width: 140vh;
  height: 200vh;
}

.Abox {
  width: 130vh;
  height: 60vh;
  border-radius: 20px 20px 20px 20px;
}


.background {
  background-image: url("../../public/icons/Wall_of_Ivy_Leaves_1.jpg");
}
</style>
