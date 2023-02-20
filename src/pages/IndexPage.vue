
<template>

  <q-page class="background row" v-if="liveData != null">


    <SideBar></SideBar>

    <div class="BoxWithBoxIn flex justify-center items-center ">
        <div>
          <h2 id="welcomeUser" v-if="name != undefined "> Welcome back{{name}}</h2>
        </div>
      <div class="Abox bg-amber-1 column justify-center">

        <div class="boxforstatus bg-amber-1 column items-center q-ml-xl q-pa-lg">
          <div class="stateText">Luckan är</div>
          <div id="info" class="stateText text-weight-bold" v-if="lucka">öppen</div>
          <div id="info" class="stateText text-weight-bold" v-else>stängd</div>

          <div class="stateText">och kommer </div>
          <div class="stateText" v-if="lucka">stängas vid</div>
          <div class="stateText" v-else>öppnas vid</div>
          <div id="info" class="stateText text-weight-bold" v-if="lucka"> {{ dataSettings.luckaTempSetting - 1 }}°C</div>
          <div id="info" class="stateText text-weight-bold" v-else> {{ dataSettings.luckaTempSetting }}C°</div>
        </div>


        <img class="picture" src="../../public/icons/bild_på_växthus_här.png">
        <div class="row justify-start">
          <q-slider class="slider q-ml-xl" v-model="valueLucka" :min="10" :max="50" :step="1" label color="light-green"
            track-size="4vh" thumb-size="6vh" />
          <q-btn color="light-green" class="buttono q-ml-xl">
            <img class="buttono" src="../../public/icons/Send_icon.png" @click="uploadSlider1" />
          </q-btn>
        </div>
      </div>



      <div class="Abox bg-amber-1 column justify-center">
          <img class="picture2" src="../../public/icons/bild_på_växthus_här.png">

          <div class="row justify-start">
            <q-slider class="slider q-ml-xl" v-model="valueFlakt" :min="10" :max="50" :step="1" label
              color="light-green" track-size="4vh" thumb-size="6vh" />
            <q-btn color="light-green" class="buttono q-ml-xl">
              <img class="buttono" src="../../public/icons/Send_icon.png" @click="uploadSlider2" />
            </q-btn>
          </div>

        <div class="boxforstatus bg-amber-1 column items-center q-mr-xl q-pa-lg">
          <div class="stateText">Fläkten är</div>
          <div id="info" class="stateText text-weight-bold" v-if="flakt">PÅ</div>
          <div id="info" class="stateText text-weight-bold" v-else>AV</div>

          <div class="stateText">och kommer </div>
          <div class="stateText" v-if="flakt">stängas av vid</div>
          <div class="stateText" v-else>sättas på vid</div>
          <div id="info" class="stateText text-weight-bold" v-if="flakt"> {{ dataSettings.FlaktTempSetting - 1 }}°C</div>
          <div id="info" class="stateText text-weight-bold" v-else> {{ dataSettings.FlaktTempSetting }}°C</div>
        </div>




      </div>
      <div class="Abox bg-amber-1 column justify-center">



          <div class="boxButton column q-pa-md">
            <h3 class="heading">Regn inställningar</h3>
            <q-btn class="buttuno" color="light-green q-mb-sm" @click="okenUpload">
              <div class="buttonText q-ma-sm q-px-xl">ÖKEN</div>
              <div class="statusBox bg-red" v-if="oken"></div>
              <div class="statusBox" v-else></div>
            </q-btn>
            <q-btn class="buttuno" color="light-green q-mb-sm" @click="grasmarkUpload">
              <div class="buttonText q-ma-sm">GRÄSMARK</div>
              <div class="statusBox bg-red" v-if="grasmark"></div>
              <div class="statusBox" v-else></div>
            </q-btn>
            <q-btn class="buttuno" color="light-green q-mb-sm" @click="regnskogUpload">
              <div class="buttonText q-ma-sm q-pr-xs">REGNSKOG</div>
              <div class="statusBox bg-red" v-if="regnskog"></div>
              <div class="statusBox" v-else></div>
            </q-btn>


          </div>



        <img class="picture2" src="../../public/icons/bild_på_växthus_här.png">

      </div>
    </div>


  </q-page>
</template>

<script setup>
import SideBar from "src/components/SideBar.vue"
import { ref, watch } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseObject } from 'vuefire'
import { ref as dbref, set } from 'firebase/database'

const liveData = useDatabaseObject(dbref(db, 'LiveData'))
const dataSettings = useDatabaseObject(dbref(db, 'dataSettings'))



const valueLucka = ref(0)
const valueFlakt = ref(0)
const hum = ref(0)
const temp = ref(0)
const lucka = ref(true)
const flakt = ref(true)
const oken = ref(false)
const grasmark = ref(false)
const regnskog = ref(false)

let cookies = document.cookie

console.log(cookies)


let decodedCookie = decodeURIComponent(document.cookie)
let ca = decodedCookie.split(';')

for (let i = 0; i < ca.length; i++) {
  const nameStr = ca[i];
  if (nameStr.startsWith('name')) {
    let name = ca[4].replace('name=', '')
  }
}




console.log('name is', name);



function uploadSlider1 () {

  set(dbref(db, 'dataSettings/luckaTempSetting'), valueLucka._value)

}
function uploadSlider2 () {

  set(dbref(db, 'dataSettings/FlaktTempSetting'), valueFlakt.value)

}

function okenUpload () {

  set(dbref(db, 'dataSettings/oken'), true)
  set(dbref(db, 'dataSettings/grasmark'), false)
  set(dbref(db, 'dataSettings/regnskog'), false)

}

function grasmarkUpload () {

  set(dbref(db, 'dataSettings/oken'), false)
  set(dbref(db, 'dataSettings/grasmark'), true)
  set(dbref(db, 'dataSettings/regnskog'), false)

}

function regnskogUpload () {

  set(dbref(db, 'dataSettings/oken'), false)
  set(dbref(db, 'dataSettings/grasmark'), false)
  set(dbref(db, 'dataSettings/regnskog'), true)

}




watch(dataSettings, (val) => {
  if (val != null) {
    valueLucka.value = val.luckaTempSetting
    valueFlakt.value = val.FlaktTempSetting
    oken.value = val.oken
    grasmark.value = val.grasmark
    regnskog.value = val.regnskog
  }
})

watch(liveData, (val2) => {

  if (val2 != null) {

    lucka.value = val2.hatchStateWeb
    flakt.value = val2.fanOnWeb

    temp.value = val2.LiveTemp
    hum.value = val2.LiveLuft
  }

})

/*if (temp.value >= valueLucka.value) {
  if (lucka.value) {
    set(dbref(db, 'LiveData/hatchStateWeb'), false)
  } else {
    set(dbref(db, 'LiveData/hatchStateWeb'), true)
  }

}

if (temp.value >= valueFlakt.value) {
  if (flakt.value) {
    set(dbref(db, 'LiveData/fanOnWeb'), false)
  } else {
    set(dbref(db, 'LiveData/fanOnWeb'), true)
  }
}
*/


</script>

<style>
#info {
  font-weight: bolder;
  font-size: 4vw;
}
.heading {
  font-weight: bolder;
  height: 25%;
  font-size: 3.7vw;
  margin: 5%;
  text-align: center;

}
.boxforstatus {
  height: 100%;
  display: flex;
  width: 40%;
  padding: 2%;
  margin: 2%;
}
.stateText {
  font-size: 3.5vw;
  height: 20%;
  display: flex;

}
.BoxWithBoxIn {
  margin-left: 8vh;
  margin-top: 30px;
  margin-bottom: 30px;
  width: 65%;
  height: 200vh;
}

.Abox {
  display: flex;
  width: 100%;
  height: 60vh;
  border-radius: 20px 20px 20px 20px;
  margin: 3vh;
  box-shadow: 5px 5px 8px;
}

.picture {

  height: 50%;
  margin: 10px;
  padding: 10px;
}

.picture2 {

  height: 50%;
  margin: 10px;
  padding: 10px;
}

.stateText {
  margin: 0px;
  padding: 10px;

}

.slider {
  width: 80%;

}

.background {
  background-image: url("../../public/icons/Wall_of_Ivy_Leaves_1.jpg");
  background-attachment: fixed;

}

.buttono {

  height: 7vh;
  width: 7vh;
}

.buttuno {

  min-height: 15%;
  width: 100%;
}

.statusBox {
  width: 4vh;
  height: 4vh;
  border-radius: 4px 4px 4px 4px;
}
.boxButton {
  height: 100%;
  width: 45%;
}
.buttonText {
  font-size: 2vw;
}
</style>
