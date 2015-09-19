class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        m = dict()
        for i in range(len(nums)):
            if target - nums[i] in m:
                return [m[target-nums[i]]+1,i+1]
            m[nums[i]] = i