<template v-if="users != null">
  <div class="row justify-around">
    <div class="box3Prison">
      <Line :data="chartData" :options="chartOptions" />
    </div>
    <div class="column self-center">
      <div class=" self-center" @click="hello">
        <q-date v-model="date" minimal no-unset color="light-green" />
      </div>

      <q-btn @click="kalleUpdate(); checkData();" class="bg-light-green q-mt-sm">Update
        graph</q-btn>

    </div>
  </div>
<!-- <q-btn @click="kalleUpdate" v-if="fireTest != null">Update graph</q-btn>   --></template>

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
const liveData = useDatabaseObject(dbref(db, 'LiveData'))
const users = useDatabaseObject(dbref(db, 'users'))


const date = ref('2023/02/01')

const year = ref(date._value.slice(0, 4))
const month = ref(date._value.slice(5, 7))
const day = ref(date._value.slice(8, 10))

const hour1 = ref(1)
const hour2 = ref(1)
const hour3 = ref(1)
const hour4 = ref(1)
const hour5 = ref(1)
const hour6 = ref(1)
const hour7 = ref(1)
const hour8 = ref(1)
const hour9 = ref(1)
const hour10 = ref(1)
const hour11 = ref(1)
const hour12 = ref(1)
const hour13 = ref(1)
const hour14 = ref(1)
const hour15 = ref(1)
const hour16 = ref(1)
const hour17 = ref(1)
const hour18 = ref(1)
const hour19 = ref(1)
const hour20 = ref(1)
const hour21 = ref(1)
const hour22 = ref(1)
const hour23 = ref(1)

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


const chartData = ref({
  labels: ["01", "02", "03", "04", "05", "06", "07", "08", "09", "010", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23"],
  datasets: [
    {
      label: 'Temperatur',
      backgroundColor: '#f87979',
      data: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23]
    }
  ]
})


const chartOptions = ref({
  responsive: true,
  maintainAspectRatio: false
})


function kalleUpdate () {


  //const fireTest = useDatabaseObject(dbref(db, 'TempHum/Month' + month.value.value + '/days' + day.value.value))
  if (fireTest._rawValue.Hour1 == null) {
    hour1.value = 1
  }
  else {
    hour1.value = ref(fireTest._rawValue.Hour1.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour2 == null) {
    hour2.value = 1
  }
  else {
    hour2.value = ref(fireTest._rawValue.Hour2.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour3 == null) {
    hour3.value = 1
  }
  else {
    hour3.value = ref(fireTest._rawValue.Hour3.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour4 == null) {
    hour4.value = 1
  }
  else {
    hour4.value = ref(fireTest._rawValue.Hour4.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour5 == null) {
    hour5.value = 1
  }
  else {
    hour5.value = ref(fireTest._rawValue.Hour5.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour6 == null) {
    hour6.value = 1
  }
  else {
    hour6.value = ref(fireTest._rawValue.Hour6.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour7 == null) {
    hour7.value = 1
  }
  else {
    hour7.value = ref(fireTest._rawValue.Hour7.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour8 == null) {
    hour8.value = 1
  }
  else {
    hour8.value = ref(fireTest._rawValue.Hour8.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour9 == null) {
    hour9.value = 1
  }
  else {
    hour9.value = ref(fireTest._rawValue.Hour9.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour10 == null) {
    hour10.value = 1
  }
  else {
    hour10.value = ref(fireTest._rawValue.Hour10.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour11 == null) {
    hour11.value = 1
  }
  else {
    hour11.value = ref(fireTest._rawValue.Hour11.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour12 == null) {
    hour12.value = 1
  }
  else {
    hour12.value = ref(fireTest._rawValue.Hour12.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour13 == null) {
    hour13.value = 1
  }
  else {
    hour13.value = ref(fireTest._rawValue.Hour13.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour14 == null) {
    hour14.value = 1
  }
  else {
    hour14.value = ref(fireTest._rawValue.Hour14.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour15 == null) {
    hour15.value = 1
  }
  else {
    hour15.value = ref(fireTest._rawValue.Hour15.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour16 == null) {
    hour16.value = 1
  }
  else {
    hour16.value = ref(fireTest._rawValue.Hour16.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour17 == null) {
    hour17.value = 1
  }
  else {
    hour17.value = ref(fireTest._rawValue.Hour17.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour18 == null) {
    hour18.value = 1
  }
  else {
    hour18.value = ref(fireTest._rawValue.Hour18.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour19 == null) {
    hour19.value = 1
  }
  else {
    hour19.value = ref(fireTest._rawValue.Hour19.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour20 == null) {
    hour20.value = 1
  }
  else {
    hour20.value = ref(fireTest._rawValue.Hour20.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour21 == null) {
    hour21.value = 1
  }
  else {
    hour21.value = ref(fireTest._rawValue.Hour21.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour22 == null) {
    hour22.value = 1
  }
  else {
    hour22.value = ref(fireTest._rawValue.Hour22.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour23 == null) {
    hour23.value = 1
  }
  else {
    hour23.value = ref(fireTest._rawValue.Hour23.Minute1.temperature)
  }


  console.log(hour10.value.value)
  console.log(fireTest)

  const kalle = ref({
    labels: ["01", "02", "03", "04", "05", "06", "07", "08", "09", "010", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23"],
    datasets: [
      {
        label: 'Temperatur',
        backgroundColor: '#f87979',
        data: [hour1.value.value, hour2.value.value, hour3.value.value, hour4.value.value, hour5.value.value, hour6.value.value, hour7.value.value, hour8.value.value, hour9.value.value, hour10.value.value, hour11.value.value, hour12.value.value, hour13.value.value, hour14.value.value, hour15.value.value, hour16.value.value, hour17.value.value, hour18.value.value, hour19.value.value, hour20.value.value, hour21.value.value, hour22.value.value, hour23.value.value]
      }
    ]
  })

  chartData.value = kalle.value
}

function hello () {

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
.box3Prison {
  width: 75vh;
  height: 55vh;
}
</style>
