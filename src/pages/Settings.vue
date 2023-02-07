<template>
  <q-page class="background row">
            <SideBar></SideBar>


<SideBar></SideBar>
<div class="BoxWithBoxIn column flex items-center ">
  <login class="Abox column justify-center items-center"></login>
  <div id="manualSettings" class="Abox column justefy-center items-center">

    <h3 class="header">Manual settings</h3>
          <q-btn-toggle v-model="model" spread class="my-custom-toggle" no-caps rounded unelevated toggle-color="primary"
            color="white" text-color="primary" :options="[
              { label: 'Option 1', value: 'one' },
              { label: 'Option 2', value: 'two' }
            ]" />

    <q-badge color="secondary">
            fläktspeed
    </q-badge>
    <q-slider class="slider" v-model="standard" :min="0" :max="50" />
    <q-btn-toggle v-model="model" spread class="my-custom-toggle" no-caps rounded unelevated toggle-color="primary"
      color="white" text-color="primary" :options="[
          { label: 'Option 1', value: 'one' },
          { label: 'Option 2', value: 'two' } ]" />
    <q-badge color="secondary">
      pump speed {{ standard }}
    </q-badge>


    <q-slider class="slider" v-model="standard" :min="0" :max="50" color="green" />

    <br>
    <q-btn-toggle v-model="model" spread class="my-custom-toggle" no-caps rounded unelevated toggle-color="primary"
    color="white" text-color="primary" :options="[
    { label: 'Option 1', value: 'one' },
    { label: 'Option 2', value: 'two' } ]" />
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

let standard = 2;
let model = 1;

let cookies = document.cookie



let decodedCookie = decodeURIComponent(document.cookie)
let ca = decodedCookie.split(';')

let userUid = ca[1].replace('userUid=', '')

const adminObject = useDatabaseObject(dbref(db, '/users/' + userUid + '/name'))


const admin = adminObject.value;

console.log(userUid)
console.log(admin);



</script>

<style>
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
