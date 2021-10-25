class Trie:

    def __init__(self):
        self.children = [None]*26
        self.isEnd = False


    def insert(self, word: str) -> None:
        node = self
        for c in word:
            index = ord(c) - ord('a')
            if not node.children[index]:
                node.children[index] = Trie()
            node = node.children[index]
        node.isEnd = True
        return


    def search(self, word: str) -> bool:
        node = self
        for c in word:
            index = ord(c) - ord('a')
            if not node.children[index]:
                return False
            node = node.children[index]
        return node.isEnd


    def startsWith(self, prefix: str) -> bool:
        node = self
        for c in prefix:
            index = ord(c) - ord('a')
            if not node.children[index]:
                return False
            node = node.children[index]
        return True



# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)