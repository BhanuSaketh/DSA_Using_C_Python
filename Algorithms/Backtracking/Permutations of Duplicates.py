##Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
def permuteUnique(nums):
  def backtrack(start, end):
      if start == end:
          ans.append(nums[:])
          return
      seen = set()  
      for i in range(start, end):
          if nums[i] in seen:
              continue  
          seen.add(nums[i])
          nums[start], nums[i] = nums[i], nums[start]
          backtrack(start + 1, end)
          nums[start], nums[i] = nums[i], nums[start]  

ans = []
nums.sort()
backtrack(0, len(nums))
return ans
