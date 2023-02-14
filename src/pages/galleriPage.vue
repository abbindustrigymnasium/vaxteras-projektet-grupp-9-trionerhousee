<template>
  <q-page class="background row">

    <SideBar></SideBar>
    <div class="BoxWithBoxIn row flex justify-center items-center justify-around">




      <div class="Atox bg-amber-1 column justify-center">
        <div>
          <img class="image" src="../../public/icons/MicrosoftTeams-image.png" >
          <img class="image" src="../../public/icons/MicrosoftTeams-image1.png">
          <img class="image" src="../../public/icons/MicrosoftTeams-image2.png">
          <img class="image" src="../../public/icons/MicrosoftTeams-image3.png">
          <img class="image" src="../../public/icons/MicrosoftTeams-image4.png">
          <img class="image" src="../../public/icons/MicrosoftTeams-image5.png">
          <img class="image" src="../../public/icons/MicrosoftTeams-image6.png">
          <img class="image" src="../../public/icons/MicrosoftTeams-image7.png">
          <img class="image" src="../../public/icons/MicrosoftTeams-image8.png">
          <img class="image" src="../../public/icons/MicrosoftTeams-image9.png">
          <img class="image" src="../../public/icons/MicrosoftTeams-image10.png">
          <img class="image" src="../../public/icons/MicrosoftTeams-image11.png">

        </div>
      </div>



    </div>


  </q-page>
</template>

<script setup>
import SideBar from "src/components/SideBar.vue"
import Chart1 from "src/components/ChartComp1.vue"
import { ref } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseObject } from 'vuefire'
import { ref as dbref, set } from 'firebase/database'






</script>

<style>
.background {
  background-image: url("../../public/icons/Wall_of_Ivy_Leaves_1.jpg");
  background-attachment: fixed;
}

.BoxWithBoxIn {
  margin-left: 8vh;
  margin-top: 30px;
  margin-bottom: 30px;
  width: 140vh;
  height: 200vh;
}

.image {
  width: 29%;
  box-shadow: 5px 5px 10px;
  margin: 2%;
  border-radius: 5% ;
}
.Atox {
  box-shadow: 5px 5px 10px;
  width: 130vh;
  border-radius: 20px 20px 20px 20px;
}
</style>
