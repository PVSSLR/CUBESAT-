import os
import subprocess

ino = r"C:\Users\slrbu\Desktop\CUBESAT\July 2019\CUBESAT\nano_temp\nano_temp.ino"
arduino = r"C:\Program Files (x86)\Arduino\arduino.exe"
subprocess.Popen((arduino, ino))
