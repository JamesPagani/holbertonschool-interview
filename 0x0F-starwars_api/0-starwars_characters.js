#!/usr/bin/node

const request = require('request');
const film = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

function printNames (namesURLs) {
  if (namesURLs.length > 0) {
    request.get(namesURLs.shift(), (error, response, body) => {
      if (error) {
        console.log(error);
      } else {
        console.log(JSON.parse(body).name);
        printNames(namesURLs);
      }
    });
  }
}

request.get(film, (error, response, body) => {
  if (error) {
    console.log(error);
  } else {
    const characters = JSON.parse(body).characters;
    printNames(characters);
  }
});
