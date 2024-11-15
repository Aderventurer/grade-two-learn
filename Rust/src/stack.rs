#[derive(Debug, Clone)]
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

    fn is_empty(&self) -> bool {
        self.items.is_empty()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_push() {
        let mut stack = Stack::new(2);
        stack.push(1);
        stack.push(2);
        assert_eq!(stack.peek(), Some(&2));
        stack.push(3);  
        assert_eq!(stack.items.len(), 2);  
    }

    #[test]
    fn test_pop() {
        let mut stack = Stack::new(2);
        stack.push(1);
        stack.push(2);
        assert_eq!(stack.pop(), Some(2));  
        assert_eq!(stack.pop(), Some(1));
        assert_eq!(stack.pop(), None);     
    }

    #[test]
    fn test_peek() {
        let mut stack = Stack::new(2);
        assert_eq!(stack.peek(), None);
        stack.push(1);
        assert_eq!(stack.peek(), Some(&1));
        stack.push(2);
        assert_eq!(stack.peek(), Some(&2));
    }

    #[test]
    fn test_is_empty() {
        let mut stack = Stack::new(2);
        assert!(stack.is_empty());
        stack.push(1);
        assert!(!stack.is_empty());
        stack.pop();
        assert!(stack.is_empty());
    }
}
