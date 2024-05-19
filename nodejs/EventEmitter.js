var EventEmitter = require('events').EventEmitter;
var event = new EventEmitter();
event.on('some_event', function () {
    console.log('some_event 事件触发');
})
setTimeout(function () {
    event.emit('some_event')
}, 1000)
// EventEmitter 的每个事件由一个事件名和若干个参数组成，事件名是一个字符串，
// 通常表达一定的语义。对于每个事件，EventEmitter 支持 若干个事件监听器。