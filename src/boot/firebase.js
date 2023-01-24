import { boot } from 'quasar/wrappers'

import { VueFire, VueFireAuth } from 'vuefire'
import { initializeApp, getApps } from "firebase/app";
import { getDatabase } from "firebase/database";
// Your web app's Firebase configuration
const firebaseConfig = {
apiKey: "AIzaSyBslwY7gKcIWTltrOcEeDooZWzSRRcSBUg",
  authDomain: "waxteras.firebaseapp.com",
  databaseURL: "https://waxteras-default-rtdb.europe-west1.firebasedatabase.app",
  projectId: "waxteras",
  storageBucket: "waxteras.appspot.com",
  messagingSenderId: "658516255745",
  appId: "1:658516255745:web:9d8005921966e5fa6d4c00"
};

const apps = getApps();
let firebaseApp;
if (!apps.length) {
  firebaseApp = initializeApp(firebaseConfig);
} else {
  firebaseApp = apps[0];
}

const db = getDatabase(firebaseApp);

export default boot(async ({ app }) => {
  app.use(VueFire, {
    // imported above but could also just be created here
    firebaseApp,
    modules: [
      // we will see other modules later on
      VueFireAuth(),
    ],
  });
});

console.log('hello world')
export { db };
