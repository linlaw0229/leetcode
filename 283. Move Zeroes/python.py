class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        y=0
        for n in range(len(nums)):
           if nums[n]:
            nums[n], nums[y] = nums[y], nums[n]
            y+=1
        
        
