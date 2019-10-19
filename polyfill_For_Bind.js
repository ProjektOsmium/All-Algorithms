const bind = (fn, context, ...boundedArgs) => (...newArrgs) => fn.apply(context, [...boundedArgs, newArrgs]);

const test = {
  name: "shyam",
  sayHello: function() {
    console.log("Hi", this.name);
  }
};

const boundedHello = test.sayHello.bind({ name: "arora" });
const customBind = bind(test.sayHello, { name: "new context" });

test.sayHello();
boundedHello();
customBind();