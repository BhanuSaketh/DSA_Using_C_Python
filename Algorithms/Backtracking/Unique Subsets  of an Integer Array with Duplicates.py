## Given an integer array nums that may contain duplicates, return all possible subset the solution set must not contain duplicate subsets.

temp,ans=[],[]
nums=[1,2,2]
nums.sort()

def backtrack(start,end):
  ans.append(temp[:])
  for i in range(start, len(nums)):
    if i > start and nums[i] == nums[i - 1]:  
        continue
    temp.append(nums[i])
    backtrack(i + 1,len(nums))
    temp.pop()

backtrack(0,len(nums))
print(ans)

#output:[[],[1],[1,2],[1,2,2],[2],[2,2]]
