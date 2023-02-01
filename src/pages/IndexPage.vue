
<template>
  <q-page class="background row" v-if="liveData != null">

    <SideBar></SideBar>
    <div class="BoxWithBoxIn column flex justify-center items-center justify-around">
      <div class="Abox bg-amber-1 column justify-center">
        <div class="boxforstatus bg-amber-1 column items-center q-ml-xl q-pa-lg">
          <h3 class="stateText fontsize-60">Luckan är</h3>
          <h1 class="stateText text-weight-bold" v-if="lucka">öppen</h1>
          <h1 class="stateText text-weight-bold" v-else>stängd</h1>

          <h3 class="stateText">och kommer </h3>
          <h3 class="stateText" v-if="lucka">stängas vid</h3>
          <h3 class="stateText" v-else>öppnas vid</h3>
          <h1 class="stateText text-weight-bold" v-if="lucka"> {{ dataSettings.luckaTempSetting - 1 }}°C</h1>
          <h1 class="stateText text-weight-bold" v-else> {{ dataSettings.luckaTempSetting }}C°</h1>
        </div>


        <img class="picture q-ma-xl" src="../../public/icons/bild_på_växthus_här.png">
        <div class="row justify-start">
          <q-slider class="slider q-ml-xl" v-model="valueLucka" :min="10" :max="50" :step="1" label color="light-green"
            track-size="4vh" thumb-size="6vh" />
          <q-btn color="light-green" class="buttono q-ml-xl">
            <img class="buttono" src="../../public/icons/Send_icon.png" @click="uploadSlider1" />
          </q-btn>
        </div>
      </div>



      <div class="Abox bg-amber-1 column justify-center">
        <div class="q-ml-xl">
          <img class="picture q-ma-xl" src="../../public/icons/bild_på_växthus_här.png">

          <div class="row justify-start">
            <q-slider class="slider q-ml-xl" v-model="valueFlakt" :min="10" :max="50" :step="1" label
              color="light-green" track-size="4vh" thumb-size="6vh" />
            <q-btn color="light-green" class="buttono q-ml-xl">
              <img class="buttono" src="../../public/icons/Send_icon.png" @click="uploadSlider2" />
            </q-btn>
          </div>
        </div>
        <div class="boxforstatus bg-amber-1 column items-center q-mr-xl q-pa-lg">
          <h3 class="stateText">Fläkten är</h3>
          <h1 class="stateText text-weight-bold" v-if="flakt">PÅ</h1>
          <h1 class="stateText text-weight-bold" v-else>AV</h1>

          <h3 class="stateText">och kommer </h3>
          <h3 class="stateText" v-if="flakt">stängas av vid</h3>
          <h3 class="stateText" v-else>sättas på vid</h3>
          <h1 class="stateText text-weight-bold" v-if="flakt"> {{ dataSettings.FlaktTempSetting - 1 }}°C</h1>
          <h1 class="stateText text-weight-bold" v-else> {{ dataSettings.FlaktTempSetting }}°C</h1>
        </div>




      </div>
      <div class="Abox bg-amber-1 column justify-center">
        <div class="boxforstatus column items-center q-ml-xl q-pa-lg">
          <h1 class="stateText text-weight-bold">Regn</h1>
          <h3 class="stateText">inställningar</h3>

          <div class="boxButton column q-pa-md">
            <q-btn color="light-green q-mb-sm" @click="okenUpload">
              <h4 class="q-ma-sm q-px-xl">ÖKEN</h4>
              <div class="statusBox bg-red" v-if="oken"></div>
              <div class="statusBox" v-else></div>
            </q-btn>
            <q-btn color="light-green q-mb-sm" @click="grasmarkUpload">
              <h4 class="q-ma-sm">GRÄSMARK</h4>
              <div class="statusBox bg-red" v-if="grasmark"></div>
              <div class="statusBox" v-else></div>
            </q-btn>
            <q-btn color="light-green q-mb-sm" @click="regnskogUpload">
              <h4 class=" q-ma-sm q-pr-xs">REGNSKOG</h4>
              <div class="statusBox bg-red" v-if="regnskog"></div>
              <div class="statusBox" v-else></div>
            </q-btn>


          </div>


        </div>
        <img class="picture2 q-ma-xl" src="../../public/icons/bild_på_växthus_här.png">

      </div>
    </div>

    <div>
      <input type="email" v-model="email" />
      <input type="password" v-model="password" />
      <button @click="googleSign"> sign in with google</button>
    </div>


  </q-page>
</template>

<script setup>
import SideBar from "src/components/SideBar.vue"
import { ref, watch } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseObject } from 'vuefire'
import { ref as dbref } from 'firebase/database'
import { getAuth, signInWithPopup, GoogleAuthProvider } from "firebase/auth"

const provider = new firebase.auth.googleAuthProvider();
firebase.auth().signInWithPopup(provider);


const liveData = useDatabaseObject(dbref(db, 'LiveData'))
const dataSettings = useDatabaseObject(dbref(db, 'dataSettings'))



const valueLucka = ref(0)
const valueFlakt = ref(0)

const lucka = ref(true)
const flakt = ref(true)
const oken = ref(false)
const grasmark = ref(false)
const regnskog = ref(false)

function uploadSlider1 () {

  set(dbref(db, 'dataSettings/luckaTempSetting'), valueLucka.value)

}
function uploadSlider2 () {

  set(dbref(db, 'dataSettings/FlaktTempSetting'), valueFlakt.value)

}

function okenUpload () {

  set(dbref(db, 'LiveData/oken'), true)
  set(dbref(db, 'LiveData/grasmark'), false)
  set(dbref(db, 'LiveData/regnskog'), false)

}

function grasmarkUpload () {

  set(dbref(db, 'LiveData/oken'), false)
  set(dbref(db, 'LiveData/grasmark'), true)
  set(dbref(db, 'LiveData/regnskog'), false)

}

function regnskogUpload () {

  set(dbref(db, 'LiveData/oken'), false)
  set(dbref(db, 'LiveData/grasmark'), false)
  set(dbref(db, 'LiveData/regnskog'), true)

}




watch(dataSettings, (val) => {
  if (val != null) {
    valueLucka.value = val.luckaTempSetting
    valueFlakt.value = val.FlaktTempSetting
  }

})

watch(liveData, (val2) => {
  if (val2 != null) {
    lucka.value = val2.GateOpen
    flakt.value = val2.fanON
    oken.value = val2.oken
    grasmark.value = val2.grasmark
    regnskog.value = val2.regnskog
  }

})


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

.picture {
  width: 60vh;
  height: 40vh;
}

.picture2 {
  width: 70vh;
  height: 50vh;
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
  width: 45vh;

}

.background {
  background-image: url("../../public/icons/Wall_of_Ivy_Leaves_1.jpg");
}

.buttono {

  height: 7vh;
  width: 7vh;
}

.statusBox {
  width: 4vh;
  height: 4vh;
  border-radius: 4px 4px 4px 4px;
}
</style>
