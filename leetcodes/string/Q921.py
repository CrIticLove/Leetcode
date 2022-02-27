class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        st = []
        for c in s:
            if c == '(':
                st.append(0)
            elif len(st):
                if st[-1]==0:
                    st.pop()
                else:
                    st.append(1)
            else:
                st.append(1)
        return len(st)
