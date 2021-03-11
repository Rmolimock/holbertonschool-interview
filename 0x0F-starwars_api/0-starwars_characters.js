#!/usr/bin/node

const request = require('request');

const recHelper = (arr, i) => {
  if (i === arr.length) return;
  request(arr[i], (err, response, body) => {
    if (!err) {
      console.log(JSON.parse(body).name);
      recHelper(arr, i + 1);
    } else {
      throw err;
    }
  });
};

const arg = process.argv[2];

request(`https://swapi-api.hbtn.io/api/films/${arg}`, (er, res, body) => {
  if (!er) {
    const characters = JSON.parse(body).characters;
    recHelper(characters, 0);
  } else {
    throw er;
  }
});
