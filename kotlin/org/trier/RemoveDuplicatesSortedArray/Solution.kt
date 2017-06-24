package org.trier.RemoveDuplicatesSortedArray

/**
 * Description:
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return
 * the new length.
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * For example, Given input array A = [1,1,2] ,
 * Your function should return length = 2, and A is now [1,2] .
 */
class Solution {
    fun removeDuplicates(nums:Array<Int>):Int {
        if(nums.size==0)
            return 0
        var index=1
        for (i in 1 until nums.size){
            if(nums[i]!=nums[index-1])
                nums[index++]=nums[i]
        }
        return index
    }
}

fun main(args:Array<String>){
    var nums:Array<Int> = arrayOf(1,1,2,3,5,8,9,9)
    var solution= Solution()
    print(solution.removeDuplicates(nums))
}