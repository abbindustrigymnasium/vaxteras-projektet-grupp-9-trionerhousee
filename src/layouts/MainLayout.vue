<template>
  <q-layout view="hHh lpR fFf">

    <q-header elevated class="bg-light-blue-7 ">
      <div class="row justify-around q-ma-sm ">


        <img class="logo q-ml-md" src="../../public/icons/Trioner_housee.png" @click="gotoHome">
        <div class="row bg-light-blue-7 col-5 justify-between">
          <q-btn color="teal" @click="gotoStatistics">
            <img class="Iconpicture q-ma-sm" src="../../public/icons/statisticsss.png">
            <div class="q-mt-xs"> Statistics</div>
          </q-btn>
          <q-btn color="teal" @click="gotoAboutUs">
            <img class="Iconpicture q-ma-sm" src="../../public/icons/aboutusss.png">
            <div class="q-mt-xs"> About Us</div>
          </q-btn>
          <q-btn color="teal" @click="gotoSettings">
            <img class="Iconpicture q-ma-sm" src="../../public/icons/Settingsss.png">
            <div class="q-mt-xs"> Settings</div>
          </q-btn>
        </div>
      </div>



    </q-header>

    <q-page-container>
      <router-view />
    </q-page-container>

  </q-layout>
</template>

<style>
.logo {
  width: 360px;
  height: 90px;
}

.Iconpicture {
  width: 45px;
  height: 45px;

}
</style>

<script setup>
import { useRouter } from 'vue-router'



const router = useRouter()

function gotoHome () {
  router.push("/")
}

function gotoSettings () {
  router.push("/Setting")
}
function gotoAboutUs () {
  router.push("/AboutUs")
}
function gotoStatistics () {
  router.push("/Statistics")
}

</script>
