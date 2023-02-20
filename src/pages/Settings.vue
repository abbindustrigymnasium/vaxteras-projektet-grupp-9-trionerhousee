<template>
  <q-page class="background row">
    <SideBar></SideBar>

    <div class="Box3WithBoxIn column flex items-center ">
      <login class="A3box column justify-center items-center "></login>
      <div v-if="admin == 'true'" class="A4box column bg-amber-1 justefy-center items-center q-mt-xl">

        <h3 class="header">Manual settings</h3>
        <q-btn-toggle v-model="fläktOn" spread class="my-custom-toggle q-mt-md" no-caps rounded unelevated
          toggle-color="green" color="white" text-color="secondary" :options="[
            { label: 'Fläkt on', value: 'one' },
            { label: 'Fläkt off', value: 'two' }]" />

        <q-btn-toggle v-model="pumpOn" spread class="my-custom-toggle q-mt-md" no-caps rounded unelevated
          toggle-color="green" color="white" text-color="secondary" :options="[
            { label: 'Pump on', value: 'one' },
            { label: 'Pump off', value: 'two' }]" />

        <q-btn-toggle v-model="gate" spread class="my-custom-toggle q-mt-md" no-caps rounded unelevated
          toggle-color="green" color="white" text-color="secondary" :options="[
            { label: 'Gate open', value: 'one' },
            { label: 'Gate closed', value: 'two' }]" />

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

let pumpSpeed = ref(200)
let fläktSpeed = ref(200)

const liveData = useDatabaseObject(dbref(db, 'LiveData'))

const pumpbool = ref(false)
let fläktbool = ref(false)
let gatebool = ref(false)
let fläktOn = ref('one')
let pumpOn = ref('one')
let gate = ref('one')
let awesome = false
let admin
let cookies = document.cookie

watch(liveData, (val2) => {
  if (val2 != null) {
    console.log(val2)
    fläktSpeed.value = val2.fanSpeed
    pumpSpeed.value = val2.pumpSpeed
    pumpbool.value = val2.HumidifyerOn
    fläktbool.value = val2.fanON
    gatebool.value = val2.hatchState
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
  }
})




function sendData () {

  if (pumpOn.value == 'one') {
    set(dbref(db, 'LiveData/HumidifyerOn'), true)

  } else {
    set(dbref(db, 'LiveData/HumidifyerOn'), false)
    console.log("hele")
  }
  if (fläktOn.value == 'one') {
    set(dbref(db, 'LiveData/fanON'), true)
  } else {
    set(dbref(db, 'LiveData/fanON'), false)
  }
  if (gate.value == 'one') {
    set(dbref(db, 'LiveData/hatchState'), true)
  } else {
    set(dbref(db, 'LiveData/hatchState'), false)
  }
}
let decodedCookie = decodeURIComponent(document.cookie)
let ca = decodedCookie.split(';')



for (let i = 0; i < ca.length; i++) {
  let adminString = ca[i]
  if (adminString.startsWith('admin')) {
    admin = adminString.replace("admin=", "")
    console.log(admin)
  }
}


if (admin == "true") {
  awesome = true
  console.log(awesome)
}





</script>

<style>
.sendData {
  margin: 4vh;
  background-color: rgb(0, 97, 97);
}

.my-custom-toggle {
  width: 35%;
  height: 5vh;

}

#manualSettings {
  display: none;

}

#manual .my-custom-toggle {
  margin: 1.5vh;
}

.background {
  background-image: url("../../public/icons/Wall_of_Ivy_Leaves_1.jpg");
}

.bruh {
  background-color: blue;
}

.A3box {
  width: 100%;
  height: 65vh;
  opacity: 95%;
  box-shadow: 3px 3px 5px;
  background-image: url("./../../public/icons/wallpaper1.jpg");
}

.A4box {
  width: 50%;
  height: 40vh;
  opacity: 95%;
  box-shadow: 3px 3px 5px;
  background-image: url("./../../public/icons/wallpaper1.jpg");
}


.Box3WithBoxIn {
  margin-left: 8vh;
  margin-top: 30px;
  margin-bottom: 30px;
  width: 140vh;
  height: 120vh;
}
</style>
