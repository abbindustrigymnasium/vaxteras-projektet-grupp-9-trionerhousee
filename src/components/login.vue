

<script setup>


import firebase from 'firebase/app'
import { useRouter } from 'vue-router'
import { VueFire, VueFireAuth } from 'vuefire'
import { signInWithPopup, GoogleAuthProvider, getAuth, signInWithEmailAndPassword, } from 'firebase/auth'
import { ref, watch } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseObject, useDatabaseList } from 'vuefire'
import { ref as dbref, set } from 'firebase/database'


const router = useRouter()
let errorMsg = ''
let errorCode = ''
const auth = getAuth()
let email = ""
let password = ""
let hurra = 'seb'


function alerthello () {
  signInWithEmailAndPassword(auth, email, password).then((userCredendtials) => {
    //signed in
    const user = userCredendtials.user
    const nameObject = useDatabaseObject(dbref(db, 'users/' + user.uid + '/name'))
    console.log(user.uid)
    const adminObject = useDatabaseObject(dbref(db, 'users/' + user.uid + '/admin'))
    console.log(adminObject)

    const admin = adminObject.value.$value
    const name = nameObject.value.$value
    console.log(nameObject.value.$value)
    document.getElementById('error').innerHTML = 'successfully loged in ' + name
    document.getElementById('error').style.color = 'green'
    console.log(user.uid)
    document.cookie = 'admin=' + admin + ';expiers=Fri, 31 Dec 2025 23:59:59 GMT; SamSite=None; Secure;'
    document.cookie = 'name=' + name + '; expiers=Fri, 31 Dec 2025 23:59:59 GMT; SamSite=None; Secure; '
    document.location.reload(true)
    document.cookie = 'userUid=' + user.uid + '; expiers=Fri, 31 Dec 2025 23:59:59 GMT; SamSite=None; Secure; '

    return { name }

  })
    .catch((error) => {

      errorCode = error.code
      errorMsg = error.message
      document.getElementById('error').innerHTML = errorMsg
      document.getElementById('error').style.color = 'red'

    })

}

function goToMainPage () {
  router.push("/")
}


</script>



<template>
  <div class="BoxWithBoxIn">

    <h1 class="text">Login</h1>
    <button class="text" @click="goToMainPage()">
      Go back to the main page
    </button>

    <div class="form flex column justify">

      <input type="email" placeholder="Enter Email" class="text" v-model="email">
      <br>
      <input type="password" v-model="password" class="text" placeholder="enter password">
      <br>
      <button type="submit" id="googleButton" class="text" @click="alerthello()">login</button>
      <p id="error"> {{ errorMsg }}</p>

      <router-link to="./setup">new to Trioner hosiee go to? setup new profile</router-link>








    </div>
  </div>
</template>


<style>
button:hover {
  background-color: rgba(1, 65, 73, 0.5);
}

button {
  background-color: rgb(1, 105, 119);
  border: none;
  padding: 1vh;
  box-shadow: 3px 3px;
}

input {
  border: none;
  width: 55%;
  height: 5vh;

}

#error {
  font-size: x-small;
  color: red;
}

#googleButton {
  width: 20%;
  height: 17%;
}

.text {

  font-weight: bolder;
  border-radius: 15px;
  box-shadow: 5px, 5px;

}

.header {
  font-weight: bolder;
  margin: 1vh;

  border-radius: 30px;
}

.form {
  background-color: rgb(253, 244, 201, 0.5);
  margin: 1vh;
  padding: 2vh;
  border-radius: 40px;
  width: 50%;
  display: flex;
  align-items: center;
  height: 60%;

  box-shadow: 3px 3px;

}
</style>
