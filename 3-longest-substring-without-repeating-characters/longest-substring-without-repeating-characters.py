class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = ""
        max_len = 0

        for ch in s:
            while ch in seen:
                seen = seen[1:]
                
            seen += ch
        
            max_len = max(max_len, len(seen))
        return max_len
