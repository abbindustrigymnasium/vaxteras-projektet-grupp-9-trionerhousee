
<template>
  <q-page class="background row">

    <SideBar></SideBar>
    <div class="BoxWithBoxIn column flex justify-center items-center justify-around">
      <div class="Abox bg-amber-1 column justify-center">
        <chart1></chart1>

      </div>


      <div class="Abox bg-amber-1 column justify-center">
        <chart2></chart2>

      </div>


      <div class="Abox bg-amber-1 column justify-center">

      </div>
    </div>


</q-page>
</template>

<script setup>
import SideBar from "src/components/SideBar.vue"
import Chart1 from "src/components/ChartComp1.vue"
import Chart2 from "src/components/ChartComp2.vue"
import { ref } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseObject } from 'vuefire'
import { ref as dbref, set } from 'firebase/database'

const liveData = useDatabaseObject(dbref(db, 'LiveData'))





</script>

<style>
.background {
  background-image: url("../../public/icons/Wall_of_Ivy_Leaves_1.jpg");
}
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
</style>
