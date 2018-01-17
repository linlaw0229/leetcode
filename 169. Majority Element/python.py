class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count= 0
        candidate= 0
        for n in nums:
            if not count:
                candidate = n
            
            if candidate == n:
                count+=1
            else:
                count-=1
        return candidate
