> Given an array of integers, find two numbers such that they add up to a specific target number.
> 
> The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
>
> You may assume that each input would have exactly one solution.
>
> Input: numbers={2, 7, 11, 15}, target=9
> Output: index1=1, index2=2
求解方法，利用hash表，建立倒排索引，即对每一个数字k和下标i，
在hash表中存在键为k值为i的元素。
然后寻找target - n是否在这个表中，每次查表只需O(1)时间复杂度，
所以总的时间复杂度是O(n)，空间复杂度是O(n)。
