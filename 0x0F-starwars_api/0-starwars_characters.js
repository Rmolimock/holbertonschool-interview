#!/usr/bin/node

const request = require('request');

const requestEachCharacterName = (character_list, line) =>
{
  const num_characters = character_list.length
  if (line === num_characters) return;
  request(character_list[line], (er, response, body) =>
  {
    if (!er)
    {
      console.log(JSON.parse(body).name);
      requestEachCharacterName(character_list, line + 1);
    } else
    {
      throw er;
    }
  });
};

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`, (er, response, body) => {
  if (!er)
  {
    requestEachCharacterName(JSON.parse(body).characters, 0);}
  else
  {
    throw er;
  }
});