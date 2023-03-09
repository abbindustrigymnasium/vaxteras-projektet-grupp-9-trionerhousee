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

const hourT = []

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
  labels: ["01", "02", "03", "04", "05", "06", "07", "08", "09", "010", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22"],
  datasets: [
    {
      label: 'Temperatur',
      backgroundColor: '#f87979',
      data: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22]
    }
  ]
})


const chartOptions = ref({
  responsive: true,
  maintainAspectRatio: false
})


function kalleUpdate () {

  for (let i = 0; i < 24; i++) {
    hourT.pop()
    console.log(hourT)
  }

  //const fireTest = useDatabaseObject(dbref(db, 'TempHum/Month' + month.value.value + '/days' + day.value.value))
  if (fireTest._rawValue.Hour1 == null) {
    hourT.push(1)
  }
  else {
    hourT.push(fireTest._rawValue.Hour1.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour2 == null) {

    hourT.push(1)
  }
  else {
    hourT.push(fireTest._rawValue.Hour2.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour3 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour3.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour4 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour4.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour5 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour5.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour6 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour6.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour7 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour7.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour8 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour8.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour9 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour9.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour10 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour10.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour11 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour11.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour12 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour12.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour13 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour13.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour14 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour14.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour15 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour15.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour16 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour16.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour17 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour17.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour18 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour18.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour19 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour19.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour20 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour20.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour21 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour21.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour22 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour22.Minute1.temperature)
  }
  if (fireTest._rawValue.Hour23 == null) {

    hourT.push(1)
  }
  else {

    hourT.push(fireTest._rawValue.Hour23.Minute1.temperature)
  }

  console.log(hourT)

  const kalle = ref({
    labels: ["01", "02", "03", "04", "05", "06", "07", "08", "09", "010", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22"],
    datasets: [
      {
        label: 'Temperatur',
        backgroundColor: '#f87979',
        data: [hourT[0], hourT[1], hourT[2], hourT[3], hourT[4], hourT[5], hourT[6], hourT[7], hourT[8], hourT[9], hourT[10], hourT[11], hourT[12], hourT[13], hourT[14], hourT[15], hourT[16], hourT[17], hourT[18], hourT[19], hourT[20], hourT[21]]
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
