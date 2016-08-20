class Node(object):
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

class HuffmanCoding(object):
    def __init__(self, chars, freq):
        self.chars = chars
        self.freq = freq
        self.n = len(chars)

        self.firstQueue = []
        self.secondQueue = []

    def ExtractMin(self):
        if not self.secondQueue:
            item = self.firstQueue[0]
            self.firstQueue.pop(0)
            return item
        elif not self.firstQueue:
            item = self.secondQueue[0]
            self.secondQueue.pop(0)
            return item
        else:
            if self.firstQueue[0].freq < self.secondQueue[0].freq:
                item = self.firstQueue[0]
                self.firstQueue.pop(0)
            else:
                item = self.secondQueue[0]
                self.secondQueue.pop(0)
            return item


    def Coding(self):
        for i in range(self.n):
            node = Node(self.chars[i], self.freq[i])
            self.firstQueue.append(node)

        while self.firstQueue or len(self.secondQueue) != 1:
            left = self.ExtractMin()
            right = self.ExtractMin()
            top = Node("$", left.freq + right.freq)
            top.left = left
            top.right = right
            self.secondQueue.append(top)

        return self.secondQueue.pop(0)

    def isLeaf(self, root):
        if (not root.left and not root.right):
            return True
        else: return False

    def PrintCode(self, root, arr, top):
        if (root.left):
            arr.append(0)
            self.PrintCode(root.left, arr, top+1)
            arr.pop()
        if (root.right):
            arr.append(1)
            self.PrintCode(root.right, arr, top+1)
            arr.pop()
        if (self.isLeaf(root)):
            print root.char,
            for i in range(top):
                print arr[i],
            print
 
def Inorder(root):
    if root:
        Inorder(root.left)
        print root.char,
        Inorder(root.right)

if __name__ == "__main__":
    chars = ['a', 'b', 'c', 'd', 'e', 'f']
    freq = [5, 9, 12, 13, 16, 45]
    h = HuffmanCoding(chars, freq)

    root = h.Coding()
    #Inorder(root)
    #print
    arr = list()
    h.PrintCode(root, arr, 0)
