
<template>
  <div>
    <h1>login</h1>
    <form @submit.prevent="handlesubmit">
      <input type="email" v-model="email">
      <input type="password" v-model="password">
      <button type="submit" @click="googleSignIn">login</button>
    </form>
  </div>
</template>

<script>
  import firebase from "firebase";

 export default {
  data() {
    return {
      email: "",
      password: "",

    };
  },
  methods: {
    googleSignIn: function() {
      const provider = firebase.auth.GoogleAuthProvider();
      firebase.auth().signInWithPopup(provider).then (() => {
        alert("Signed in");
      })
    }
  }
 }
</script>
