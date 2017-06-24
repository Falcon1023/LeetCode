package org.trier.RemoveDuplicatesSortedArrayII

/**
 * Description
 * Follow up for "Remove Duplicates": What if duplicates are allowed at most twice?
 * For example, given sorted array A = [1,1,1,2,2,3] , your function should return length = 5 , and A is
 * now [1,1,2,2,3]
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