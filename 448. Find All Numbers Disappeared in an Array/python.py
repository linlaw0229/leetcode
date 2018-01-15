class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for n in nums:
            nums[abs(n)-1] = -abs(nums[abs(n)-1])
        x= []
        for i in xrange(len(nums)):
            if nums[i] > 0:
                x.append(i+1)
        return x
