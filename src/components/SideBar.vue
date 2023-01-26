<template>
  <q-page-sticky position="right" :offset="[30, 30]">
    <div class="box flex bg-light-blue-7 column justify-center items-center justify-around text-white">
      <div class="column items-center " @click="gotoStatistics">
        <div class="text-h3">
          Temperatur
        </div>
        <div class="text-h1">
          {{ Temp.$value }}°C
        </div>
      </div>

      <div class="column items-center " @click="gotoStatistics">
        <div class="text-h3">
          Luftfuktighet
        </div>
        <div class="text-h1">
          {{ luft.$value }}%
        </div>
      </div>

      <div class="column items-center " @click="gotoStatistics">
        <div class="text-h3">
          Jordfuktighet
        </div>
        <div class="text-h1">
          {{ jord.$value }}%
        </div>
      </div>
    </div>
  </q-page-sticky>



</template>


<script setup>
import { ref } from 'vue'
import { useRouter } from 'vue-router'
import { db } from 'src/boot/firebase'
import { useDatabaseList } from 'vuefire'
import { useDatabaseObject } from 'vuefire'
import { ref as dbref } from 'firebase/database'

const jord = useDatabaseObject(dbref(db, 'LiveData/LiveJord'))
const Temp = useDatabaseObject(dbref(db, 'LiveData/LiveTemp'))
const luft = useDatabaseObject(dbref(db, 'LiveData/LiveLuft'))


//const luft = useDatabaseObject(dbref(db, 'LiveData', 'LiveLuft'))
//const jord = useDatabaseObject(dbref(db, 'LiveData', 'LiveJord'))


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
