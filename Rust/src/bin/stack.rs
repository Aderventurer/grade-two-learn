struct Stack {
    items: Vec<i32>,
    capacity: usize,
}

impl Stack {
    fn new(capacity: usize) -> Self {
        Stack {
            items: Vec::with_capacity(capacity),
            capacity,
        }
    }

    fn push(&mut self, item: i32) {
        if self.items.len() < self.capacity {
            self.items.push(item);
        } else {
            println!("Stack overflow");
        }
    }

    fn pop(&mut self) -> Option<i32> {
        self.items.pop()
    }

    fn peek(&self) -> Option<&i32> {
        self.items.last()
    }
}

fn main() {
    let mut stack = Stack::new(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    println!("{:?}", stack.pop());
    println!("{:?}", stack.peek());
}
