import unittest

class Queue:
    def __init__(self, capacity):
        self.queue = []
        self.capacity = capacity

    def enqueue(self, item):
        if len(self.queue) < self.capacity:
            self.queue.append(item)
        else:
            print("Queue overflow")

    def dequeue(self):
        if not self.is_empty():
            return self.queue.pop(0)
        else:
            print("Queue underflow")
            return None

    def peek(self):
        if not self.is_empty():
            return self.queue[0]
        else:
            return None

    def is_empty(self):
        return len(self.queue) == 0

class TestQueueOperations(unittest.TestCase):
    def test_enqueue(self):
        queue = Queue(2)
        queue.enqueue(1)
        self.assertEqual(queue.peek(), 1)
        queue.enqueue(2)
        self.assertEqual(queue.peek(), 1)
        queue.enqueue(3)  
        self.assertEqual(len(queue.queue), 2)

    def test_dequeue(self):
        queue = Queue(2)
        queue.enqueue(1)
        queue.enqueue(2)
        self.assertEqual(queue.dequeue(), 1)
        self.assertEqual(queue.dequeue(), 2)
        self.assertIsNone(queue.dequeue()) 
    def test_peek(self):
        queue = Queue(2)
        self.assertIsNone(queue.peek()) 
        queue.enqueue(1)
        self.assertEqual(queue.peek(), 1)
        queue.enqueue(2)
        self.assertEqual(queue.peek(), 1)
        queue.dequeue()
        self.assertEqual(queue.peek(), 2)

    def test_is_empty(self):
        queue = Queue(2)
        self.assertTrue(queue.is_empty())
        queue.enqueue(1)
        self.assertFalse(queue.is_empty())
        queue.dequeue()
        self.assertTrue(queue.is_empty())

if __name__ == '__main__':
    unittest.main()
