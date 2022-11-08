def makeGood(s):
    stack = []

    for c in list(s):
        if stack and abs(ord(c) - ord(stack[-1])) == 32:
            stack.pop()
        else:
            stack.append(c)
    return ''.join(stack)