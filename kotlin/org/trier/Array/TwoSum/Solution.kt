package org.trier.Array.TwoSum

import java.util.*

/**
 * Description:
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target, where
 * index1 must be less than index2. Please note that your returned answers (both index1 and index2) are
 * not zero-based.
 * You may assume that each input would have exactly one solution.
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

fun twoSum(nums:Array<Int>,target:Int):Array<Int>?{
    var map=HashMap<Int,Int>()
    for(i in 0 until nums.size){
        map.put(nums[i],i)
    }
    for (i in 0 until nums.size){
        var pos=map.get(target-nums[i])
        if (pos!=null && pos>i)
            return arrayOf(i,pos)
    }
    return null
}

fun main(args:Array<String>){
    val scanner=Scanner(System.`in`)
    var num=scanner.nextInt()
    var nums=Array(num,{0})
    for(i in 0 until num){
        nums[i]=scanner.nextInt()
    }
    var target=scanner.nextInt()
    var arr=twoSum(nums,target)
    if(arr!=null)
        println("arr[0] is ${arr[0]}, and arr[1] is ${arr[1]}")
    else
        println("don't exist")
}