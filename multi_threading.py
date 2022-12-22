import threading
import time
  
def func0(list_var):
    for x in list_var:
        print(x)
        time.sleep(0.5)  
  
def func1(list_var):
    for x in list_var:
        print(x)
        time.sleep(1)  
  
if __name__ == "__main__":
    t1 = threading.Thread(target=func0, args=([1,2,3],))
    t2 = threading.Thread(target=func1, args=(["a","b","c"],))
  
    t1.start()
    t2.start()
  
    t1.join()
    t2.join()