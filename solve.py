import pyautogui as pg
import time

def sudoku_clear(filename):
    file = open("solution/solved.txt","r")   
    char = file.read(1)
    i = 0
    while char != "X":
        time.sleep(0.5)
        pg.press(char)
        pg.press("right")
        i+=1
        if i == 9 :
            pg.press("down")
            i=0
        char = file.read(1)
    file.close()


time.sleep(5)
sudoku_clear("solution/solved.txt")
