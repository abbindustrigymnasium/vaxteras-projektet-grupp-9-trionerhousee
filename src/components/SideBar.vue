<template>
  <q-page-sticky position="right" :offset="[30, 30]">
    <div class="box flex bg-light-blue-7 column justify-center items-center justify-around text-white">
      <div class="column items-center " @click="gotoStatistics">
        <div class="text-h3">
          Temperatur
        </div>
        <div class="text-h1">
          {{ temp }}°C
        </div>
      </div>

      <div class="column items-center " @click="gotoStatistics">
        <div class="text-h3">
          Luftfuktighet
        </div>
        <div class="text-h1">
          {{ luft }}%
        </div>
      </div>

      <div class="column items-center " @click="gotoStatistics">
        <div class="text-h3">
          Jordfuktighet
        </div>
        <div class="text-h1">
          {{ jord }}%
        </div>
      </div>
    </div>
  </q-page-sticky>



</template>


<script setup>
import { ref } from 'vue'
import { useRouter } from 'vue-router'

let temp = ref('55')
let luft = ref('64')
let jord = ref('8')



const router = useRouter()

function gotoStatistics () {
  router.push("/Statistics")
}


</script>

<style>
.box {
  width: 40vh;
  height: 80vh;
  border-radius: 15px 15px 15px 15px;
}
</style>
