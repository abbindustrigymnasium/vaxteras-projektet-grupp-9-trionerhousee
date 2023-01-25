<template>
  <q-page class="row bg-grey">
    <SideBar></SideBar>
    <div class="BoxWithBoxIn bg-red column flex justify-center items-center justify-around">
      <div class="Abox bg-pink column justify-center">
        <div class="boxforstatus bg-blue column items-center q-ml-xl q-pa-lg">
          <h3 class="stateText">Luckan är</h3>
          <h1 class="stateText text-weight-bold" v-if="lucka">öppen</h1>
          <h1 class="stateText text-weight-bold" v-else>stängd</h1>

          <h3 class="stateText">och kommer </h3>
          <h3 class="stateText" v-if="lucka">stängas vid</h3>
          <h3 class="stateText" v-else>öppnas vid</h3>
          <h1 class="stateText text-weight-bold" v-if="lucka"> {{ valueLucka - 1 }}°C</h1>
          <h1 class="stateText text-weight-bold" v-else> {{ valueLucka }}C°</h1>
        </div>


        <img class="picture q-ma-xl" src="../../public/icons/bild_på_växthus_här.png">

        <q-slider class="slider q-mx-xl" v-model="valueLucka" :min="10" :max="50" :step="1" label color="light-green"
          track-size="30px" thumb-size="60px" />

      </div>
      <div class="Abox bg-yellow column justify-center">
        <img class="picture q-ma-xl" src="../../public/icons/bild_på_växthus_här.png">

        <q-slider class="slider q-mx-xl" v-model="valueLucka" :min="10" :max="50" :step="1" label color="light-green"
          track-size="30px" thumb-size="60px" />
        <div class="boxforstatus bg-blue column items-center q-ml-xl q-pa-lg">
          <h3 class="stateText">Fläkten är</h3>
          <h1 class="stateText text-weight-bold" v-if="lucka">PÅ</h1>
          <h1 class="stateText text-weight-bold" v-else>AV</h1>

          <h3 class="stateText">och kommer </h3>
          <h3 class="stateText" v-if="lucka">stängas av vid</h3>
          <h3 class="stateText" v-else>sättas på vid</h3>
          <h1 class="stateText text-weight-bold" v-if="lucka"> {{ valueLucka - 1 }}°C</h1>
          <h1 class="stateText text-weight-bold" v-else> {{ valueLucka }}°C</h1>
        </div>




      </div>
      <div class="Abox bg-green column justify-center">
        <div class="boxforstatus bg-blue column items-center q-ml-xl q-pa-lg">
          <h4 class="stateText">Bevattningen är</h4>
          <h1 class="stateText text-weight-bold" v-if="lucka">PÅ</h1>
          <h1 class="stateText text-weight-bold" v-else>AV</h1>

          <h3 class="stateText">och kommer </h3>
          <h3 class="stateText" v-if="lucka">stängas vid</h3>
          <h3 class="stateText" v-else>öppnas vid</h3>
          <h1 class="stateText text-weight-bold" v-if="lucka"> {{ valueLucka - 1 }}%RH</h1>
          <h1 class="stateText text-weight-bold" v-else> {{ valueLucka }}%RH</h1>
        </div>


        <img class="picture q-ma-xl" src="../../public/icons/bild_på_växthus_här.png">

        <q-slider class="slider q-mx-xl" v-model="valueLucka" :min="10" :max="100" :step="1" label color="light-green"
          track-size="30px" thumb-size="60px" />

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

const valueLucka = ref(11)

//Lucka!!
const lucka = ref(true)



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

.stateText {
  margin: 0px;
  padding: 010px;



}

.boxforstatus {
  height: 53vh;
  width: 40vh;
}

.slider {
  width: 60vh;

}
</style>
