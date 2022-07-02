# 创建一个Student类
class Student:
    # 返回对象字符串
    def __str__(self):
        return "Student"

    # 打印对象字符串
    def printStudent(self):
        print(self.__str__())


# 创建一个子类GraduateStudent继承于父类Student
class GraduateStudent(Student):
    # 返回对象字符串
    def __str__(self):
        return "GraduateStudent"


# 创建一个Student类的对象a
a = Student()
# 创建一个GraduateStudent类的对象b
b = GraduateStudent()
a.printStudent()
b.printStudent()
