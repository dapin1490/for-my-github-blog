class Person:
    def sleep(self):
        print('sleep')

class Student(Person):
    def study(sself):
        print('study')

class Worker(Person):
    def work(self):
        print('work')
    def study(self):
        print('study as a worker')

class JLee(Student, Worker):
    def run(self):
        print('run')

a = Worker(); b = JLee()

# (a)
print(isinstance(a, Person))

# (b)
a.study(); b.study()

# (c)
# a.run()  # AttributeError: 'Worker' object has no attribute 'run'
