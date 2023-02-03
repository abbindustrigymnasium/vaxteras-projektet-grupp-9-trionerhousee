<script setup>
import firebase from 'firebase/app'
import { VueFire, VueFireAuth } from 'vuefire'
import { signInWithPopup, GoogleAuthProvider, getAuth, createUserWithEmailAndPassword, } from 'firebase/auth'
import { ref, watch } from 'vue'
import { db } from 'src/boot/firebase'
import { useDatabaseObject } from 'vuefire'
import { ref as dbref, set } from 'firebase/database'
import { useRouter } from 'vue-router'

let errorMsg = '';
let errorCode = '';
let name = '';
let phoneNumber = '';
const auth = getAuth()
let email = ""
let password = ""
const router = useRouter();

function signUp() {
  createUserWithEmailAndPassword(auth, email, password).then((userCredendtials) => {
    //signed in
    const user = userCredendtials.user;
    document.getElementById('error').innerHTML = 'successfully signed up ' + name;
    document.getElementById('error').style.color = 'green';
    console.log(user.uid);
    document.cookie = 'name=' + name + '; expiers=Fri, 31 Dec 2025 23:59:59 GMT; SamSite=None; Secure; ';
    set(dbref(db, '/users/' + user.uid ),  {
      email: user.email,
      name: name,
      phoneNumber: phoneNumber,
      admin: false,

    });

    document.location.reload(true)


  })
  .catch ((error) => {

    errorCode = error.code;
    errorMsg = error.message;
    document.getElementById('error').innerHTML = errorMsg;
    document.getElementById('error').style.color = 'red';

  })

}

function goToMainPage () {
  router.push("/")
}


</script>
<template>
  <div>
    <h1>Sign up</h1>
    <form @submit.prevent="handlesubmit">
      <input type="text" placeholder="Enter name" v-model="name">
      <br>
      <input type="number" placeholder="Eneter phone number" v-model="phoneNumber">
      <br>
      <input type="email" placeholder="Enter Email" v-model="email">
      <br>
      <input type="password" v-model="password" placeholder="enter password">

      <button type="submit" id="googleButton" @click="signUp()">sign up</button>
      <p id="error"> {{ errorMsg }}</p>

      <router-link to="./login">Already have an acount? go to login</router-link>
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
