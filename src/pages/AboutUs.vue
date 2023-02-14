<template>
  <q-page class="background row">
    <SideBar></SideBar>

    <div class="BroxWithboxIn row flex items-top justify-between">
      <div class="longBox q-ml-xl q-mt-lg bg-amber-1 row justify-center items-start">
        <h1 class="text-weight-bold q-mt-xl">Vårt Team</h1>
      </div>

      <div class="Abrox bg-amber-1 column justify-top items-center q-mt-xl q-mr-sm q-ml-lg">
        <img class="faceImg q-mt-md" src="../../public/icons/sebastian.png" />
        <div class="q-mt-md column items-center ">
          <h3 class="nameText text-weight-bold">Sebastin Alin</h3>
          <h5 class="nameText text-weight-bold">Mjukvaruingenjör</h5>
          <h5 class="nameText text-weight-bold">Firebaseingenjör</h5>
          <h5 class="nameText text-weight-bold">Photograf</h5>
          <h5 class="nameText text-weight-bold">Arduinoingenjör</h5>



        </div>
      </div>
      <div class="Abrox bg-amber-1 column justify-top items-center q-mt-xl q-mx-sm">
        <img class="faceImg q-mt-md" src="../../public/icons/axel.png" />
        <div class="q-mt-md column items-center ">
          <h3 class="nameText text-weight-bold">Axel Roxenborg</h3>
          <h5 class="nameText text-weight-bold">CAD-Expert</h5>
          <h5 class="nameText text-weight-bold">Arduinoingenjör</h5>
          <h5 class="nameText text-weight-bold">3D-Print Expert</h5>
          <h5 class="nameText text-weight-bold">Vattenpumpingenjör</h5>
        </div>

      </div>
      <div class="Abrox bg-amber-1 column justify-top items-center q-mt-xl q-ml-sm">
        <img class="faceImg q-mt-md" src="../../public/icons/simon.png" />
        <div class="q-mt-md column items-center ">
          <h3 class="nameText text-weight-bold">Simon Meier</h3>

          <h5 class="nameText text-weight-bold">Mjukvaruingenjör</h5>
          <h5 class="nameText text-weight-bold">Webbdesigner</h5>
          <h5 class="nameText text-weight-bold">Firebaseingenjör</h5>
          <h5 class="nameText text-weight-bold">Paint.net "expert"</h5>
        </div>
        <div></div>

      </div>

    </div>



  </q-page>

</template>

<script setup>
import SideBar from "src/components/SideBar.vue"

</script>

<style>
template {
  background-color: aqua;
}
.background {
  background-image: url("../../public/icons/Wall_of_Ivy_Leaves_1.jpg");
  background-attachment: fixed;
  background-size: cover;
}

.BroxWithboxIn {
  margin-left: 8vh;
  margin-top: 30px;
  margin-bottom: 30px;
  width: 140vh;
  height: 60vh;
}

.Abrox {
  width: 40vh;
  border-radius: 20px 20px 20px 20px;
  display: flex;
  flex-direction: row;
  justify-content: center;
  align-items: center;
}

.faceImg {
  width: 35vh;
  height: 25vh;
  border-radius: 20px 20px 20px 20px;
}

.nameText {
  margin: 0px;
  padding: 0px;
  text-align: center;
}

.longBox {
  width: 132vh;
  height: 20vh;
  border-radius: 100px 100px 100px 100px;
  box-shadow: 5px 5px 8px;

}
</style>
