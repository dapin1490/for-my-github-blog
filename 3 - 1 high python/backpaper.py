def example(**param):
    for key, val in param.items():
        print("{} : {}".format(key, val))

example(a = 1, b = 2, c = "3")
