def main():
    try:
        number1, number2 = eval(
            input("Enter two numbers,separated by a comma:"))
        result = number1 / number2
        print("Result is", result)
    # 捕获并处理除数为0的异常
    except ZeroDivisionError:
        print("Division by zero!")
    # 捕获并处理输入格式的异常
    except SyntaxError:
        print("A comma may be missing in the input")
    # 捕获并处理其他的异常
    except:
        print("Something wrong in the input")
    else:
        print("No exception")
    finally:
        print("The finally clause is executed")


main()
