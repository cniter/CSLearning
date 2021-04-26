function debounce(func, wait) {
    let timer;
    return function() {
        let context = this;
        let args = arguments;
        console.log(this);

        if (timer) clearTimeout(timer);
        timer = setTimeout(() => {
            func.apply(context, args);
            timer = null;
        }, wait);
    }
}

let a = {
    a: 1,
    b: () => console.log("dfasd")
}

debounce(a.b, 1000).apply(a);
