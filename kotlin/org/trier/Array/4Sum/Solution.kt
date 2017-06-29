package org.trier.Array.`4Sum`

/**
 * Description:
 * Given an array S of n integers, are there elements a, b, c , and d in S such that a + b + c +
 * d = target ? Find all unique quadruplets in the array which gives the sum of target.
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 * For example, given array S = {1 0 -1 0 -2 2} , and target = 0 .
 * A solution set is:
 * (-1, 0, 0, 1)
 * (-2, -1, 1, 2)
 * (-2, 0, 0, 2)
 */

fun main(args:Array<String>){
    val nums = arrayOf(1,0,-1,0,-2,2)
    val target = 0
    val list = fourSum(nums, target)
    print(list)
}

// 排序后循环两次之后左右加逼
fun fourSum(nums:Array<Int>, target: Int):List<List<Int>>{
    val list = mutableListOf<List<Int>>()
    if (nums.size < 4)
        return list
    nums.sort()
    for (i in 0..nums.size-4){
        for (j in i+1..nums.size-3){
            var k = j+1
            var l = nums.size-1
            while (k < l){
                if (nums[i]+nums[j]+nums[k]+nums[l] == target) {
                    list.add(listOf(nums[i], nums[j], nums[k], nums[l]))
                    while (nums[++k] == nums[k-1]){}
                    while (nums[--l] == nums[l+1]){}
                } else if (nums[i]+nums[j]+nums[k]+nums[l] < target) {
                    while (nums[++k] == nums[k-1]){}
                } else {
                    while (nums[--l] == nums[l+1]){}
                }
            }
        }
    }
    return list
}