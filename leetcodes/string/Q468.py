class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        # if ipv4
        if '.' in queryIP:
            parts = queryIP.split('.')
            if len(parts) == 4:
                for part in parts:
                    if len(part) > 1 and part[0] == '0':
                        return 'Neither'
                    try:
                        num = int(part)
                        if num > 255 or num < 0:
                            return 'Neither'
                    except:
                        return 'Neither'
                return 'IPv4'
        if ':' in queryIP:
            parts = queryIP.split(':')
            if len(parts) == 8:
                for part in parts:
                    if len(part) > 4 or len(part) < 1:
                        return 'Neither'
                    for d in part:
                        if d not in '0123456789abcdefABCDEF':
                            return 'Neither'
                return 'IPv6'
        return 'Neither'
