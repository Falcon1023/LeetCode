package org.trier.Array.`3SumClosest`

/**
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given
 * number, target. Return the sum of the three integers. You may assume that each input would have exactly
 * one solution.
 * For example, given array S = {-1 2 1 -4} , and target = 1 .
 * The sum that is closest to the target is 2. ( -1 + 2 + 1 = 2 ).
 */

fun main(args:Array<String>){
    val nums= arrayOf(-1,2,1,-4)
    print(threeSumClosest(nums,1))
}

fun threeSumClosest(nums:Array<Int>,target:Int):Int{
    var min=Int.MAX_VALUE
    var current:Int
    var j:Int
    var k:Int
    for (i in 0..nums.size-2){
        j=i+1
        k=nums.size-1
        while (j<k){
            current=Math.abs((nums[i]+nums[j]+nums[k])-target)
            if(current<min){
                min=current
            }
            j++
            while (nums[j]==nums[j-1])
                j++
            k--
            while (nums[k]==nums[k+1])
                k--
        }
    }
    return min
}
