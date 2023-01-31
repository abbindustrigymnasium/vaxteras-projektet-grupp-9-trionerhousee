<template>
  <div class="row justify-around">
    <div class="boxPrison" @click="hello">
      <Line :data="chartData" :options="chartOptions" />
    </div>
    <div class=" self-center">
      <q-date v-model="date" minimal />
    </div>
  </div>

</template>

<script setup>
import { ref, watch } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseObject } from 'vuefire'
import { ref as dbref, set } from 'firebase/database'

import { Bar } from 'vue-chartjs'
import { Line } from 'vue-chartjs'
import {
  Chart as ChartJS, CategoryScale, LinearScale, PointElement, LineElement, Title, Tooltip, Legend
} from 'chart.js'
ChartJS.register(CategoryScale, LinearScale, PointElement, LineElement, Title, Tooltip, Legend)

const chartData = ref({
  labels: [1, 2, 3, 4, 5, 6, 7, 8, 9],
  datasets: [
    {
      label: 'Data One',
      backgroundColor: '#f87979',
      data: [40, 20, 12, 10, 8, 15, 17, 19, 24,]
    }
  ]
})

const tempHum = useDatabaseObject(dbref(db, 'TempHum'))

const chartOptions = ref({
  responsive: true,
  maintainAspectRatio: false
})

const date = ref('2023/01/01')

function hello () {
  const year = ref(date._value.slice(0, 4))
  const month = ref(date._value.slice(5, 7))
  const day = ref(date._value.slice(8, 10))
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
