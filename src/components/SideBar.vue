<template>
  <q-page-sticky position="right" :offset="[30, 30]">
    <div class="box flex bg-amber-1 column justify-center items-center justify-around text-black">

      <div class="column items-center " @click="gotoStatistics">
        <div class="text-h3">
          Temperatur
        </div>
        <div class="text-h1">
          {{ liveData.LiveTemp }}°C
        </div>
      </div>

      <div class="column items-center " @click="gotoStatistics">
        <div class="text-h3">
          Luftfuktighet
        </div>
        <div class="text-h1">
          {{ liveData.LiveLuft }}%
        </div>
      </div>

      <div class="column items-center " @click="gotoStatistics">
        <div class="text-h3">
          Jordfuktighet
        </div>
        <div class="text-h1">
          {{ liveData.LiveJord }}%
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

const liveData = useDatabaseObject(dbref(db, 'LiveData'))



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
