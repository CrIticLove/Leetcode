class Solution:
    def simplifyPath(self, path: str) -> str:
        contents = path.split('/')
        temp = []
        for content in contents:
            if content == '':
                continue
            if content == '.':
                continue
            if content == '..':
                if len(temp) > 0:
                    temp.pop()
                continue
            temp.append('/'+content)
        return ''.join(temp) if len(temp) > 0 else '/'
