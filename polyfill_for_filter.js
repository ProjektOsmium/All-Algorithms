Array.prototype.filter = function(fn) {
    const filteredArray = [];
    for (let i = 0; i < this.length; i++) {
      const value = fn(this[i], i);
      if (value) filteredArray.push(this[i]);
    }
    return filteredArray;
  };
  
  console.log([1, 2, 3, 4, 5].filter(item => item % 2));