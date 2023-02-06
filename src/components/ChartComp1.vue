<template v-if="users != null">
  <div class="row justify-around">
    <div class="boxPrison">
      <Line :data="chartData" :options="chartOptions" />
    </div>
    <div class=" self-center" @click="hello">
      <q-date v-model="date" minimal />
    </div>
  </div>

</template>

<script setup>
import { ref, watch } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseObject } from 'vuefire'
import { ref as dbref, set } from 'firebase/database'

import { Bar, Chart } from 'vue-chartjs'
import { Line } from 'vue-chartjs'
import {
  Chart as ChartJS, CategoryScale, LinearScale, PointElement, LineElement, Title, Tooltip, Legend
} from 'chart.js'
ChartJS.register(CategoryScale, LinearScale, PointElement, LineElement, Title, Tooltip, Legend,)

const graph = useDatabaseObject(dbref(db, 'TempHum'))
const users = useDatabaseObject(dbref(db, 'users'))

const date = ref('2023/01/05')

const test = ref(date._value.slice(8, 10))

//const graph1 = graph._rawValue.Month2.days1.Hour1.Minute1.EarthHumidity
//const graph2 = graph._rawValue.Month2.days1.Hour1.Minute1.EarthHumidity
//const graph3 = graph._rawValue.Month2.days1.Hour1.Minute1.EarthHumidity
//const graph4 = graph._rawValue.Month2.days1.Hour1.Minute1.EarthHumidity
//const graph5 = graph._rawValue.Month2.days1.Hour1.Minute1.EarthHumidity



const chartData = ref({
  labels: ["01", "02", "03", "04", "05"],
  datasets: [
    {
      label: 'Data One',
      backgroundColor: '#f87979',
      data: [test._value, 2, 3, 4, 5]
    }
  ]
})


const chartOptions = ref({
  responsive: true,
  maintainAspectRatio: false
})




function hello () {
  const year = ref(date._value.slice(0, 4))
  const month = ref(date._value.slice(5, 7))
  const day = ref(date._value.slice(8, 10))
  //  const graph1 = useDatabaseObject(dbref(db, 'TempHum/Month2/days1/Hour1/Minute1'))
  console.log(graph._rawValue.Month2.days1.Hour1.Minute1.EarthHumidity)
  console.log(year)
  console.log(month)
  console.log(day)
  console.log(date)


}


</script>

<style>
.boxPrison {
  width: 55vh;
  height: 55vh;
}
</style>
