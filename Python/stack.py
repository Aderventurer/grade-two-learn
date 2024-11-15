import unittest

class Stack:
    def __init__(self, capacity):
        self.stack = []
        self.capacity = capacity

    def push(self, item):
        if len(self.stack) < self.capacity:
            self.stack.append(item)
        else:
            print("Stack overflow")

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        else:
            print("Stack underflow")
            return None

    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        else:
            return None

    def is_empty(self):
        return len(self.stack) == 0

class TestStackOperations(unittest.TestCase):
    def test_push(self):
        stack = Stack(2)
        stack.push(1)
        self.assertEqual(stack.peek(), 1)
        stack.push(2)
        self.assertEqual(stack.peek(), 2)
        stack.push(3)  
        self.assertEqual(len(stack.stack), 2)

    def test_pop(self):
        stack = Stack(2)
        stack.push(1)
        stack.push(2)
        self.assertEqual(stack.pop(), 2)
        self.assertEqual(stack.pop(), 1)
        self.assertIsNone(stack.pop()) 
    def test_peek(self):
        stack = Stack(2)
        self.assertIsNone(stack.peek()) 
        stack.push(1)
        self.assertEqual(stack.peek(), 1)
        stack.push(2)
        self.assertEqual(stack.peek(), 2)

    def test_is_empty(self):
        stack = Stack(2)
        self.assertTrue(stack.is_empty())
        stack.push(1)
        self.assertFalse(stack.is_empty())
        stack.pop()
        self.assertTrue(stack.is_empty())

if __name__ == '__main__':
    unittest.main()
