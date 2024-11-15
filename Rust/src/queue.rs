#[derive(Debug, Clone)]
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

    fn is_empty(&self) -> bool {
        self.items.is_empty()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_enqueue() {
        let mut queue = Queue::new(2);
        queue.enqueue(1);
        queue.enqueue(2);
        assert_eq!(queue.peek(), Some(&1));
        queue.enqueue(3); 
        assert_eq!(queue.items.len(), 2);
    }

    #[test]
    fn test_dequeue() {
        let mut queue = Queue::new(2);
        queue.enqueue(1);
        queue.enqueue(2);
        assert_eq!(queue.dequeue(), Some(1));
        assert_eq!(queue.dequeue(), Some(2));
        assert_eq!(queue.dequeue(), None); 
    }

    #[test]
    fn test_peek() {
        let mut queue = Queue::new(2);
        assert_eq!(queue.peek(), None);
        queue.enqueue(1);
        assert_eq!(queue.peek(), Some(&1));
        queue.enqueue(2);
        assert_eq!(queue.peek(), Some(&1));
    }

    #[test]
    fn test_is_empty() {
        let mut queue = Queue::new(2);
        assert!(queue.is_empty());
        queue.enqueue(1);
        assert!(!queue.is_empty());
        queue.dequeue();
        assert!(queue.is_empty());
    }
}
