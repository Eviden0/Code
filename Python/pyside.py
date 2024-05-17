import sys
from PySide6.QtWidgets import QApplication, QMainWindow, QPushButton

class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("PySide6 Test")
        self.setGeometry(100, 100, 300, 200)

        self.button = QPushButton("Click Me!", self)
        self.button.setGeometry(100, 100, 100, 40)
        self.button.clicked.connect(self.on_button_click)

    def on_button_click(self):
        self.button.setText("Clicked!")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MyWindow()
    window.show()
    sys.exit(app.exec())
