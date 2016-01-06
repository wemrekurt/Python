class Queue:
  def __init__(self):
    self.items = []

  def isEmpty(self):
    return self.items == []

  def enqueue(self,item):
    self.items.insert(0,item) #.append(item)

  def dequeue(self):
    return self.items.pop() #.pop(0)

  def size(self):
    return len(self.items)

  def show(self):
    return self.items
