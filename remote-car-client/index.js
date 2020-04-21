var io = require('socket.io-client')

var socket = io('http://localhost:3000');

  socket.on('connect', function(){});
  socket.on('event', function(data){});
  socket.on('disconnect', function(){});

  socket.on('move', direction => console.log(direction))