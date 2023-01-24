<template>
  <q-page-sticky position="right" :offset="[30, 30]">
    <div class="box flex bg-light-blue-7 column justify-center items-center justify-around text-white">
      <div class="column items-center " @click="gotoStatistics">
        <div class="text-h5">
          Temperatur
        </div>
        <div class="text-h3">
          {{ temp }}°C
        </div>
      </div>

      <div class="column items-center " @click="gotoStatistics">
        <div class="text-h5">
          Luftfuktighet
        </div>
        <div class="text-h3">
          {{ luft }}%
        </div>
      </div>

      <div class="column items-center " @click="gotoStatistics">
        <div class="text-h5">
          Jordfuktighet
        </div>
        <div class="text-h3">
          {{ jord }}%
        </div>
      </div>
    </div>
  </q-page-sticky>



</template>


<script setup>
import { ref } from 'vue'
import { useRouter } from 'vue-router'

let temp = ref('54')
let luft = ref('64')
let jord = ref('8')



const router = useRouter()

function gotoStatistics () {
  router.push("/Statistics")
}


</script>

<style>
.box {
  width: 350px;
  height: calc(8vh);
  border-radius: 15px 15px 15px 15px;
}
</style>
