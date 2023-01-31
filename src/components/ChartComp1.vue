<template>
  <div class="row justify-around">
    <div class="boxPrison">
      <Line :data="chartData" :options="chartOptions" />
    </div>
    <div class=" self-center">
      <q-date v-model="date" minimal />
    </div>
  </div>

</template>

<script setup>
import { Bar } from 'vue-chartjs'
import { Line } from 'vue-chartjs'
import {
  Chart as ChartJS, CategoryScale, LinearScale, PointElement, LineElement, Title, Tooltip, Legend
} from 'chart.js'
import { ref } from 'vue'
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
const chartOptions = ref({
  responsive: true,
  maintainAspectRatio: false
})

const date = ref('2023/01/01')

const dateArray = date.split("/")

console.log(dateArray)
</script>

<style>
.boxPrison {
  width: 55vh;
  height: 55vh;
}
</style>
