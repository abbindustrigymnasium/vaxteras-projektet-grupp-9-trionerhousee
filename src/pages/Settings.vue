<template>
  <q-page class="background row">
            <SideBar></SideBar>

<div class="BoxWithBoxIn column flex items-center ">
  <login class="Abox column justify-center items-center"></login>
  <div v-if="awesome" class="Abox column bg-amber-1 justefy-center items-center">

    <h3 class="header">Manual settings</h3>
          <q-btn-toggle v-model="fläktOn" spread class="my-custom-toggle" no-caps rounded unelevated toggle-color="green"
            color="white" text-color="secondary" :options="[
              { label: 'fläkt on', value: 'one' },
              { label: 'Fläkt off', value: 'two' }
            ]" />

    <q-badge class="badge" color="secondary">
            fläktspeed {{ fläktSpeed }}
    </q-badge>
    <q-slider class="slider" v-model="fläktSpeed" :min="0" :max="1000" color="green" />
    <q-btn-toggle v-model="pumpOn" spread class="my-custom-toggle" no-caps rounded unelevated toggle-color="green"
      color="white" text-color="secondary" :options="[
          { label: 'Pump On', value: 'one' },
          { label: 'Pump off', value: 'two' } ]" />
    <q-badge class="badge" color="secondary">
      Pump speed: {{ pumpSpeed }}
    </q-badge>


    <q-slider class="slider" v-model="pumpSpeed" :min="0" :max="1000" color="green" />

    <br>
    <q-btn-toggle v-model="gate" spread class="my-custom-toggle" no-caps rounded unelevated toggle-color="green"
    color="white" text-color="secondary" :options="[
    { label: 'Gate open', value: 'one' },
    { label: 'Gate closed', value: 'two' } ]" />

    <q-btn class="sendData" @click="sendData"> Send data to firebase</q-btn>
  </div>

</div>


</q-page>

</template>

<script setup>

import SideBar from "src/components/SideBar.vue"
import login from "../components/login.vue"
import { ref, watch } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseObject } from 'vuefire'
import { ref as dbref, set } from 'firebase/database'

let pumpSpeed = ref(200);
let fläktSpeed = ref(200);

const liveData = useDatabaseObject(dbref(db, 'LiveData'))

const pumpbool = ref(false);
let fläktbool = ref(false);
let gatebool = ref(false);
let fläktOn = ref('one');
let pumpOn = ref('one');
let gate = ref('one');
let awesome = false;
let admin = false;
let cookies = document.cookie

watch(liveData, (val2) => {
  if (val2 != null) {
    console.log(val2);
    fläktSpeed.value = val2.fanSpeed;
    pumpSpeed.value = val2.pumpSpeed;
    pumpbool.value = val2.HumidifyerOn;
    fläktbool.value = val2.fanON;
    gatebool.value = val2.hatchState;
    if (pumpbool.value == true) {
      pumpOn = ref('one')
    }
    else {
      pumpOn = ref('two')
    }
    if (fläktbool.value == true) {
      fläktOn = ref('one')
    }
    else {
      fläktOn = ref('two')
    }
    if (gatebool.value == true) {
      gate = ref('one')
    }
    else {
      gate = ref('two')
    }
  }});




function sendData() {
  console.log(fläktSpeed.value);
  set(dbref(db, 'LiveData/fanSpeed'), fläktSpeed.value);
  set(dbref(db, 'LiveData/pumpSpeed'), pumpSpeed.value);

  if (pumpOn.value == 'one') {
    set(dbref(db, 'LiveData/HumidifyerOn'), true);
  } else {
    set(dbref(db, 'LiveData/HumidifyerOn'), false);
  }
  if (fläktOn.value == 'one') {
    set(dbref(db, 'LiveData/fanON'), true);
  } else {
    set(dbref(db, 'LiveData/fanON'), false);
  }
  if (gate.value == 'one') {
    set(dbref(db, 'LiveData/hatchState'), true);
  } else {
    set(dbref(db, 'LiveData/hatchState'), false);
  }
}
let decodedCookie = decodeURIComponent(document.cookie)
let ca = decodedCookie.split(';')
let adminString = ca[2]
console.log(adminString)

if (typeof adminString === 'string') {
  if (adminString.startsWith('adm')) {
    admin = adminString.replace("admin=", "")
  }
}


if (admin)
  {
    awesome = true;
  }





</script>

<style>

.sendData {
  margin: 4vh;
  background-color: rgb(0, 97, 97);
}
.my-custom-toggle {
  width: 30%
}
#manualSettings {
  display: none;

}
#manual
.my-custom-toggle {
  margin: 1.5vh;
}
.slider {
  width: 70%;

}
.badge {
    margin: 2vh;
}
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
