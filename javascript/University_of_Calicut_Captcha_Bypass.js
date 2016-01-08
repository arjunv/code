// ==UserScript==
// @name        University of Calicut - Captcha Bypass
// @namespace   UoC
// @description Greasemonkey Javascript for Captcha Bypass in University of Calicut results page
// @include     http://202.88.252.21/CuPbhavan/*
// @version     1
// @grant       none
// ==/UserScript==

function checkSum() {
  var a = document.getElementById('fst').value;
  var b = document.getElementById('snd').value;
  document.getElementById('sum').value = parseInt(a) + parseInt(b);
}

clickd = document.getElementById('sum');
clickd.addEventListener('focus', checkSum, false);
