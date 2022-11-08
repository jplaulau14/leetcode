def containsDuplicates(nums):
    dict_ = {}

    for num in nums:
        if num not in dict_:
            dict_[num] = 0

        dict_[num] += 1
    
    dict_ = list(dict_.values())

    for num in dict_:
        if num > 1:
            return True
    return False

print(containsDuplicates([1, 2, 3, 4]))
