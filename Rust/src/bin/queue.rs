struct Queue {
    items: Vec<i32>,
    capacity: usize,
}

impl Queue {
    fn new(capacity: usize) -> Self {
        Queue {
            items: Vec::with_capacity(capacity),
            capacity,
        }
    }

    fn enqueue(&mut self, item: i32) {
        if self.items.len() < self.capacity {
            self.items.push(item);
        } else {
            println!("Queue overflow");
        }
    }

    fn dequeue(&mut self) -> Option<i32> {
        if !self.items.is_empty() {
            Some(self.items.remove(0))
        } else {
            println!("Queue underflow");
            None
        }
    }

    fn peek(&self) -> Option<&i32> {
        self.items.first()
    }
}

fn main() {
    let mut queue = Queue::new(5);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    println!("{:?}", queue.dequeue());
    println!("{:?}", queue.peek());
}
