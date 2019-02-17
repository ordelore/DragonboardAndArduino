import firebase_admin
import subprocess
from firebase_admin import credentials
from firebase_admin import db

cred = credentials.Certificate("key-file.json")
firebase_admin = firebase_admin.initialize_app(cred, {
    'databaseURL': 'https://readandwritetutorialagent.firebaseio.com/'
})
ref = db.reference('ageInfo/runningAverage')
strServerMessage = ref.get()
previousMessage = ""

while True:
	strServermessage = ref.get()
	if(strServerMessage != previousMessage):
		strServerMessage = ref.get()
		subprocess.run(["./rgb_lcd_demo", strServerMessage])
		previousMessage = strServerMessage
