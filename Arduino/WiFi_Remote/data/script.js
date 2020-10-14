'use strict';

  function sendButtonPress(id, display)
  {
    console.log(id);

    document.getElementById('display').innerHTML=display;
    setTimeout(function(){
        document.getElementById("display").innerHTML = '';
    }, 500);

    return fetch(
      `http://${location.host}/api`,
      {
        method: 'POST',
        body: JSON.stringify({
          cmd: id,
        }),
        headers: {
          'Content-Type': 'application/json'
        }
      }
    );
  }

document.addEventListener("DOMContentLoaded", function(event) {

    // const animateIndicator = function() {
    //     document.getElementById('indicator').style.display='block';
    //     setTimeout(function(){
    //         document.getElementById("indicator").style.display = 'none';
    //     }, 50);
    // }




    // const sendRequest = function(id) {
    //   console.log(id);
    //   return;

    //     return fetch(
    //       `http://${location.host}/api`,
    //       {
    //         method: 'POST',
    //         body: JSON.stringify({
    //           command: 123,
    //           code: 321
    //         }),
    //         headers: {
    //           'Content-Type': 'application/json'
    //         }
    //       }
    //     );
    // }


    // let promise;
    // let targets = document.getElementsByClassName('button');
    // for (let i = 0; i < targets.length; i++) {
    //   targets[i].addEventListener("click", sendRequest(targets[i].id));
    // }

});