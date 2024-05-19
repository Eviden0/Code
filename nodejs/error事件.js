var events = require('events');
var emitter = new events.EventEmitter();
emitter.on('error', function (err) {
    console.log('An error occurred!', err);
})
emitter.emit('error', new Error('Something went wrong!'));