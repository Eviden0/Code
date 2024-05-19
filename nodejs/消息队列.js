/*
* 事件触发器
node会产生一个消息队列,一次将事件放入队列,然后触发器从队列中取出事件,执行事件处理函数
on方法绑定消息的第一个参数是事件的名字,字符串类型,然后为一个事件注册一个监听器接受一个字符串 event 和一个回调函数。
* */
var events = require('events');
var emitter = new events.EventEmitter();
emitter.on('some_event', function (ar1, ar2) {
    console.log('listen_1', ar1, ar2);
})
function listen_2() {
    console.log('listen_2 is called!');
}
emitter.on('some_event', listen_2)
// 移除监听器
emitter.on('some_event', function () {
    //此处移除listen_2监听器的事件排在消息队列的最后,因此还是会先调用再移除
    emitter.removeListener('some_event', listen_2)
    console.log('listen_2 is removed!');
})
emitter.emit('some_event', 'a', 'b');
//再次调用发现listen_2已经成功从消息队列移除,验证成功
emitter.emit('some_event', 'c', 'd');

