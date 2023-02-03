

<script setup>


import firebase from 'firebase/app'
import { VueFire, VueFireAuth } from 'vuefire'
import { signInWithPopup, GoogleAuthProvider, getAuth, signInWithEmailAndPassword, } from 'firebase/auth'
import { ref, watch } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseObject, useDatabaseList } from 'vuefire'
import { ref as dbref, set } from 'firebase/database'



let errorMsg = ''
let errorCode = ''
const auth = getAuth()
let email = ""
let password = ""
let hurra = 'seb';


function alerthello () {
  signInWithEmailAndPassword(auth, email, password).then((userCredendtials) => {
    //signed in
    const user = userCredendtials.user
    const nameObject = useDatabaseObject(dbref(db, 'users/' +  user.uid + '/name/'))
    const name = nameObject.value.$value;
    console.log(nameObject.value.$value);
    document.getElementById('error').innerHTML = 'successfully loged in ' + name;
    document.getElementById('error').style.color = 'green'
    console.log(user.uid)
    document.cookie = 'name='+name+'; expiers=Fri, 31 Dec 2025 23:59:59 GMT; SamSite=None; Secure; ';
    document.location.reload(true)

    return {name};

  })
    .catch((error) => {

      errorCode = error.code
      errorMsg = error.message
      document.getElementById('error').innerHTML = errorMsg
      document.getElementById('error').style.color = 'red'

    })

}

function goToMainPage() {
  router.push("/")
}



</script>



<template>

  <div>
    <h1>Login</h1>
    <form @submit.prevent="handlesubmit">

      <input type="email" placeholder="Enter Email" v-model="email">
      <br>
      <input type="password" v-model="password" placeholder="enter password">

      <button type="submit" id="googleButton" @click="alerthello()">login</button>
      <p id="error"> {{ errorMsg }}</p>

      <router-link to="./setup">new to Trioner hosiee go to? setup new profile</router-link>
      <br>

      <button @click="goToMainPage()">
        go back to the main page
      </button>






    </form>
  </div>
</template>


<style>
#error {
  font-size: x-small;
  color: red;
}
</style>
