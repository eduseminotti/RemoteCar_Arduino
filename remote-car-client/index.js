var io = require('socket.io-client')

var socket = io('https://remote-car-server.herokuapp.com/');

  socket.on('connect', function(){});
  socket.on('event', function(data){});
  socket.on('disconnect', function(){});

  socket.on('move', direction => console.log(direction))