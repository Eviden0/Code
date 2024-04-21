const EventEmitter = require('events')
const myEvent = new EventEmitter()
myEvent.on('事件1',()=>{
    console.log("1 is running!")
})
myEvent.on('事件1',()=>{
    console.log("1 is running by aysinc I/O")
})
myEvent.emit('事件1')