import os
os.system("pip install -r requirements.txt")
os.system("pyinstaller --onefile src/sys-info.py")
