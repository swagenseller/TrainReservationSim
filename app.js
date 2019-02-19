// app.js

var dropdown = ["Roma", "Venice"];

var departList = document.getElementById("departing");
var arriveList = document.getElementById("ariving");

for(var i = 0; i < dropdown.length; i++) {
    var opt = dropdown[i];
    var el = document.createElement("option");
    el.textContent = opt;
    el.value = opt;
    departList.appendChild(el);
}

for(var i = 0; i < dropdown.length; i++) {
    var opt = dropdown[i];
    var el = document.createElement("option");
    el.textContent = opt;
    el.value = opt;
    arriveList.appendChild(el);
}

// checking if jquery document is ready
/*$( document ).ready(function() {
  console.log( 'ready!' );
});


// fills the dropdown menu with train stations
$('#select').empty();
$.each(dropdown, function(i, p) {
    $('#select').append($('<option></option>').val(p).html(p));
});
*/
