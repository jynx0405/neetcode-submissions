class MinStack:

    def __init__(self):
        self.stack = []
        self.prefix = []
        self.top_idx = -1      
        self.pretop = -1

    def push(self, val: int) -> None:
        if len(self.stack) == 0:
            self.prefix.append(val)
            self.pretop += 1
        else:
            if self.prefix[self.pretop] >= val:
                self.prefix.append(val)
                self.pretop += 1

        self.stack.append(val)
        self.top_idx += 1

    def pop(self) -> None:
        if self.top_idx == -1:
            return  

        if self.prefix[self.pretop] == self.stack[self.top_idx]:
            self.prefix.pop()
            self.pretop -= 1

        self.stack.pop()
        self.top_idx -= 1

    def top(self) -> int:
        return self.stack[self.top_idx]

    def getMin(self) -> int:
        return self.prefix[self.pretop]