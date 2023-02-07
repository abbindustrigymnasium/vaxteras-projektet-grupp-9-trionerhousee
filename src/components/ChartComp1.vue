<template v-if="users != null">
  <div class="row justify-around">
    <div class="boxPrison">
      <Line :data="chartData" :options="chartOptions" />
    </div>
    <div class="column self-center">
      <div class=" self-center" @click="hello">
        <q-date v-model="date" minimal no-unset color="light-green" />
      </div>
      <q-btn @click="kalleUpdate" class="bg-light-green q-mt-sm">Update graph</q-btn>
    </div>
  </div>


  <!-- <q-btn @click="kalleUpdate" v-if="fireTest != null">Update graph</q-btn>   -->

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



const date = ref('2023/02/01')

const year = ref(date._value.slice(0, 4))
const month = ref(date._value.slice(5, 7))
const day = ref(date._value.slice(8, 10))

if (day.value < 10) {
  day.value = ref(day._value.slice(1, 2))
}
if (day.value > 10) {
  day.value = ref(day._value.slice(0, 2))
}
if (month.value < 10) {
  month.value = ref(month._value.slice(1, 2))
}
if (month.value > 10) {
  month.value = ref(month._value.slice(0, 2))
}

let fireTest = useDatabaseObject(dbref(db, 'TempHum/Month' + month.value.value + '/days' + day.value.value))


//const graph1 = graph._rawValue.Month2.days1.Hour1.Minute1.EarthHumidity
//const graph2 = graph._rawValue.Month2.days1.Hour1.Minute1.EarthHumidity
//const graph3 = graph._rawValue.Month2.days1.Hour1.Minute1.EarthHumidity
//const graph4 = graph._rawValue.Month2.days1.Hour1.Minute1.EarthHumidity
//const graph5 = graph._rawValue.Month2.days1.Hour1.Minute1.EarthHumidity



const chartData = ref({
  labels: ["01", "02", "03", "04", "05", "06", "07", "08", "09", "010", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23"],
  datasets: [
    {
      label: 'JordHumiditet',
      backgroundColor: '#f87979',
      data: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23]
    }
  ]
})


// const kalle = ref({
//   labels: ["02", "03", "04", "05", "06"],
//   datasets: [
//     {
//       label: 'Data One',
//       backgroundColor: '#f87979',
//       data: [test._value, 3, 4, 5, 20]
//     }
//   ]
// })

const chartOptions = ref({
  responsive: true,
  maintainAspectRatio: false
})


function kalleUpdate () {


  //const fireTest = useDatabaseObject(dbref(db, 'TempHum/Month' + month.value.value + '/days' + day.value.value))
  if (fireTest._rawValue.Hour1 == null) {
    const hour1 = 1
  }
  else {
    const hour1 = ref(fireTest._rawValue.Hour1.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour2 == null) {
    const hour2 = 1
  }
  else {
    const hour2 = ref(fireTest._rawValue.Hour2.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour3 == null) {
    const hour3 = 1
  }
  else {
    const hour3 = ref(fireTest._rawValue.Hour3.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour4 == null) {
    const hour4 = 1
  }
  else {
    const hour4 = ref(fireTest._rawValue.Hour4.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour5 == null) {
    const hour5 = 1
  }
  else {
    const hour5 = ref(fireTest._rawValue.Hour5.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour6 == null) {
    const hour6 = 1
  }
  else {
    const hour6 = ref(fireTest._rawValue.Hour6.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour7 == null) {
    const hour7 = 1
  }
  else {
    const hour7 = ref(fireTest._rawValue.Hour7.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour8 == null) {
    const hour8 = 1
  }
  else {
    const hour8 = ref(fireTest._rawValue.Hour8.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour9 == null) {
    const hour9 = 1
  }
  else {
    const hour9 = ref(fireTest._rawValue.Hour9.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour10 == null) {
    const hour10 = 1
  }
  else {
    const hour10 = ref(fireTest._rawValue.Hour10.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour11 == null) {
    const hour11 = 1
  }
  else {
    const hour11 = ref(fireTest._rawValue.Hour11.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour12 == null) {
    const hour12 = 1
  }
  else {
    const hour12 = ref(fireTest._rawValue.Hour12.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour13 == null) {
    const hour13 = 1
  }
  else {
    const hour13 = ref(fireTest._rawValue.Hour13.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour14 == null) {
    const hour14 = 1
  }
  else {
    const hour15 = ref(fireTest._rawValue.Hour15.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour16 == null) {
    const hour16 = 1
  }
  else {
    const hour16 = ref(fireTest._rawValue.Hour16.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour17 == null) {
    const hour17 = 1
  }
  else {
    const hour17 = ref(fireTest._rawValue.Hour17.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour18 == null) {
    const hour18 = 1
  }
  else {
    const hour18 = ref(fireTest._rawValue.Hour18.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour19 == null) {
    const hour19 = 1
  }
  else {
    const hour19 = ref(fireTest._rawValue.Hour19.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour20 == null) {
    const hour20 = 1
  }
  else {
    const hour20 = ref(fireTest._rawValue.Hour20.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour21 == null) {
    const hour21 = 1
  }
  else {
    const hour21 = ref(fireTest._rawValue.Hour21.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour22 == null) {
    const hour22 = 1
  }
  else {
    const hour22 = ref(fireTest._rawValue.Hour22.Minute1.EarthHumidity)
  }
  if (fireTest._rawValue.Hour23 == null) {
    const hour23 = 1
  }
  else {
    const hour23 = ref(fireTest._rawValue.Hour23.Minute1.EarthHumidity)
  }


  // const hour7 = ref(fireTest._rawValue.Hour7.Minute1.EarthHumidity)
  // const hour8 = ref(fireTest._rawValue.Hour8.Minute1.EarthHumidity)
  // const hour9 = ref(fireTest._rawValue.Hour9.Minute1.EarthHumidity)
  // const hour10 = ref(fireTest._rawValue.Hour10.Minute1.EarthHumidity)
  // const hour11 = ref(fireTest._rawValue.Hour11.Minute1.EarthHumidity)
  // const hour12 = ref(fireTest._rawValue.Hour12.Minute1.EarthHumidity)
  // const hour13 = ref(fireTest._rawValue.Hour13.Minute1.EarthHumidity)
  // const hour14 = ref(fireTest._rawValue.Hour14.Minute1.EarthHumidity)
  // const hour15 = ref(fireTest._rawValue.Hour15.Minute1.EarthHumidity)
  // const hour16 = ref(fireTest._rawValue.Hour16.Minute1.EarthHumidity)
  // const hour17 = ref(fireTest._rawValue.Hour17.Minute1.EarthHumidity)
  // const hour18 = ref(fireTest._rawValue.Hour18.Minute1.EarthHumidity)
  // const hour19 = ref(fireTest._rawValue.Hour19.Minute1.EarthHumidity)
  // const hour20 = ref(fireTest._rawValue.Hour20.Minute1.EarthHumidity)
  // const hour21 = ref(fireTest._rawValue.Hour21.Minute1.EarthHumidity)
  // const hour22 = ref(fireTest._rawValue.Hour22.Minute1.EarthHumidity)
  // const hour23 = ref(fireTest._rawValue.Hour23.Minute1.EarthHumidity)

  console.log(hour2)
  console.log(fireTest)

  const kalle = ref({
    labels: ["01", "02", "03", "04", "05", "06", "07", "08", "09", "010", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23"],
    datasets: [
      {
        label: 'JordHumiditet',
        backgroundColor: '#f87979',
        data: [hour1.value, hour2.value, hour3.value, hour4.value, hour5.value, hour6.value, hour7.value, hour8.value, hour9.value, hour10.value, hour11.value, hour12.value, hour13.value, hour14.value, hour15.value, hour16.value, hour17.value, hour18.value, hour19.value, hour20.value, hour21.value, hour22.value, hour23.value]
      }
    ]
  })

  chartData.value = kalle.value
}

function hello () {
  console.log(date)


  if (date != null) {
    const month2 = ref(date.value.slice(5, 7))
    const day2 = ref(date.value.slice(8, 10))

    if (day2.value < 10) {
      day2.value = ref(day2.value.slice(1, 2))
    }
    if (day2.value > 10) {
      day2.value = ref(day2.value.slice(0, 2))
    }
    if (month2.value < 10) {
      month2.value = ref(month2.value.slice(1, 2))
    }
    if (month2.value > 10) {
      month2.value = ref(month2.value.slice(0, 2))
    }

    fireTest = useDatabaseObject(dbref(db, 'TempHum/Month' + month2.value.value + '/days' + day2.value.value))


    console.log("Hello!!")
    console.log(fireTest)
  }

}


</script>

<style>
.boxPrison {
  width: 75vh;
  height: 55vh;
}
</style>
