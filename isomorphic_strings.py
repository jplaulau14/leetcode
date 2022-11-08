def transform(s):
    hash_map = {}
    new_str = []
    # add
    for i, c in enumerate(s):
        if c not in hash_map:
            hash_map[c] = i 
        new_str.append(str(hash_map[c]))
    return ''.join(new_str)

def isIsomorphic(s, t):
    return transform(s) == transform(t)

s = "add"
t = "egg"

print(isIsomorphic(s, t))

        
        