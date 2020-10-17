class Queue {

    constructor() {
        this.data = []
    }

    enqueue(element) {
        this.data.push(element)
    }

    dequeue() {
        this.data.shift()
    }

    front() {
        return this.data[0]
    }

    back() {
        return this.data[this.data.length - 1]
    }

    empty() {
        return this.data.length === 0
    }
}

const main = () => {
    let q = new Queue()
    q.enqueue(30)
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(40)
    q.dequeue()
    console.log(q.front()) // it should be 10.
}
main()