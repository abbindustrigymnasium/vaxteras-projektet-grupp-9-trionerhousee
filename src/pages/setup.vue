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
    document.cookie = 'admin=' + false + 'expiers=Fri, 31 Dec 2025 23:59:59 GMT; SamSite=None; Secure;';
    document.cookie = 'name=' + name + '; expiers=Fri, 31 Dec 2025 23:59:59 GMT; SamSite=None; Secure; ';
    document.cookie = 'userUid=' + user.uid + '; expiers=Fri, 31 Dec 2025 23:59:59 GMT; SamSite=None; Secure; ';
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
<q-page class="container flex column justify-center items-center ">
  <div class="content flex column justify-center items-center">
      <h1>Sign up</h1>
    <form class="yes flex column justify-center items-center">
      <input class="text" type="text" placeholder="Enter name" v-model="name">
      <br>
      <input class="text" type="number" placeholder="Eneter phone number" v-model="phoneNumber">
      <br>
      <input class="text" type="email" placeholder="Enter Email" v-model="email">
      <br>
      <input class="text" type="password" v-model="password" placeholder="enter password">
      <br>

      <button type="submit" id="SignUp" @click="signUp()">sign up</button>
      <p id="error"> {{ errorMsg }}</p>

      <router-link to="./login">Already have an acount? go to login</router-link>
      <br>
      <button @click="goToMainPage()">
              go back to the main page
      </button>
      <br>





    </form>
  </div>

</q-page>
</template>

<style>
button {
  border-radius: 10px;
}
.content {
  background-color: rgba(183, 253, 253, 0.768);
  width: 50%;
  margin: 3vh;
  padding: 2vh;
  border-radius: 20px;
}
#signUp {
  width: 1%;
}
#error {
  font-size: x-small;
  color: red;
}
.text {
  width: 300px;
  margin: 2px;
  background-color: rgb(204, 234, 255);
}

.container {
  background-image: url(./../../public/icons/wallpaper5.jpg);
  background-size: cover;
}


</style>
