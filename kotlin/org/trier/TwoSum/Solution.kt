package org.trier.TwoSum

import java.util.*

/**
 * Created by trier on 2017/5/16.
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