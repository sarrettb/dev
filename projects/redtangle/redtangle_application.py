from redtangle_local import RedTangleLocal
from redtangle_client import RedTangleClient
from time import sleep
import pyautogui 
import webbrowser
import os
import sys

rules_result = pyautogui.confirm(title='Redtangle',
                           text='Welcome to Redtangle! Would you like to view the game controls and rules?',
                           buttons=['Yes', 'No'])
if rules_result == 'Yes':
    _, file_type = os.path.splitext(sys.argv[0])
    rules_path = os.path.join(os.path.abspath(os.path.dirname(sys.argv[0])), 'resources/redtangle-directions.pdf' if file_type == '.py' else 'redtangle-directions.pdf')
    webbrowser.open(rules_path)
    sleep(3)

remote_result = pyautogui.confirm(title='Redtangle',
                           text='Choose Game Mode',
                           buttons=['Local', 'Remote'])

match remote_result:
    case 'Local':
        RedTangleLocal()
    case 'Remote':
        RedTangleClient(host='192.168.1.93')
    case None:
        pass