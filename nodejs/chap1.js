// 阻塞代码
var fs = require('fs');
var data = fs.readFileSync('input.txt');
console.log(data.toString());
console.log("Program Ended\n")
// 非阻塞代码
var fs = require("fs");

fs.readFile('input.txt', function (err, data) {
    if (err) return console.error(err);
    console.log(data.toString());
});

console.log("程序执行结束!");


var fs = require('fs');
fs.readFile('./input.txt', function (err, data) {
    if (err) return console.log(err.stack);
    console.log(data.toString());
});
console.log("程序执行结束!");
