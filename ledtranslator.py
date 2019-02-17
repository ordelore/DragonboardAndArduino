import firebase_admin
import os
import serial
import time
from firebase_admin import credentials
from firebase_admin import db

oldMessage = ""


cred = credentials.Certificate(r"C:\Users\sammy\Documents\Uncommon Hacks\key-file.json")
firebase_admin = firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://readandwritetutorialagent.firebaseio.com/'
})
ref = db.reference('ageInfo/runningAverage')

i=0

ser = serial.Serial('COM4' ,9600)
while i < 100:



    message = ref.get();


    if (oldMessage != message):
        print(message)

        time.sleep(2)
        ser.write(bytes(message, encoding='utf-8'))
        i = i+1
        oldMessage = message

    time.sleep(20)
