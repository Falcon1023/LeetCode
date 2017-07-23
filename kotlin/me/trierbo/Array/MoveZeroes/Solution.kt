package me.trierbo.Array.MoveZeroes

/**
 * Given an array nums , write a function to move all 0's to the end of it while maintaining the relative order
 * of the non-zero elements.
 * For example, given nums = [0, 1, 0, 3, 12] , after calling your function, nums should be [1, 3,
 * 12, 0, 0] .
 * Note:
 * 1. You must do this in-place without making a copy of the array.
 * 2. Minimize the total number of operations.
 */

fun main(args: Array<String>){
    val nums = arrayOf(0,1,0,3,6,0,2,1,0)
    moveZeroes(nums)
    nums.map { print(it) }
}

fun moveZeroes(nums: Array<Int>){
    var index = 0
    nums.map { if (it != 0){
        nums[index++] = it
    } }
    for (i in index+1..nums.size-1)
        nums[i] = 0
}
