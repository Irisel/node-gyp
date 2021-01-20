const nodeGyp = require('./build/Release/nodeGyp');

const createObject = nodeGyp.CreateObject;

const add = nodeGyp.Add;

const obj = createObject(10);
console.log(obj.plusOne());
// 打印: 11
console.log(obj.plusOne());
// 打印: 12
console.log(obj.plusOne());
// 打印: 13

const obj2 = createObject(20);
console.log(obj2.plusOne());
// 打印: 21
console.log(obj2.plusOne());
// 打印: 22
console.log(obj2.plusOne());
// 打印: 23

console.log(add(3.1, 5));