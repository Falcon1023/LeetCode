package org.trier.RemoveDuplicatesSortedArray

/**
 * Created by trier on 2017/5/7.
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