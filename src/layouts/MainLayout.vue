<template>
  <q-layout view="hHh lpR fFf">

    <q-header elevated class="bg-amber-1 ">
      <div class="row justify-around q-ma-sm ">


        <img class="logo q-ml-md" src="../../public/icons/Trioner_housee.png" @click="gotoHome">

        <div class="buttons row bg-amber-1">

          <q-btn class="btn q-ml-xl" color="light-green" @click="gotoStatistics">
            <img class="Iconpicture q-ma-sm" src="../../public/icons/statisticsss.png">
            <div class="q-mt-xs"> Statistik</div>
          </q-btn>
          <q-btn class="btn q-ml-xl" color="light-green" @click="gotoAboutUs">
            <img class="Iconpicture q-ma-sm" src="../../public/icons/aboutusss.png">
            <div class="q-mt-xs"> Om oss</div>
          </q-btn>
          <q-btn class="btn q-ml-xl" color="light-green" @click="gotoSettings">
            <img class="Iconpicture q-ma-sm" src="../../public/icons/guyguyguyg.png">
            <div class="q-mt-xs"> Logga in</div>
          </q-btn>
          <q-btn class="btn q-ml-xl" color="light-green" @click="gotoGalleri">
            <img class="Iconpicture q-ma-sm" src="../../public/icons/instagram.png">
            <div class="q-mt-xs"> Galleri</div>
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

function gotoGalleri () {
  router.push("/Galleri")
}



</script>
