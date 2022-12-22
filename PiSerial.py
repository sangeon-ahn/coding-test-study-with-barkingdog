from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
import time
import sys
import serial
import schedule

# 파이어베이스에서 예약시간 가져오는 코드 작성
reserved_time = "10:30"

# 아두이노와 파이 시리얼 연결
com = serial.Serial(port = "/dev/ttyACM0",
        baudrate = 9600,
        bytesize = serial.EIGHTBITS,
        parity = serial.PARITY_NONE,
        timeout = 1)

#스텝모터 제어 쓰레드 선언
class StepMoterController(QThread):
  def __init__(self, parent):
      super().__init__(parent)
      self.count = 0

  def job(self):
    # count의 나머지를 아두이노에 보내고 0, 1, 2에 따라 아침, 점심, 저녁에 해당하는 모터 제어
    # 코드가 아두이노에서 돌아간다.
    com.write(self.count % 3)
    self.count = self.count + 1
    
    # reserved_time이 되었을 때 self.job 함수를 실행시킨다.
  def run(self):
    schedule.every().day.at(reserved_time).do(self.job)

    while True:
      schedule.run_pending()
      time.sleep(1)

class MainWidget(QWidget):
  def __init__(self):
    super().__init__()

    # 메인위젯이 생성될 때 스텝모터 제어 쓰레드를 만들고 시작한다.
    x = StepMoterController(self)
    x.start()

if __name__ == '__main__':
  app = QApplication(sys.argv)
  widget = MainWidget()
  widget.show()
  sys.exit(app.exec_())