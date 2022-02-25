class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def getSortkey(string:str):
            [identifyer, content] = string.split(' ', maxsplit=1)
            return (1,) if content[0].isdigit() else (0, content, identifyer)
        return sorted(logs, key=getSortkey)
