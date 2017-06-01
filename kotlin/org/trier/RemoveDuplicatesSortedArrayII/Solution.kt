package org.trier.RemoveDuplicatesSortedArrayII

/**
 * Created by trier on 2017/5/8.
 */
class Solution {
    fun removeDuplicates(nums:Array<Int>):Int {
        var index=0
        var count=0
        val length=nums.size
        for(i in 1 until length){
            if(nums[i]!=nums[index]) {
                nums[++index] = nums[i]
                count=0
            }
            else{
                if(count==0) {
                    index++
                    count++
                }
            }
        }
        return index+1
    }
}

fun main(args:Array<String>){
    var nums:Array<Int> = arrayOf(1,1,2,3,5,8,9,9)
    var solution= Solution()
    print(solution.removeDuplicates(nums))
}