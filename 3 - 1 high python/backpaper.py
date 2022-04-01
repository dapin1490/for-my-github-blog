import random

be = 0
shi = 0
mu = 0
for _ in range(30001):
    num = random.randint(1, 3)
    if num == 1:
        be += 1
    elif num == 2:
        shi += 1
    elif num == 3:
        mu += 1

if be > mu and be > shi:
    print("be")
elif shi > be and shi > mu:
    print("shi")
elif mu > be and mu > shi:
    print("mu")
else:
    print("retry")

