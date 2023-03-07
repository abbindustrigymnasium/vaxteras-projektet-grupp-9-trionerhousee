<template v-if="users != null">
  <div class="row justify-around">
    <div class="box2Prison">
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
const liveData = useDatabaseObject(dbref(db, 'LiveData'))
const users = useDatabaseObject(dbref(db, 'users'))


const date = ref('2023/02/01')

const year = ref(date._value.slice(0, 4))
const month = ref(date._value.slice(5, 7))
const day = ref(date._value.slice(8, 10))

const hour = []

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
      label: 'Luftfuktighet',
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

  for (let i = 0; i < 24; i++) {
    hour.pop()
    console.log(hour)
  }

  //const fireTest = useDatabaseObject(dbref(db, 'TempHum/Month' + month.value.value + '/days' + day.value.value))
  if (fireTest._rawValue.Hour1 == null) {
    hour.push(1)
    console.log(hour)
  }
  else {
    hour.push(fireTest._rawValue.Hour1.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour2 == null) {

    hour.push(1)
  }
  else {
    hour.push(fireTest._rawValue.Hour2.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour3 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour3.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour4 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour4.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour5 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour5.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour6 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour6.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour7 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour7.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour8 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour8.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour9 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour9.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour10 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour10.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour11 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour11.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour12 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour12.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour13 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour13.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour14 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour14.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour15 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour15.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour16 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour16.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour17 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour17.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour18 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour18.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour19 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour19.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour20 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour20.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour21 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour21.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour22 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour22.Minute1.humidity)
  }
  if (fireTest._rawValue.Hour23 == null) {

    hour.push(1)
  }
  else {

    hour.push(fireTest._rawValue.Hour23.Minute1.humidity)
  }


  console.log(hour)

  const kalle = ref({
    labels: ["01", "02", "03", "04", "05", "06", "07", "08", "09", "010", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23"],
    datasets: [
      {
        label: 'Luftfuktighet',
        backgroundColor: '#f87979',
        data: [hour[0], hour[1], hour[2], hour[3], hour[4], hour[5], hour[6], hour[7], hour[8], hour[9], hour[10], hour[11], hour[12], hour[13], hour[14], hour[15], hour[16], hour[17], hour[18], hour[19], hour[20], hour[21], hour[22]]
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
.box2Prison {
  width: 75vh;
  height: 55vh;
}
</style>
