var events = require('events')
var EventEmitter = new events.EventEmitter()
//可以直接调用函数
function connection() {
    console.log('connection')
    EventEmitter.emit('data1_received')
}
//也可创建函数对象
var connectHandler = function connected() {
    console.log('连接成功。');
    // 触发 data_received 事件 
    EventEmitter.emit('data1_received');
}

EventEmitter.on('connection', connectHandler)
EventEmitter.on('data1_received', function () {
    console.log('data_received')
})
EventEmitter.emit('connection')
console.log('程序执行完毕')
// emit方法是触发事件，on方法是监听事件，on方法监听到事件后，会执行回调函数。
/*
整个流程
创建处理函数
绑定事件和处理函数
触发事件
*/