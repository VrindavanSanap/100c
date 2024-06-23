const fs = require('fs');
// Import the functions you need from the SDKs you need
// Import the functions you need from the SDKs you need

import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyBlzIFhsDYliefkhuwT3VT8q6pNPlmfFDM",
  authDomain: "mini-projects-8a5f2.firebaseapp.com",
  projectId: "mini-projects-8a5f2",
  storageBucket: "mini-projects-8a5f2.appspot.com",
  messagingSenderId: "818666275224",
  appId: "1:818666275224:web:cb0903069c2c79f0bdabed",
  measurementId: "G-FZL60FFQ8Q"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);
// Initialize Firebase
firebase.initializeApp(firebaseConfig);
const db = firebase.firestore();

// Read JSON file
var i = 0;
var path = '/Users/vrindavan/code/languages/100c/quiz/train.json'
fs.readFile(path, 'utf8', async (err, data) => {
  if (err) {
    console.error('Error reading file:', err);
    return;
  }
    // Parse JSON data
    const jsonData = JSON.parse(data);
    console.log(jsonData[0]);
    jsonData.forEach((number)=>{
      console.log(number, i)
      i++;
      setDoc(doc(db, "questions", i), number);
    })

});

var path = '/Users/vrindavan/code/languages/100c/quiz/test.json'
fs.readFile(path, 'utf8', async (err, data) => {
  if (err) {
    console.error('Error reading file:', err);
    return;
  }
    // Parse JSON data
    const jsonData = JSON.parse(data);
    console.log(jsonData[0]);
    jsonData.forEach((number)=>{
      console.log(number, i)
      i++;
      setDoc(doc(db, "questions", i), number);
    })
});

var path = '/Users/vrindavan/code/languages/100c/quiz/valid.json'
fs.readFile(path, 'utf8',async(err, data) => {
  if (err) {
    console.error('Error reading file:', err);
    return;
  }
    // Parse JSON data
    const jsonData = JSON.parse(data);
    console.log(jsonData[0]);
    jsonData.forEach((number)=>{
      console.log(number, i)
      i++;
      setDoc(doc(db, "questions", i), number);
    })
});

