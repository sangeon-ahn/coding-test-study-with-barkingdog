from multiprocessing import Process
import time

def func0():
    list_var = [1,2,3]
    while True:
      func3();
      time.sleep(0.5)

def func1():
    list_var = ["a","b","c"]
    while True:
      print(1)
      time.sleep(0.5)
    # for x in list_var:
    #     print(x)
    #     time.sleep(0.5) 

def func3():
  print(2)
if __name__ == '__main__':
    p0 = Process(target=func0)
    p1 = Process(target=func1)
    p0.start()
    p1.start()
    print("main process is done")