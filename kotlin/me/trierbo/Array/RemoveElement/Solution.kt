package me.trierbo.Array.RemoveElement

/**
 * Description:
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

fun main(args:Array<String>){
    val arr = arrayOf(3,4,5,6,1,2,3,4,5,6,3,2,3)
    print(removeElement(arr, 3))
}

fun removeElement(nums: Array<Int>, target: Int): Int{
    var index = 0
    nums.filter { it != target }.map { index++ }
    return index
}