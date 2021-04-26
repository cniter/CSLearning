function promiseAll(promises) {
    let count = promises.length;
    let result = new Array(count);
    let index = 0;
    return new Promise((resolve, reject) => {
        for (let promise of promises) {
            Promise.resolve(promise).then(res => {
                index++;
                result[index-1] = res;

                if (index === count) {
                    return resolve(result);
                }
            }, err => reject(err))
        }
    })
}

let promise1 = new Promise(function(resolve) {
    resolve(1);
  });
  let promise2 = new Promise(function(resolve) {
    resolve(2);
  });
  let promise3 = new Promise(function(resolve) {
    resolve(3);
  });
  
  let promiseAll1 = promiseAll([promise1, promise2, promise3]);
  promiseAll1.then(function(res) {
    console.log(res);
  });
  